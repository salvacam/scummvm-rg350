/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#include "sci/engine/features.h"
#include "sci/engine/hoyle5poker.h"
#include "sci/engine/kernel.h"
#include "sci/engine/script.h"
#include "sci/engine/selector.h"
#include "sci/engine/vm.h"

namespace Sci {

#ifdef ENABLE_SCI32

// The logic for the poker game in Hoyle Classic Games (Hoyle 5) is hardcoded
// in PENGIN16.DLL, which is then loaded and invoked via the kWinDLL kernel call.
// Note that the first player is the left one.

enum Hoyle5PokerSuits {
	kSuitSpades = 0,
	kSuitClubs = 1,
	kSuitDiamonds = 2,
	kSuitHearts = 3
};

enum Hoyle5PokerData {
	kTotalChips = 1,
	kCurrentPot = 2,
	kCurrentBet = 3,
	kChipsPlayer1 = 4,
	kChipsPlayer2 = 5,
	kChipsPlayer3 = 6,
	kChipsPlayer4 = 7,
	kStatusPlayer1 = 8,
	kStatusPlayer2 = 9,
	kStatusPlayer3 = 10,
	kStatusPlayer4 = 11,
	// 12 - 16 seem to be unused?
	kCurrentPlayer = 17,
	kCurrentStage = 18,	// Stage 1: Card changes, 2: Betting
	kCard0 = 19,
	kSuit0 = 20,
	kCard1 = 21,
	kSuit1 = 22,
	kCard2 = 23,
	kSuit2 = 24,
	kCard3 = 25,
	kSuit3 = 26,
	kCard4 = 27,
	kSuit4 = 28,
	// 19 - 28: current player's cards (number + suit)
	// 29 - 38: next clockwise player's cards (number + suit)
	// 39 - 48: next clockwise player's cards (number + suit)
	// 49 - 58: next clockwise player's cards (number + suit)
	// 59 - 60 seem to be unused?
	// ---- Return values -----------------------------------
	kWhatAmIResult = 61,  // bitmask, 0 - 128, checked by PokerHand::whatAmI. Determines what kind of card each player has
	kWinningPlayers = 62, // bitmask, winning players (0000 - 1111 binary), checked by localproc_3020
	kDiscardCard0 = 63,	  // flag, checked by PokerHand::think
	kDiscardCard1 = 64,	  // flag, checked by PokerHand::think
	kDiscardCard2 = 65,	  // flag, checked by PokerHand::think
	kDiscardCard3 = 66,	  // flag, checked by PokerHand::think
	kDiscardCard4 = 67	  // flag, checked by PokerHand::think
	// 77 seems to be a bit array?
};

#if 0
Common::String getCardDescription(int16 card, int16 suit) {
	Common::String result;

	if (card >= 2 && card <= 10)
		result += Common::String::format("%d", card);
	else if (card == 11)
		result = "Jack";
	else if (card == 12)
		result = "Queen";
	else if (card == 13)
		result = "King";
	else if (card == 14)
		result = "Ace";
	else
		result = "Unknown";

	switch (suit) {
	case kSuitSpades:
		return result + " of spades";
	case kSuitClubs:
		return result + " of clubs";
	case kSuitDiamonds:
		return result + " of diamonds";
	case kSuitHearts:
		return result + " of hearts";
	default:
		return result + " of unknown";
	}
}

void printPlayerCards(int player, SciArray *data) {
	debug("Player %d cards:", player);
	for (int i = 19 + player * 10; i < 29 + player * 10; i += 2) {
		if (data->getAsInt16(i) > 0)
			debug("- %s", getCardDescription(data->getAsInt16(i), data->getAsInt16(i + 1)).c_str());
	}
}
#endif

int getCardValue(int card) {
	return card == 1 ? 14 : card;	// aces are the highest valued cards
}

int getCardTotal(SciArray *data, int player) {
	int result = 0;

	int cards[5] = {
		getCardValue(data->getAsInt16(kCard0 + 10 * player)),
		getCardValue(data->getAsInt16(kCard1 + 10 * player)),
		getCardValue(data->getAsInt16(kCard2 + 10 * player)),
		getCardValue(data->getAsInt16(kCard3 + 10 * player)),
		getCardValue(data->getAsInt16(kCard4 + 10 * player)),
	};

	Common::sort(cards, cards + 5, Common::Less<int>());

	int sameRank = 0;
	int sameSuit = 0;
	int orderedCards = 0;

	for (int i = 0; i < 4; i++) {
		if (cards[i] == cards[i + 1]) {
			if (sameRank == 0) {
				result += cards[i] + cards[i + 1];
				sameRank += 2;
			} else {
				result += cards[i + 1];
				sameRank++;
			}
		}
		if (cards[i] == cards[i + 1] - 1)
			orderedCards == 0 ? orderedCards += 2 : orderedCards++;
	}

	bool isFullHouse =
		(cards[0] == cards[1] && cards[1] == cards[2] && cards[3] == cards[4]) ||
		(cards[0] == cards[1] && cards[2] == cards[3] && cards[3] == cards[4]);

	if (isFullHouse || sameSuit == 5 || orderedCards == 5) {
		result = 0;

		for (int i = 0; i < 5; i++)
			result += cards[i];
	}

	return result;
}

// Checks a player's hand, and returns its type using a bitmask
int checkHand(SciArray *data, int player = 0) {
	int cards[5] = {
		data->getAsInt16(kCard0 + 10 * player),
		data->getAsInt16(kCard1 + 10 * player),
		data->getAsInt16(kCard2 + 10 * player),
		data->getAsInt16(kCard3 + 10 * player),
		data->getAsInt16(kCard4 + 10 * player),
	};

	int suits[5] = {
		data->getAsInt16(kSuit0 + 10 * player),
		data->getAsInt16(kSuit1 + 10 * player),
		data->getAsInt16(kSuit2 + 10 * player),
		data->getAsInt16(kSuit3 + 10 * player),
		data->getAsInt16(kSuit4 + 10 * player),
	};

	Common::sort(cards, cards + 5, Common::Less<int>());

	int lastCard = -1;
	int pairs = 0;
	int sameRank = 0;
	int sameSuit = 0;
	int orderedCards = 0;

	for (int i = 0; i < 4; i++) {
		if (cards[i] == cards[i + 1] && cards[i] != lastCard)
			pairs++;
		if (cards[i] == cards[i + 1])
			sameRank == 0 ? sameRank += 2 : sameRank++;
		if (suits[i] == suits[i + 1])
			sameSuit == 0 ? sameSuit += 2 : sameSuit++;
		if (cards[i] == cards[i + 1] - 1)
			orderedCards == 0 ? orderedCards += 2 : orderedCards++;

		lastCard = cards[i];
	}

	bool isFullHouse =
		(cards[0] == cards[1] && cards[1] == cards[2] && cards[3] == cards[4]) ||
		(cards[0] == cards[1] && cards[2] == cards[3] && cards[3] == cards[4]);

	if (pairs == 1 && sameRank == 2)
		return 1 << 0;	// 1, one pair
	else if (pairs == 2 && !isFullHouse)
		return 1 << 1;	// 2, two pairs
	else if (sameRank == 3 && !isFullHouse)
		return 1 << 2;	// 4, three of a kind
	else if (orderedCards == 5 && sameSuit < 5)
		return 1 << 3;	// 8, straight
	else if (orderedCards < 5 && sameSuit == 5)
		return 1 << 4;	// 16, flush
	else if (isFullHouse)
		return 1 << 5;	// 32, full house
	else if (sameRank == 4)
		return 1 << 6;	// 64, four of a kind
	else if (orderedCards == 5 && sameSuit == 5)
		return 1 << 7;	// straight flush
	else if (sameRank == 5)
		return 1 << 8;	// 256, five of a kind

	return 0;	// high card
}

struct Hand {
	int player;
	int handTotal;

	Hand(int p, int h) : player(p), handTotal(h) {}
};

struct WinningHand : public Common::BinaryFunction<Hand, Hand, bool> {
	bool operator()(const Hand &x, const Hand &y) const { return x.handTotal > y.handTotal; }
};

int getWinner(SciArray *data) {
	Hand playerHands[4] = {
		Hand(0, checkHand(data, 0)),
		Hand(1, checkHand(data, 1)),
		Hand(2, checkHand(data, 2)),
		Hand(3, checkHand(data, 3))
	};

	Common::sort(playerHands, playerHands + 4, WinningHand());

	if (playerHands[0].handTotal > playerHands[1].handTotal)
		return playerHands[0].player;
	else
		return getCardTotal(data, 0) > getCardTotal(data, 1) ? playerHands[0].player : playerHands[1].player;
}

reg_t hoyle5PokerEngine(SciArray *data) {
#if 0
	debug("Player %d's turn", data->getAsInt16(kCurrentPlayer));

	debug("Pot: %d, bet: %d", data->getAsInt16(kCurrentPot), data->getAsInt16(kCurrentBet));

	debug("Chips: %d %d %d %d - %d in total",
		data->getAsInt16(kChipsPlayer1),
		data->getAsInt16(kChipsPlayer2),
		data->getAsInt16(kChipsPlayer3),
		data->getAsInt16(kChipsPlayer4),
		data->getAsInt16(kTotalChips)
	);

	debug("Player status: %d %d %d %d",
		data->getAsInt16(kStatusPlayer1),
		data->getAsInt16(kStatusPlayer2),
		data->getAsInt16(kStatusPlayer3),
		data->getAsInt16(kStatusPlayer4)
	);

	for (int i = 0; i < 4; i++)
		printPlayerCards(i, data);

	for (int i = 0; i < data->size(); i++) {
		if (i >= kChipsPlayer1 && i <= kChipsPlayer4)
			continue;
		if (i >= 8 && i <= 11)
			continue;
		if (i >= 19 && i <= 58)
			continue;

		if (data->getAsInt16(i) != 0)
			debug("%d: %d", i, data->getAsInt16(i));
	}
#endif

	data->setFromInt16(kWhatAmIResult, checkHand(data));
	data->setFromInt16(kWinningPlayers, 1 << getWinner(data));

	// Dummy logic for card discard
	Common::RandomSource &rng = g_sci->getRNG();
	data->setFromInt16(kDiscardCard0,  (int)rng.getRandomBit());
	data->setFromInt16(kDiscardCard1,  (int)rng.getRandomBit());
	data->setFromInt16(kDiscardCard2,  (int)rng.getRandomBit());
	data->setFromInt16(kDiscardCard3,  (int)rng.getRandomBit());
	data->setFromInt16(kDiscardCard4,  (int)rng.getRandomBit());

	warning("The Poker game logic has not been implemented yet");
	return TRUE_REG;
}
#endif

}
