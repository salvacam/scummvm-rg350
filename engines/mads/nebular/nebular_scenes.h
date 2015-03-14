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

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#ifndef MADS_NEBULAR_SCENES_H
#define MADS_NEBULAR_SCENES_H

#include "common/scummsys.h"
#include "mads/game.h"
#include "mads/scene.h"
#include "mads/nebular/game_nebular.h"
#include "mads/nebular/globals_nebular.h"


namespace MADS {

namespace Nebular {

enum {
	SEX_MALE = 0, SEX_UNKNOWN = 1, SEX_FEMALE = 2
};

enum Verb {
	VERB_ACTIVATE       = 0x00E,
	VERB_ATTACH         = 0x019,
	VERB_BREAK          = 0x032,
	VERB_BREATHE_AIR    = 0x033,
	VERB_CAST           = 0x03D,
	VERB_CLIMB_DOWN     = 0x04E,
	VERB_CLIMB_THROUGH  = 0x04F,
	VERB_CLIMB_UP       = 0x050,
	VERB_CUT            = 0x061,
	VERB_DAMPEN         = 0x064,
	VERB_DISASSEMBLE    = 0x06C,
	VERB_DIVE_INTO      = 0x06D,
	VERB_DRINK          = 0x072,
	VERB_EAT            = 0x075,
	VERB_EJECT          = 0x076,
	VERB_EMPTY          = 0x077,
	VERB_EXAMINE        = 0x07D,
	VERB_FILL           = 0x085,
	VERB_FONDLE         = 0x08C,
	VERB_HOSE_DOWN      = 0x0A6,
	VERB_IGNITE         = 0x0B4,
	VERB_INFLATE        = 0x0B5,
	VERB_INSERT         = 0x0B6,
	VERB_INSPECT        = 0x0B7,
	VERB_GNAW_ON        = 0x098,
	VERB_GORGE_ON       = 0x099,
	VERB_HURL           = 0x0A9,
	VERB_LICK           = 0x0CB,
	VERB_LOOK_AT        = 0x0D1,
	VERB_LOOK_IN        = 0x0D2,
	VERB_LOOK_THROUGH   = 0x0D3,
	VERB_PEER_THROUGH   = 0x103,
	VERB_PLAY           = 0x112,
	VERB_PRESS          = 0x11A,
	VERB_PRY            = 0x11C,
	VERB_READ           = 0x11F,
	VERB_SET            = 0x132,
	VERB_SHAKE_HANDS    = 0x133,
	VERB_SHARPEN        = 0x134,
	VERB_SHOOT          = 0x13A,
	VERB_SIT_IN         = 0x13F,
	VERB_SMELL          = 0x147,
	VERB_SNIFF          = 0x149,
	VERB_STARE_AT       = 0x155,
	VERB_SWIM_ACROSS    = 0x159,
	VERB_SWIM_INTO      = 0x15A,
	VERB_SWIM_THROUGH   = 0x15B,
	VERB_SWIM_TO        = 0x15C,
	VERB_SWIM_TOWARDS   = 0x15D,
	VERB_SWIM_UNDER     = 0x15E,
	VERB_TIE            = 0x170,
	VERB_UNLOCK         = 0x17B,
	VERB_WALK_ACROSS    = 0x187,
	VERB_WALK_INSIDE    = 0x188,
	VERB_WALK_OUTSIDE   = 0x18A,
	VERB_WALK_THROUGH   = 0x18B,
	VERB_WALK_TOWARDS   = 0x18C,
	VERB_WEAR           = 0x191,
	VERB_WALK_DOWN      = 0x1AD,
	VERB_LEAVE          = 0x1CD,
	VERB_EXIT_FROM      = 0x1CE,
	VERB_USE            = 0x20C,
	VERB_GAZE_INTO      = 0x212,
	VERB_SIT_AT         = 0x21F,
	VERB_WALK_UP        = 0x227,
	VERB_WALK_INTO      = 0x242,
	VERB_EXIT           = 0x298,
	VERB_WALK_BEHIND    = 0x2A2,
	VERB_WALK_ONTO      = 0x2B5,
	VERB_RETURN_TO      = 0x2D5,
	VERB_CLIMB_INTO     = 0x2F7,
	VERB_STEP_INTO      = 0x2F9,
	VERB_CRAWL_TO       = 0x2FB,
	VERB_CRAWL_DOWN     = 0x301,
	VERB_SIT_ON         = 0x30B,
	VERB_WALK_ALONG     = 0x312,
	VERB_GET_INSIDE     = 0x325,
	VERB_WALK           = 0x32F,
	VERB_REFLECT        = 0x365,
	VERB_GET_INTO       = 0x36A,
	VERB_LOOK_OUT		= 0x397,
	VERB_APPLY          = 0x3A6,
	VERB_STEER_TOWARDS  = 0x3B1,
	VERB_NIBBLE_ON      = 0x3B7,
	VERB_ENTER          = 0x3B8,
	VERB_PUT_DOWN       = 0x46F,
	VERB_INSTALL        = 0x474,
	VERB_REMOVE         = 0x476,
	VERB_DEFACE         = 0x489,
	VERB_MASSAGE        = 0x4A3,
	VERB_MANGLE         = 0x4A4,
	VERB_RUB            = 0x4A5,
	VERB_JUGGLE         = 0x4A6,
	VERB_SMASH          = 0x4A7,
	VERB_GUZZLE         = 0x4A8,
	VERB_FOLD           = 0x4AB,
	VERB_SPINDLE        = 0x4AC,
	VERB_MUTILATE       = 0x4AD
};

enum Noun {
	//NOUN_GAME = 0x1,
	//NOUN_QSAVE = 0x2,
	//NOUN_LOOK = 0x3,
	//NOUN_TAKE = 0x4,
	//NOUN_PUSH = 0x5,
	//NOUN_OPEN = 0x6,
	//NOUN_PUT = 0x7,
	//NOUN_TALK_TO = 0x8,
	//NOUN_GIVE = 0x9,
	//NOUN_PULL = 0xA,
	//NOUN_CLOSE = 0xB,
	//NOUN_THROW = 0xC,
	//NOUN_WALK_TO = 0xD,
	//NOUN_ACTIVATE = 0xE,
	//NOUN_ADMIRE = 0xF,
	NOUN_ADSM = 0x10,
	NOUN_AIR_VENT = 0x11,
	NOUN_ALOE_PLANT = 0x12,
	NOUN_ANEMONE = 0x13,
	NOUN_ANOMOMETER = 0x14,
	NOUN_AREA_AROUND_HUT = 0x15,
	NOUN_AREA_TO_SOUTH = 0x16,
	NOUN_AREA_TO_WEST = 0x17,
	NOUN_AROMATIC_MEAT = 0x18,
	//NOUN_ATTACH = 0x19,
	NOUN_AUDIO_TAPE = 0x1A,
	NOUN_AUXILIARY_POWER = 0x1B,
	NOUN_BADMITTON_BRAT = 0x1C,
	NOUN_BAG = 0x1D,
	NOUN_BAMBOO_TREE = 0x1E,
	NOUN_BATS = 0x1F,
	NOUN_BAWLEMER_ORIOLE_HUN = 0x20,
	NOUN_BEAR_RUG = 0x21,
	NOUN_BEASTLY_TROPHY = 0x22,
	NOUN_BIG_LEAVES = 0x23,
	NOUN_BIG_PIPES = 0x24,
	NOUN_BIG_SKY = 0x25,
	NOUN_BIG_STONE = 0x26,
	NOUN_BINOCULARS = 0x27,
	NOUN_BIRDIES = 0x28,
	NOUN_BLOWGUN = 0x29,
	NOUN_BOMB = 0x2A,
	NOUN_BOMBS = 0x2B,
	NOUN_BONE = 0x2C,
	NOUN_BONES = 0x2D,
	NOUN_BOTTLE = 0x2E,
	NOUN_BOULDER = 0x2F,
	NOUN_BOULDERS = 0x30,
	NOUN_BRA = 0x31,
	//NOUN_BREAK = 0x32,
	//NOUN_BREATHE_AIR = 0x33,
	NOUN_BULKHEAD = 0x34,
	NOUN_BURGER = 0x35,
	NOUN_BURN = 0x36,
	NOUN_BURNT_OUT_WARP_COIL = 0x37,
	NOUN_BUSH_LIKE_FORMATION = 0x38,
	NOUN_BUSHES = 0x39,
	NOUN_BUSHY_FERN = 0x3A,
	NOUN_CACTUS = 0x3B,
	NOUN_CARD = 0x3C,
	//NOUN_CAST = 0x3D,
	NOUN_CAULDRON = 0x3E,
	NOUN_CAVE = 0x3F,
	NOUN_CAVE_CEILING = 0x40,
	NOUN_CAVE_ENTRANCE = 0x41,
	NOUN_CAVE_EXIT = 0x42,
	NOUN_CAVE_FLOOR = 0x43,
	NOUN_CAVE_TO_EAST = 0x44,
	NOUN_CAVE_WALL = 0x45,
	NOUN_CEILING = 0x46,
	NOUN_CHAIR = 0x47,
	NOUN_CHARGE_CASES = 0x48,
	NOUN_CHICKEN = 0x49,
	NOUN_CHICKEN_BOMB = 0x4A,
	NOUN_CLEARING_TO_EAST = 0x4B,
	NOUN_CLEARING_TO_SOUTH = 0x4C,
	NOUN_CLIFF_FACE = 0x4D,
	//NOUN_CLIMB_DOWN = 0x4E,
	//NOUN_CLIMB_THROUGH = 0x4F,
	//NOUN_CLIMB_UP = 0x50,
	NOUN_CLOCK = 0x51,
	NOUN_CLOSET = 0x52,
	NOUN_CLOTHESLINE = 0x53,
	NOUN_CLUMP_OF_TREES = 0x54,
	NOUN_COAL = 0x55,
	NOUN_COCOANUT = 0x56,
	NOUN_COMPACT_CASE = 0x57,
	NOUN_COMPUTER_GAME = 0x58,
	NOUN_CONTROL_PANEL = 0x59,
	NOUN_CORAL = 0x5A,
	NOUN_CRAB = 0x5B,
	NOUN_CREDIT_CHIP = 0x5C,
	NOUN_CUMULOUS_CLOUD = 0x5D,
	NOUN_CURIOUS_WEED_PATCH = 0x5E,
	NOUN_CURTAIN = 0x5F,
	NOUN_CURTAINS = 0x60,
	//NOUN_CUT = 0x61,
	NOUN_DAMAGE_CONTROL = 0x62,
	NOUN_DAMAGE_CONTROL_PANEL = 0x63,
	//NOUN_DAMPEN = 0x64,
	NOUN_DEAD_FISH = 0x65,
	NOUN_DEAD_PURPLE_MONSTER = 0x66,
	NOUN_DECLIVITOUS_CHASM = 0x67,
	NOUN_DEEP_DARK_FOREST = 0x68,
	NOUN_DENSE_FOREST = 0x69,
	NOUN_DETONATORS = 0x6A,
	NOUN_DINO_MITE = 0x6B,
	//NOUN_DISASSEMBLE = 0x6C,
	//NOUN_DIVE_INTO = 0x6D,
	NOUN_DOOR = 0x6E,
	NOUN_DOOR_KEY = 0x6F,
	NOUN_DOORWAY = 0x70,
	NOUN_DRAWER = 0x71,
	//NOUN_DRINK = 0x72,
	NOUN_DURAFAIL_CELLS = 0x73,
	NOUN_EASTERN_CLIFF_FACE = 0x74,
	//NOUN_EAT = 0x75,
	//NOUN_EJECT = 0x76,
	//NOUN_EMPTY = 0x77,
	NOUN_ENGINEERING_CONTROLS = 0x78,
	NOUN_ENGINEERING_SECTION = 0x79,
	NOUN_ENTER_KEY = 0x7A,
	NOUN_ESCAPE_HATCH = 0x7B,
	NOUN_ESTROTOXIN = 0x7C,
	//NOUN_EXAMINE = 0x7D,
	NOUN_EXPERIMENT_CAGE = 0x7E,
	NOUN_EXTINGUISH = 0x7F,
	NOUN_FACE_ID = 0x80,
	NOUN_FERN = 0x81,
	NOUN_FIELD_TO_NORTH = 0x82,
	NOUN_FIELD_TO_SOUTH = 0x83,
	NOUN_FIELD_TO_WEST = 0x84,
	//NOUN_FILL = 0x85,
	NOUN_FIRE_PIT = 0x86,
	NOUN_FISHING_LINE = 0x87,
	NOUN_FISHING_ROD = 0x88,
	NOUN_FLOOR = 0x89,
	NOUN_FLOOR_OF_HUT = 0x8A,
	NOUN_FLOOR_TILE = 0x8B,
	//NOUN_FONDLE = 0x8C,
	NOUN_FOREST_TO_EAST = 0x8D,
	NOUN_FRONT_WINDOW = 0x8E,
	NOUN_FUNGOIDS = 0x8F,
	NOUN_FURNACE = 0x90,
	NOUN_FUZZY_DICE = 0x91,
	//NOUN_GAZE = 0x92,
	//NOUN_GAZE_AT = 0x93,
	//NOUN_GAZE_IN = 0x94,
	//NOUN_GLANCE_AT = 0x95,
	NOUN_GLOVE = 0x96,
	NOUN_GNARLY_SHRUB = 0x97,
	//NOUN_GNAW_ON = 0x98,
	//NOUN_GORGE_ON = 0x99,
	NOUN_GRAIN_ALCHOHOL = 0x9A,
	NOUN_GRASSLAND_TO_EAST = 0x9B,
	NOUN_GRASSLAND_TO_SOUTH = 0x9C,
	NOUN_GRASSY_AREA = 0x9D,
	NOUN_GRASSY_AREA_TO_NORTH = 0x9E,
	NOUN_GRASSY_KNOLL = 0x9F,
	//NOUN_GRIND = 0xA0,
	NOUN_GROOVILACTIC_TREE = 0xA1,
	NOUN_GUARDS_ARM = 0xA2,
	NOUN_HATCHWAY = 0xA3,
	//NOUN_HOOK_UP = 0xA4,
	NOUN_HORIZON = 0xA5,
	//NOUN_HOSE_DOWN = 0xA6,
	NOUN_HOTPANTS = 0xA7,
	NOUN_HULL = 0xA8,
	//NOUN_HURL = 0xA9,
	NOUN_HUT = 0xAA,
	NOUN_HUT_AREA = 0xAB,
	NOUN_HUT_TO_EAST = 0xAC,
	NOUN_HUT_TO_SOUTH = 0xAD,
	NOUN_HUT_TO_THE_SOUTH = 0xAE,
	NOUN_HUT_TO_WEST = 0xAF,
	NOUN_HUTS_TO_NORTH = 0xB0,
	NOUN_HYDROSPANNER = 0xB1,
	NOUN_HYPERDRIVE_JUMP_UNIT = 0xB2,
	NOUN_ID_CARD = 0xB3,
	//NOUN_IGNITE = 0xB4,
	//NOUN_INFLATE = 0xB5,
	//NOUN_INSERT = 0xB6,
	//NOUN_INSPECT = 0xB7,
	NOUN_JUNGLE = 0xB8,
	NOUN_JUNGLE_TO_EAST = 0xB9,
	NOUN_JUNGLE_TO_WEST = 0xBA,
	NOUN_KEY_1 = 0xBB,
	NOUN_KEY_2 = 0xBC,
	NOUN_KEY_3 = 0xBD,
	NOUN_KEY_4 = 0xBE,
	NOUN_KEY_5 = 0xBF,
	NOUN_KEY_6 = 0xC0,
	NOUN_KEY_7 = 0xC1,
	NOUN_KEY_8 = 0xC2,
	NOUN_KEY_9 = 0xC3,
	NOUN_KEYPAD = 0xC4,
	NOUN_KNEELING_WOMAN = 0xC5,
	NOUN_KNIFE = 0xC6,
	NOUN_LADDER = 0xC7,
	NOUN_LARGE_STALAGMITE = 0xC8,
	//NOUN_LEER_AT = 0xC9,
	NOUN_LIBRARY_COMPUTER = 0xCA,
	//NOUN_LICK = 0xCB,
	NOUN_LIFE_SUPPORT_SECTION = 0xCC,
	NOUN_LIGHT = 0xCD,
	//NOUN_LOAD = 0xCE,
	//NOUN_LOCK = 0xCF,
	NOUN_LOG = 0xD0,
	//NOUN_LOOK_AT = 0xD1,
	//NOUN_LOOK_IN = 0xD2,
	//NOUN_LOOK_THROUGH = 0xD3,
	NOUN_LOUNGE_AREA = 0xD4,
	NOUN_LOVE_ALTAR = 0xD5,
	NOUN_LOWLANDS = 0xD6,
	NOUN_MACHINE = 0xD7,
	NOUN_MAGNET = 0xD8,
	NOUN_MAIN_AIRLOCK = 0xD9,
	NOUN_MANTA_RAY = 0xDA,
	NOUN_MARSHY_WETLANDS = 0xDB,
	NOUN_MATCH = 0xDC,
	NOUN_MEDICAL_WASTE = 0xDD,
	NOUN_MEDICINE_CABINET = 0xDE,
	NOUN_MEN_WHO_CAME_BEFORE = 0xDF,
	NOUN_MINE = 0xE0,
	NOUN_MIRROR = 0xE1,
	NOUN_MONITOR = 0xE2,
	NOUN_MONKEY = 0xE3,
	NOUN_MONKEY_LIVER_JUICE = 0xE4,
	NOUN_MONSTER_SLUDGE = 0xE5,
	NOUN_MOUNTAIN = 0xE6,
	NOUN_MOUNTAIN_RANGE = 0xE7,
	NOUN_MOUNTAINS = 0xE8,
	NOUN_MTAM = 0xE9,
	NOUN_MUSHROOMS = 0xEA,
	NOUN_NAVIGATION_CONTROLS = 0xEB,
	NOUN_NORTH_PATH = 0xEC,
	NOUN_NORTHERN_EXPOSURE = 0xED,
	NOUN_NORTHERN_SEA_CLIFF = 0xEE,
	NOUN_OBSTACLE = 0xEF,
	NOUN_OCEAN_FLOOR = 0xF0,
	NOUN_ODD_ROCK_FORMATION = 0xF1,
	NOUN_OOGLY_BOOGLY_JUICE = 0xF2,
	NOUN_OPEN_AREA_TO_EAST = 0xF3,
	NOUN_OPEN_AREA_TO_NORTH = 0xF4,
	NOUN_OPEN_AREA_TO_SOUTH = 0xF5,
	NOUN_OPEN_AREA_TO_WEST = 0xF6,
	NOUN_OPEN_FIELD = 0xF7,
	NOUN_OUTER_HULL = 0xF8,
	NOUN_OUTSIDE = 0xF9,
	NOUN_OVEN = 0xFA,
	NOUN_OVERHANG_TO_EAST = 0xFB,
	NOUN_OVERHANG_TO_WEST = 0xFC,
	NOUN_OVERHEAD_LAMP = 0xFD,
	NOUN_PAD_OF_PAPER = 0xFE,
	NOUN_PADLOCK_KEY = 0xFF,
	NOUN_PALM_TREE = 0x100,
	NOUN_PASSAGE_WAY_TO_SOUTH = 0x101,
	NOUN_PASSION_PUSS = 0x102,
	//NOUN_PEER_THROUGH = 0x103,
	NOUN_PENCIL = 0x104,
	NOUN_PENDULOUS_CRAG = 0x105,
	NOUN_PENLIGHT = 0x106,
	NOUN_PHONE_CELLS = 0x107,
	NOUN_PHONE_HANDSET = 0x108,
	NOUN_PILE_OF_ROCKS = 0x109,
	NOUN_PILLOW = 0x10A,
	NOUN_PILOTS_CHAIR = 0x10B,
	NOUN_PIPE = 0x10C,
	NOUN_PIRANHA = 0x10D,
	NOUN_PLANT = 0x10E,
	NOUN_PLANT_STALK = 0x10F,
	NOUN_PLANTS = 0x110,
	NOUN_PLASTIC_JESUS = 0x111,
	//NOUN_PLAY = 0x112,
	NOUN_PLUNGER = 0x113,
	NOUN_POISON_DARTS = 0x114,
	NOUN_POLYCEMENT = 0x115,
	NOUN_POOL = 0x116,
	NOUN_POSTER = 0x117,
	NOUN_POWER_STATUS_PANEL = 0x118,
	NOUN_PRECIPICE = 0x119,
	//NOUN_PRESS = 0x11A,
	NOUN_PRESSURE_GAUGE = 0x11B,
	//NOUN_PRY = 0x11C,
	NOUN_RAGING_RIVER = 0x11D,
	NOUN_RAMOLYAN_RUGBY_RATS = 0x11E,
	//NOUN_READ = 0x11F,
	NOUN_REARVIEW_MIRROR = 0x120,
	NOUN_REBREATHER = 0x121,
	NOUN_REFRIGERATOR = 0x122,
	NOUN_REMOTE = 0x123,
	NOUN_REPAIR_LIST = 0x124,
	NOUN_RIVER = 0x125,
	NOUN_RIVER_TO_WEST = 0x126,
	NOUN_ROBO_KITCHEN = 0x127,
	NOUN_ROCK = 0x128,
	NOUN_ROCKS = 0x129,
	NOUN_ROCKY_AREA = 0x12A,
	NOUN_ROLLING_HILL = 0x12B,
	NOUN_SCALPEL = 0x12C,
	NOUN_SCENIC_MOUNTAINS = 0x12D,
	NOUN_SEA_CLIFF = 0x12E,
	NOUN_SEAWEED = 0x12F,
	NOUN_SEAWEED_BANK = 0x130,
	NOUN_SECURITY_CARD = 0x131,
	//NOUN_SET = 0x132,
	//NOUN_SHAKE_HANDS = 0x133,
	//NOUN_SHARPEN = 0x134,
	NOUN_SHIELD_ACCESS_PANEL = 0x135,
	NOUN_SHIELD_GENERATOR = 0x136,
	NOUN_SHIELD_MODULATOR = 0x137,
	NOUN_SHIELD_STATUS_PANEL = 0x138,
	NOUN_SHIP = 0x139,
	//NOUN_SHOOT = 0x13A,
	NOUN_SHOVEL = 0x13B,
	//NOUN_SHRED = 0x13C,
	NOUN_SHRUNKEN_HEADS = 0x13D,
	NOUN_SINGED_MEAT = 0x13E,
	//NOUN_SIT_IN = 0x13F,
	NOUN_SKULL = 0x140,
	NOUN_SKULL_AND_CROSSBONES = 0x141,
	NOUN_SKY = 0x142,
	//NOUN_SLEEP_ON = 0x143,
	NOUN_SLITHERING_SNAKE = 0x144,
	NOUN_SLUG_SECRETION = 0x145,
	NOUN_SMALL_HOLE = 0x146,
	//NOUN_SMELL = 0x147,
	NOUN_SNAKE = 0x148,
	//NOUN_SNIFF = 0x149,
	//NOUN_SOAK = 0x14A,
	NOUN_SPECIAL_KEY_1 = 0x14B,
	NOUN_SPECIAL_KEY_2 = 0x14C,
	NOUN_SPIDER = 0x14D,
	NOUN_SPILT_MILK = 0x14E,
	NOUN_SPIT_FIRE = 0x14F,
	//NOUN_SPRAY = 0x150,
	//NOUN_STAB = 0x151,
	NOUN_STAIRS = 0x152,
	NOUN_STALAGMITES = 0x153,
	//NOUN_STAND_INSIDE = 0x154,
	//NOUN_STARE_AT = 0x155,
	NOUN_STEPS = 0x156,
	NOUN_STUFFED_FISH = 0x157,
	NOUN_SURFACE = 0x158,
	//NOUN_SWIM_ACROSS = 0x159,
	//NOUN_SWIM_INTO = 0x15A,
	//NOUN_SWIM_THROUGH = 0x15B,
	//NOUN_SWIM_TO = 0x15C,
	//NOUN_SWIM_TOWARDS = 0x15D,
	//NOUN_SWIM_UNDER = 0x15E,
	NOUN_SWOOPING_CREATURE = 0x15F,
	NOUN_TABLE = 0x160,
	//NOUN_TAKE_LIVER = 0x161,
	//NOUN_TAKE_OFF = 0x162,
	//NOUN_TAKE_PAGE = 0x163,
	NOUN_TALL_GRASS = 0x164,
	NOUN_TAPE_PLAYER = 0x165,
	NOUN_TARGET_COMPUTER = 0x166,
	NOUN_TARGET_MODULE = 0x167,
	NOUN_TARGETTING_COMPUTER = 0x168,
	NOUN_TASMANIAN_DEVIL = 0x169,
	NOUN_TASTY_TURKEY = 0x16A,
	NOUN_TELEPORT_DEVICE = 0x16B,
	NOUN_TELEPORTER = 0x16C,
	NOUN_THATCHED_ROOF = 0x16D,
	NOUN_THORNS = 0x16E,
	NOUN_THORNY_BUSH = 0x16F,
	//NOUN_TIE = 0x170,
	NOUN_TIMEBOMB = 0x171,
	NOUN_TIMER = 0x172,
	NOUN_TIMER_MODULE = 0x173,
	NOUN_TREE = 0x174,
	NOUN_TREES = 0x175,
	NOUN_TRODDEN_PATH = 0x176,
	NOUN_TUBE = 0x177,
	NOUN_TUNNEL = 0x178,
	NOUN_TWINKIE_BUSH = 0x179,
	NOUN_TWINKIFRUIT = 0x17A,
	//NOUN_UNLOCK = 0x17B,
	NOUN_UZI = 0x17C,
	NOUN_VASE = 0x17D,
	NOUN_VIDEO_GAME = 0x17E,
	//NOUN_VIEW = 0x17F,
	NOUN_VIEW_SCREEN = 0x180,
	NOUN_VIEWPORT = 0x181,
	NOUN_VILLAGE_AREA = 0x182,
	NOUN_VILLAGE_TO_WEST = 0x183,
	NOUN_VOLCANO = 0x184,
	NOUN_VULTURE = 0x185,
	NOUN_WAD_OF_CATTLE_PARTS = 0x186,
	//NOUN_WALK_ACROSS = 0x187,
	//NOUN_WALK_INSIDE = 0x188,
	//NOUN_WALK_ON = 0x189,
	//NOUN_WALK_OUTSIDE = 0x18A,
	//NOUN_WALK_THROUGH = 0x18B,
	//NOUN_WALK_TOWARDS = 0x18C,
	NOUN_WALL = 0x18D,
	NOUN_WATCH_TOWER = 0x18E,
	NOUN_WATER = 0x18F,
	NOUN_WEAPONS_DISPLAY = 0x190,
	//NOUN_WEAR = 0x191,
	NOUN_WEATHER_STATION = 0x192,
	NOUN_WEATHER_VANE = 0x193,
	NOUN_WEIGHT_MACHINE = 0x194,
	NOUN_WESTERN_CLIFF_FACE = 0x195,
	NOUN_WHEEL = 0x196,
	NOUN_WINDOW = 0x197,
	NOUN_WITCHDOCTOR_HUT = 0x198,
	NOUN_WORKBENCH = 0x199,
	//NOUN_WRITE_ON = 0x19A,
	NOUN_YELLOW_BIRDY = 0x19B,
	NOUN_GRASS = 0x19C,
	NOUN_BOUNCING_REPTILE = 0x19D,
	NOUN_DEEP_PIT = 0x19E,
	NOUN_LOWLANDS_TO_NORTH = 0x19F,
	NOUN_SMALL_BUSH = 0x1A0,
	NOUN_SMALL_CACTUS = 0x1A1,
	NOUN_ROCKY_AREA_TO_NORTH = 0x1A2,
	NOUN_BAMBOO_LIKE_PLANT = 0x1A3,
	NOUN_MOUNTAINSIDE = 0x1A4,
	NOUN_FIELD = 0x1A5,
	NOUN_GRASSY_FIELD = 0x1A6,
	NOUN_CRAG = 0x1A7,
	NOUN_HUGE_LEGS = 0x1A8,
	NOUN_LEAF_COVERED_PIT = 0x1A9,
	NOUN_PILE_OF_LEAVES = 0x1AA,
	NOUN_OPEN_FIELD_TO_EAST = 0x1AB,
	NOUN_LAWN = 0x1AC,
	//NOUN_WALK_DOWN = 0x1AD,
	NOUN_PATH_TO_WEST = 0x1AE,
	NOUN_HEDGE = 0x1AF,
	NOUN_VILLAGE_PATH = 0x1B0,
	NOUN_PATH_TO_NORTHEAST = 0x1B1,
	NOUN_JUNGLE_PATH = 0x1B2,
	NOUN_THICK_UNDERGROWTH = 0x1B3,
	NOUN_OCEAN = 0x1B4,
	NOUN_OCEAN_IN_DISTANCE = 0x1B5,
	NOUN_STRANGE_DEVICE = 0x1B6,
	NOUN_BUSH = 0x1B7,
	NOUN_ANEMOMETER = 0x1B8,
	NOUN_ISLAND_IN_DISTANCE = 0x1B9,
	NOUN_PATH = 0x1BA,
	NOUN_TROPHY = 0x1BB,
	NOUN_SPECIMEN_JARS = 0x1BC,
	NOUN_BOWL = 0x1BD,
	NOUN_LARGE_BOWL = 0x1BE,
	NOUN_PATH_TO_NORTH = 0x1BF,
	NOUN_HUT_TO_NORTH = 0x1C0,
	NOUN_PATH_TO_EAST = 0x1C1,
	NOUN_CHICKEN_ON_SPIT = 0x1C2,
	NOUN_CAPTIVE_CREATURE = 0x1C3,
	NOUN_TWINKIFRUIT_BUSH = 0x1C4,
	NOUN_STREAM = 0x1C5,
	NOUN_OPPOSITE_SHORE = 0x1C6,
	NOUN_PATH_TO_SOUTH = 0x1C7,
	NOUN_OPPOSITE_BANK = 0x1C8,
	NOUN_BROKEN_LADDER = 0x1C9,
	NOUN_BAG_OF_TWINKIFRUITS = 0x1CA,
	NOUN_BED = 0x1CB,
	NOUN_DISPLAY = 0x1CC,
	//NOUN_LEAVE = 0x1CD,
	//NOUN_EXIT_FROM = 0x1CE,
	NOUN_DEVICE = 0x1CF,
	NOUN_0_KEY = 0x1D0,
	NOUN_1_KEY = 0x1D1,
	NOUN_2_KEY = 0x1D2,
	NOUN_3_KEY = 0x1D3,
	NOUN_4_KEY = 0x1D4,
	NOUN_5_KEY = 0x1D5,
	NOUN_6_KEY = 0x1D6,
	NOUN_7_KEY = 0x1D7,
	NOUN_8_KEY = 0x1D8,
	NOUN_9_KEY = 0x1D9,
	NOUN_FROWN_KEY = 0x1DA,
	NOUN_SMILE_KEY = 0x1DB,
	NOUN_NATIVE_WOMAN = 0x1DC,
	NOUN_YELLOW_BIRD = 0x1DD,
	NOUN_BLEEPER = 0x1DE,
	NOUN_SIZEMOMETER = 0x1DF,
	NOUN_PANEL = 0x1E0,
	NOUN_PRINTER = 0x1E1,
	NOUN_HARD_DRIVE = 0x1E2,
	NOUN_BATHROOM = 0x1E3,
	NOUN_DESK = 0x1E4,
	NOUN_PASSAGEWAY = 0x1E5,
	NOUN_FIRE_HYDRANT = 0x1E6,
	NOUN_FREEZER = 0x1E7,
	NOUN_EQUIDIGITIZER = 0x1E8,
	NOUN_VISION_VIEW = 0x1E9,
	NOUN_TELEDETECTOR = 0x1EA,
	NOUN_POLE = 0x1EB,
	NOUN_TRANSPOSITION_DEVICE = 0x1EC,
	NOUN_STATUESQUE = 0x1ED,
	NOUN_TEMPERATURE_GAUGE = 0x1EE,
	NOUN_CHECK = 0x1EF,
	NOUN_WATCH = 0x1F0,
	NOUN_ELECTRO_SCANNER = 0x1F1,
	NOUN_HALL = 0x1F2,
	NOUN_SCANNER = 0x1F3,
	//NOUN_PLACE_HAND_ON = 0x1F4,
	NOUN_SECURITY_MONITOR = 0x1F5,
	NOUN_DIGITORAMA = 0x1F6,
	NOUN_RAIL_BEAM = 0x1F7,
	NOUN_VAULT = 0x1F8,
	NOUN_HALLWAY = 0x1F9,
	NOUN_PIPES = 0x1FA,
	NOUN_AIR_VENT_GRATE = 0x1FB,
	NOUN_SECURITY_OFFICE = 0x1FC,
	NOUN_SIGNAL = 0x1FD,
	NOUN_BLEEP = 0x1FE,
	NOUN_BLIP = 0x1FF,
	NOUN_LOFT = 0x200,
	NOUN_ELECTRONIC_ANT_FARM = 0x201,
	NOUN_ELECTRIC_WIRING = 0x202,
	NOUN_SECURITY_PANEL = 0x203,
	NOUN_CORRIDOR = 0x204,
	NOUN_CIRCUIT_CONTROLS = 0x205,
	NOUN_AIR_DUCT = 0x206,
	NOUN_CELL_WALL = 0x207,
	NOUN_LIGHTS = 0x208,
	//NOUN_STARE_INTO = 0x209,
	NOUN_CELL_CONTROLS = 0x20A,
	NOUN_COMMODE = 0x20B,
	//NOUN_USE = 0x20C,
	NOUN_BASIN = 0x20D,
	//NOUN_JUMP_INSIDE = 0x20E,
	NOUN_PREVIOUS_CELL = 0x20F,
	NOUN_NEXT_ROOM = 0x210,
	NOUN_ZINK = 0x211,
	//NOUN_GAZE_INTO = 0x212,
	NOUN_THRONE = 0x213,
	NOUN_SACK = 0x214,
	NOUN_LIMB = 0x215,
	NOUN_SINK = 0x216,
	NOUN_JOHNNY_ON_THE_SPOT = 0x217,
	NOUN_DEBRIS = 0x218,
	NOUN_BUNK = 0x219,
	NOUN_NEXT_CELL = 0x21A,
	NOUN_TOILET = 0x21B,
	NOUN_MONITOR_AREA = 0x21C,
	NOUN_SIDEWALL = 0x21D,
	NOUN_COFFEE_MUG = 0x21E,
	//NOUN_SIT_AT = 0x21F,
	NOUN_LIGHTING_FIXTURE = 0x220,
	NOUN_MONITORS = 0x221,
	NOUN_GENDER_CONTROLS = 0x222,
	NOUN_NEURO_ANALYZER = 0x223,
	NOUN_MOLECULAR_RECORDER = 0x224,
	NOUN_MAINTENANCE_PANEL = 0x225,
	NOUN_RAMP = 0x226,
	//NOUN_WALK_UP = 0x227,
	NOUN_SUBSONIC_ATOMIZER = 0x228,
	NOUN_EIGHT_BALL = 0x229,
	NOUN_DNA_INVERTER = 0x22A,
	NOUN_DNA_CONVERTER = 0x22B,
	NOUN_PLATFORM = 0x22C,
	NOUN_GUINEA_PIG_TEST_BOX = 0x22D,
	NOUN_GASEOUS_PROBE_WARPER = 0x22E,
	NOUN_TOOL_CABINET = 0x22F,
	NOUN_SURGICAL_BOXES = 0x230,
	NOUN_FETAL_HEART_MONITOR = 0x231,
	NOUN_XRAY_CABINET = 0x232,
	NOUN_STERILIZATION_SINK = 0x233,
	NOUN_DRIPOLATOR = 0x234,
	NOUN_SHOCK_MACHINE = 0x235,
	NOUN_INTERROGATION_TABLE = 0x236,
	NOUN_LIE_DOWN_ON = 0x237,
	//NOUN_DECIPHER = 0x238,
	NOUN_GUARD = 0x239,
	NOUN_RIP_IN_FLOOR = 0x23A,
	NOUN_TELEPORT_AREA = 0x23B,
	NOUN_BROKEN_BEAM = 0x23C,
	NOUN_ROCK_CHUNK = 0x23D,
	NOUN_BLOODY_CELL_WALL = 0x23E,
	NOUN_WALL_BOARD = 0x23F,
	NOUN_GENDER_SCANNER = 0x240,
	NOUN_BAR = 0x241,
	//NOUN_WALK_INTO = 0x242,
	NOUN_HALLWAY_TO_SOUTH = 0x243,
	NOUN_SIGN = 0x244,
	NOUN_HALLWAY_TO_NORTH = 0x245,
	NOUN_BOTTLES = 0x246,
	NOUN_UPPER_DANCE_FLOOR = 0x247,
	NOUN_DANCE_FLOOR = 0x248,
	NOUN_RAILING = 0x249,
	NOUN_BAR_STOOL = 0x24A,
	NOUN_LADY = 0x24B,
	NOUN_UPPER_LEVEL = 0x24C,
	NOUN_ALCOVE = 0x24D,
	NOUN_DISCO_BALL = 0x24E,
	NOUN_LADIES = 0x24F,
	NOUN_COACH_LAMP = 0x250,
	NOUN_CARD_SLOT = 0x251,
	NOUN_HOOP = 0x252,
	NOUN_CANNONBALLS = 0x253,
	NOUN_WATER_FOUNTAIN = 0x254,
	NOUN_HALLWAY_TO_EAST = 0x255,
	NOUN_HALLWAY_TO_WEST = 0x256,
	NOUN_SUPPORT = 0x257,
	NOUN_BACKBOARD = 0x258,
	NOUN_WIDE_DOOR = 0x259,
	NOUN_SIGN_POST = 0x25A,
	NOUN_FIRE_EXTINGUISHER = 0x25B,
	NOUN_TRASH = 0x25C,
	NOUN_MISSILES = 0x25D,
	NOUN_TANK = 0x25E,
	NOUN_TWO_TON_WEIGHT = 0x25F,
	NOUN_ONE_TON_TOMATO = 0x260,
	NOUN_ANVIL = 0x261,
	NOUN_MINUTEMAN_IV_ICBM = 0x262,
	NOUN_CHEST = 0x263,
	NOUN_ARMOR = 0x264,
	NOUN_CARTON = 0x265,
	NOUN_POWDER = 0x266,
	NOUN_RAFT = 0x267,
	NOUN_WHATZIT = 0x268,
	NOUN_CATAPULT = 0x269,
	NOUN_HAND_GRENADE = 0x26A,
	NOUN_BARRELS = 0x26B,
	NOUN_LOADING_RAMP = 0x26C,
	NOUN_BLIMP = 0x26D,
	NOUN_FLOUR = 0x26E,
	NOUN_FLY_PAPER = 0x26F,
	NOUN_RUG = 0x270,
	NOUN_CARPET = 0x271,
	NOUN_CAN = 0x272,
	NOUN_RUBBER_DUCKIE = 0x273,
	NOUN_GOLF_CLUBS = 0x274,
	NOUN_RAT = 0x275,
	NOUN_BARREL = 0x276,
	NOUN_BUCKET_OF_TAR = 0x277,
	NOUN_SACKS = 0x278,
	NOUN_STORAGE = 0x279,
	NOUN_120V_3_PHASE_400HZ = 0x27A,
	NOUN_LAB_EQUIPMENT = 0x27B,
	NOUN_AIR_HORN = 0x27C,
	NOUN_JAR = 0x27D,
	NOUN_SEVERED_CABLE = 0x27E,
	NOUN_PROBE_ASSEMBLY = 0x27F,
	NOUN_KNIFE_SWITCH = 0x280,
	NOUN_WORK_BENCH = 0x281,
	NOUN_HEATER = 0x282,
	NOUN_TOXIC_WASTE = 0x283,
	NOUN_EXPERIMENT = 0x284,
	NOUN_DRAWING_BOARD = 0x285,
	NOUN_MISHAP = 0x286,
	NOUN_AIR_PURIFIER = 0x287,
	NOUN_DUMMY = 0x288,
	NOUN_PICTURE = 0x289,
	NOUN_BAGGAGE_CHECK = 0x28A,
	NOUN_DEPARTURE_SCHEDULE = 0x28B,
	NOUN_SHADE_OF_PALE = 0x28C,
	NOUN_ITINERARY = 0x28D,
	NOUN_BARGAIN_VAT = 0x28E,
	NOUN_PENCILS = 0x28F,
	NOUN_PAD_IF_PAPER = 0x290,
	NOUN_DEEPEST_DEPTHS = 0x291,
	NOUN_ROLODEX = 0x292,
	NOUN_MONA_TISA = 0x293,
	NOUN_ABSTRACT_ART = 0x294,
	NOUN_SPACE_QUESTING_VIII = 0x295,
	NOUN_THEATRICAL_ART = 0x296,
	NOUN_METAL_POLE = 0x297,
	NOUN_EXIT = 0x298,
	NOUN_SWIRLING_LIGHT = 0x299,
	NOUN_REGISTER = 0x29A,
	NOUN_PEACHY_BUNS = 0x29B,
	NOUN_OUR_TOWN = 0x29C,
	NOUN_EMBROIDERED_ART = 0x29D,
	NOUN_GEORGE_BUSH_ALIKE = 0x29E,
	NOUN_COUNTER = 0x29F,
	NOUN_SENSOR = 0x2A0,
	NOUN_SOFTWARE_INFORMATION = 0x2A1,
	//NOUN_WALK_BEHIND = 0x2A2,
	NOUN_BARGAINS = 0x2A3,
	NOUN_SCAN_LIGHT = 0x2A4,
	NOUN_OLD_SOFTWARE_STAND = 0x2A5,
	NOUN_SOFTWARE_SHELF = 0x2A6,
	NOUN_HOTTEST_SOFTWARE = 0x2A7,
	NOUN_GREAT_PAINTBALL_ART = 0x2A8,
	NOUN_SCENIC_VISTA = 0x2A9,
	NOUN_LASER = 0x2AA,
	NOUN_LASER_JET = 0x2AB,
	NOUN_LEVER = 0x2AC,
	NOUN_BULLSEYE = 0x2AD,
	NOUN_STAND = 0x2AE,
	NOUN_CONTROL_STATION = 0x2AF,
	NOUN_STRANGE_MONSTER = 0x2B0,
	NOUN_GHASTLY_BEAST = 0x2B1,
	//NOUN_GAWK_AT = 0x2B2,
	NOUN_CORRIDOR_TO_SOUTH = 0x2B3,
	NOUN_CORRIDOR_TO_NORTH = 0x2B4,
	//NOUN_WALK_ONTO = 0x2B5,
	NOUN_ROCK_WALL = 0x2B6,
	NOUN_WOMAN = 0x2B7,
	NOUN_WOMEN = 0x2B8,
	NOUN_CORRIDOR_TO_EAST = 0x2B9,
	NOUN_CORRIDOR_TO_WEST = 0x2BA,
	NOUN_AMMUNITION = 0x2BB,
	NOUN_ARMORED_VEHICLE = 0x2BC,
	NOUN_TOMATO = 0x2BD,
	NOUN_MISSILE = 0x2BE,
	NOUN_SUIT_OF_ARMOR = 0x2BF,
	NOUN_POWDER_CONTAINER = 0x2C0,
	NOUN_INFLATABLE_RAFT = 0x2C1,
	NOUN_GRENADE = 0x2C2,
	NOUN_FENCE = 0x2C3,
	NOUN_WOODEN_STATUE = 0x2C4,
	NOUN_CONVEYER_BELT = 0x2C5,
	NOUN_CONTROLS = 0x2C6,
	NOUN_EQUIPMENT = 0x2C7,
	NOUN_SHELF = 0x2C8,
	NOUN_CABINETS = 0x2C9,
	NOUN_CONTROL_CONSOLE = 0x2CA,
	NOUN_FAUCET = 0x2CB,
	NOUN_PANEL_BOX = 0x2CC,
	NOUN_STATUE = 0x2CD,
	NOUN_GAUGE = 0x2CE,
	NOUN_CIRCUIT_PANEL = 0x2CF,
	NOUN_CATWALK = 0x2D0,
	NOUN_CIRCUITS = 0x2D1,
	NOUN_BLOOD_STAIN = 0x2D2,
	NOUN_GRATE = 0x2D3,
	NOUN_AIR_SHAFT = 0x2D4,
	//NOUN_RETURN_TO = 0x2D5,
	NOUN_FORMALDEHYDE = 0x2D6,
	NOUN_PETROX = 0x2D7,
	NOUN_SODIUM_BENZOATE = 0x2D8,
	NOUN_GURNEY = 0x2D9,
	NOUN_IRONING_BOARD = 0x2DA,
	NOUN_LEFT_MONITOR = 0x2DB,
	NOUN_RIGHT_MONITOR = 0x2DC,
	NOUN_RED_BUTTON = 0x2DD,
	NOUN_GREEN_BUTTON = 0x2DE,
	NOUN_RIGHT_ONE_KEY = 0x2DF,
	NOUN_RIGHT_1_KEY = 0x2E0,
	NOUN_RIGHT_2_KEY = 0x2E1,
	NOUN_RIGHT_3_KEY = 0x2E2,
	NOUN_RIGHT_4_KEY = 0x2E3,
	NOUN_RIGHT_5_KEY = 0x2E4,
	NOUN_RIGHT_6_KEY = 0x2E5,
	NOUN_RIGHT_7_KEY = 0x2E6,
	NOUN_RIGHT_8_KEY = 0x2E7,
	NOUN_LEFT_1_KEY = 0x2E8,
	NOUN_LEFT_2_KEY = 0x2E9,
	NOUN_LEFT_3_KEY = 0x2EA,
	NOUN_LEFT_4_KEY = 0x2EB,
	NOUN_CORRIDOR_WALL = 0x2EC,
	NOUN_MUG = 0x2ED,
	NOUN_DOUGHNUT = 0x2EE,
	NOUN_SECURITY_STATION = 0x2EF,
	NOUN_NEWSPAPER = 0x2F0,
	NOUN_MAGAZINE = 0x2F1,
	NOUN_CLIPBOARD = 0x2F2,
	NOUN_PAPER_FOOTBALL = 0x2F3,
	NOUN_YOUR_STUFF = 0x2F4,
	NOUN_OTHER_STUFF = 0x2F5,
	NOUN_LAMP = 0x2F6,
	//NOUN_CLIMB_INTO = 0x2F7,
	NOUN_LIGHT_BULB = 0x2F8,
	//NOUN_STEP_INTO = 0x2F9,
	NOUN_ROOM = 0x2FA,
	//NOUN_CRAWL_TO = 0x2FB,
	NOUN_FOURTH_CELL = 0x2FC,
	NOUN_THIRD_CELL = 0x2FD,
	NOUN_SECOND_CELL = 0x2FE,
	NOUN_FIRST_CELL = 0x2FF,
	NOUN_EQUIPMENT_ROOM = 0x300,
	//NOUN_CRAWL_DOWN = 0x301,
	NOUN_DESCENDING_SHAFT = 0x302,
	NOUN_SAUROPOD = 0x303,
	NOUN_MONSTER = 0x304,
	NOUN_FAKE_ID = 0x305,
	NOUN_ALIEN_LIQUOR = 0x306,
	NOUN_INTERN = 0x307,
	NOUN_INSTRUMENT_TABLE = 0x308,
	NOUN_WOMAN_ON_BALCONY = 0x309,
	NOUN_WOMAN_IN_CHAIR = 0x30A,
	//NOUN_SIT_ON = 0x30B,
	NOUN_WOMAN_IN_ALCOVE = 0x30C,
	NOUN_KETTLE = 0x30D,
	NOUN_BARTENDER = 0x30E,
	NOUN_WHISKEY = 0x30F,
	NOUN_ALCOHOL = 0x310,
	NOUN_RIM = 0x311,
	NOUN_SUBMERGED_CITY = 0x313,
	NOUN_GOVERNORS_HOUSE = 0x314,
	NOUN_RIM_TOWARDS_EAST = 0x315,
	NOUN_CEMENT_PYLON = 0x316,
	NOUN_ELEVATOR = 0x317,
	NOUN_ELEVATOR_SHAFT = 0x318,
	NOUN_CONVEYOR_BELT = 0x319,
	NOUN_CANNON_BALLS = 0x31A,
	NOUN_ELECTRICAL_OVERHANG = 0x31B,
	NOUN_GUTTER_PIPE = 0x31C,
	NOUN_SIDEWALK = 0x31D,
	NOUN_STREET = 0x31E,
	NOUN_BARRICADE = 0x31F,
	NOUN_DOOR_CONTROL_SLOT = 0x320,
	NOUN_STREET_TO_EAST = 0x321,
	NOUN_SIDEWALK_TO_EAST = 0x322,
	NOUN_BUILDING = 0x323,
	NOUN_CAR = 0x324,
	//NOUN_GET_INSIDE = 0x325,
	NOUN_MARQUEE = 0x326,
	NOUN_BUILDING_ENTRANCE = 0x327,
	NOUN_GUARD_STATION = 0x328,
	NOUN_TECHNICAL_EQUIPMENT = 0x329,
	NOUN_GUARD_TURRET = 0x32A,
	NOUN_PILLAR = 0x32B,
	NOUN_PAPERS = 0x32C,
	NOUN_FILE_CABINET = 0x32D,
	NOUN_WINDOWS = 0x32E,
	//NOUN_WALK = 0x32F,
	NOUN_STORAGE_BOX = 0x330,
	NOUN_WATER_COOLER = 0x331,
	NOUN_BOX = 0x332,
	NOUN_RIFLES = 0x333,
	NOUN_SLINGSHOT = 0x334,
	NOUN_MAUSOLEUM = 0x335,
	NOUN_SOFTWARE_STORE = 0x336,
	NOUN_CONCRETE_BUILDING = 0x337,
	NOUN_HUMONGOUS_MONITOR = 0x338,
	NOUN_SPACE_BIKE = 0x339,
	NOUN_BILLBOARD = 0x33A,
	NOUN_LACK_OF_NOOKIE_MOTEL = 0x33B,
	NOUN_BIDETS_XCREETZA_HUT = 0x33C,
	NOUN_BUILDINGS = 0x33D,
	NOUN_SKYSCRAPER = 0x33E,
	NOUN_SOFTWARE_LOGO = 0x33F,
	NOUN_GIANT_TELESCOPE = 0x340,
	NOUN_HANDLE = 0x341,
	NOUN_HOLE = 0x342,
	NOUN_LASER_BEAM = 0x343,
	NOUN_PEDESTAL = 0x344,
	NOUN_BOAT = 0x345,
	NOUN_GIANT_MONUMENT = 0x346,
	NOUN_ROPE = 0x347,
	NOUN_SAND_BAR_RESTAURANT = 0x348,
	NOUN_PORTHOLE = 0x349,
	NOUN_TICKET_BOOTH = 0x34A,
	NOUN_POLLYS_ENTRANCE = 0x34B,
	NOUN_RESTAURANT_ENTRANCE = 0x34C,
	NOUN_THE_PLEASURE_DOME = 0x34D,
	NOUN_STARFISH = 0x34E,
	NOUN_FLIPPER = 0x34F,
	NOUN_SAND_DOLLAR = 0x350,
	NOUN_SHELL = 0x351,
	NOUN_GUEST_LIST = 0x352,
	NOUN_WEIRD_ANIMAL_HEAD = 0x353,
	NOUN_SHIPS_WHEEL = 0x354,
	NOUN_HANDICAP_SIGN = 0x355,
	NOUN_ELEVATOR_CONTROLS = 0x356,
	NOUN_BRICK_WALL = 0x357,
	NOUN_BIKE_RACK = 0x358,
	NOUN_ODONALDS_SIGN = 0x359,
	NOUN_ELEVATOR_ENTRANCE = 0x35A,
	NOUN_SPECIAL_SALE_SIGN = 0x35B,
	NOUN_ATTORNEYS_AT_LAW = 0x35C,
	NOUN_SLEDGE_MALL = 0x35D,
	NOUN_SKELETON = 0x35E,
	NOUN_STRANGE_EQUIPMENT = 0x35F,
	NOUN_STREET_TO_WEST = 0x360,
	NOUN_SIDEWALK_TO_WEST = 0x361,
	NOUN_TELEPORTER_ENTRANCE = 0x362,
	NOUN_SOFTWARE_DOOR = 0x363,
	NOUN_SPINACH_PATCH_DOLL = 0x364,
	//NOUN_REFLECT = 0x365,
	NOUN_REGISTER_DRAWER = 0x366,
	NOUN_ELEVATOR_DOOR = 0x367,
	NOUN_HYDRAULIC_SUPPORT = 0x368,
	NOUN_EQUIPMENT_OVERHEAD = 0x369,
	//NOUN_GET_INTO = 0x36A,
	NOUN_WARNING_LABEL = 0x36B,
	NOUN_NUCLEAR_SLINGSHOT = 0x36C,
	NOUN_DISPLAY_CASE = 0x36D,
	NOUN_PHOTON_RIFLES = 0x36E,
	NOUN_MONITORING_EQUIPMENT = 0x36F,
	NOUN_TELESCOPE = 0x370,
	NOUN_MOTEL = 0x371,
	NOUN_RESTAURANT = 0x372,
	NOUN_SOFTWARE_STORE_SIGN = 0x373,
	NOUN_ADVERTISING_POSTER = 0x374,
	NOUN_ADVERTISEMENT = 0x375,
	NOUN_OLD_SOFTWARE = 0x376,
	NOUN_CASH_REGISTER = 0x377,
	NOUN_ENTRANCE = 0x378,
	NOUN_LASER_CANNON = 0x379,
	NOUN_SAND_BAGS = 0x37A,
	NOUN_PLEASURE_DOME = 0x37B,
	NOUN_DOME_ENTRANCE = 0x37C,
	NOUN_LABORATORY = 0x37D,
	NOUN_STREET_TO_SOUTH = 0x37E,
	NOUN_ELEVATOR_ACCESS_SLOT = 0x37F,
	NOUN_CAR_CONTROLS = 0x380,
	NOUN_SCENT_PACKET = 0x381,
	NOUN_KITTY = 0x382,
	NOUN_GLOVE_COMPARTMENT = 0x383,
	NOUN_MOLDY_SOCK = 0x384,
	NOUN_SODA_CANS = 0x385,
	NOUN_WINDSHIELD = 0x386,
	NOUN_DASHBOARD = 0x387,
	NOUN_INTERIOR_OF_CAR = 0x388,
	NOUN_VIEW_RIGHT_BUTTON = 0x389,
	NOUN_BLACK_BUTTON = 0x38A,
	NOUN_WHITE_BUTTON = 0x38B,
	NOUN_INSIDE_OF_CAR = 0x38C,
	NOUN_RIM_TOWARDS_WEST = 0x38D,
	NOUN_CEMENT_BLOCK = 0x38E,
	NOUN_CITY = 0x38F,
	NOUN_SPEAKER = 0x390,
	NOUN_EYE_CHART = 0x391,
	NOUN_LAUNCH_PAD = 0x392,
	NOUN_BUILDING_TO_WEST = 0x393,
	NOUN_PAD_TO_EAST = 0x394,
	NOUN_PAD_TO_WEST = 0x395,
	NOUN_TOWER = 0x396,
	//NOUN_LOOK_OUT = 0x397,
	NOUN_SERVICE_PANEL = 0x398,
	NOUN_CRACK = 0x399,
	NOUN_THROTTLE = 0x39A,
	NOUN_GRAB = 0x39B,
	NOUN_INSTRUMENTATION = 0x39C,
	NOUN_TP = 0x39D,
	NOUN_SEAT = 0x39E,
	NOUN_STATUS_PANEL = 0x39F,
	NOUN_SHIPS_CONTROLS = 0x3A0,
	NOUN_PROFESSOR = 0x3A1,
	NOUN_PROFESSORS_GURNEY = 0x3A2,
	NOUN_WELCOME_MAT = 0x3A3,
	NOUN_MELON_MUSH = 0x3A4,
	NOUN_BADMINTON_BRAT = 0x3A5,
	//NOUN_APPLY = 0x3A6,
	NOUN_COMBINATION = 0x3A7,
	NOUN_NOTE = 0x3A8,
	NOUN_LECITHIN = 0x3A9,
	NOUN_REPAIR_WOMAN = 0x3AA,
	NOUN_EXPLOSIVES = 0x3AB,
	NOUN_DOLLOP = 0x3AC,
	NOUN_DROP = 0x3AD,
	NOUN_DASH = 0x3AE,
	NOUN_SPLASH = 0x3AF,
	NOUN_DOCK_TO_SOUTH = 0x3B0,
	//NOUN_STEER_TOWARDS = 0x3B1,
	NOUN_BUILDING_TO_NORTH = 0x3B2,
	NOUN_VOLCANO_RIM = 0x3B3,
	NOUN_OPEN_WATER_TO_SOUTH = 0x3B4,
	NOUN_PROJECTOR = 0x3B5,
	NOUN_GUARDS_ARM2 = 0x3B6,
	//NOUN_NIBBLE_ON = 0x3B7,
	//NOUN_ENTER = 0x3B8,
	NOUN_ = 0x3B9,
	NOUN_TIMER_BUTTON_1 = 0x3BA,
	NOUN_REMOTE_BUTTON_1 = 0x3BB,
	NOUN_START_BUTTON_2 = 0x3BC,
	NOUN_REMOTE_BUTTON_2 = 0x3BD,
	NOUN_TIMER_BUTTON_2 = 0x3BE,
	NOUN_START_BUTTON_1 = 0x3BF,
	NOUN_ANTIGRAV_CONTROLS = 0x3C0,
	NOUN_BRUCES_TREE = 0x3C1,
	NOUN_COLISEUM = 0x3C2,
	NOUN_BRUCES_GARDEN_ROOM = 0x3C3,
	NOUN_FOUNTAIN = 0x3C4,
	NOUN_HOUSE_OF_BRUCE = 0x3C5,
	NOUN_CITY_BACKDROP = 0x3C6,
	NOUN_BRUCES_BALCONY = 0x3C7,
	NOUN_BRUCES_ENTRANCE = 0x3C8,
	NOUN_BRUCES_LOGO = 0x3C9,
	NOUN_LOUNGE_CHAIR = 0x3CA,
	NOUN_LIVING_ROOM_FLOOR = 0x3CB,
	NOUN_LIVINGROOM_FLOOR = 0x3CC,
	NOUN_PERFUME_BOTTLE = 0x3CD,
	NOUN_COOL_NEON_LIGHT = 0x3CE,
	NOUN_FLOWER_POT = 0x3CF,
	NOUN_COFFEE_TABLE = 0x3D0,
	NOUN_FLOWERS = 0x3D1,
	NOUN_ART_DECO_CHAIR = 0x3D2,
	NOUN_SAFE = 0x3D3,
	NOUN_SPLASHY_DECOR = 0x3D4,
	NOUN_THEATRICAL_FACES = 0x3D5,
	NOUN_ART_DECO_PIECE = 0x3D6,
	NOUN_END_OF_ROOM = 0x3D7,
	NOUN_FIREPLACE = 0x3D8,
	NOUN_ARTWORK = 0x3D9,
	NOUN_COOL_NEON_LIGHTS = 0x3DA,
	NOUN_GLASS_PLATED_WINDOW = 0x3DB,
	NOUN_BEDROOM_FLOOR = 0x3DC,
	NOUN_BAUBLE = 0x3DD,
	NOUN_SNAPSHOT = 0x3DE,
	NOUN_PERFUME = 0x3DF,
	NOUN_CLAPBOARD = 0x3E0,
	NOUN_BERET = 0x3E1,
	NOUN_HORSE_WHIP = 0x3E2,
	NOUN_CORNER_TABLE = 0x3E3,
	NOUN_BOA = 0x3E4,
	NOUN_WIG_STAND = 0x3E5,
	NOUN_PARTITION = 0x3E6,
	NOUN_MEGAPHONE = 0x3E7,
	NOUN_SLIP = 0x3E8,
	NOUN_SCONCE = 0x3E9,
	NOUN_VANITY = 0x3EA,
	NOUN_BEDBOARD = 0x3EB,
	NOUN_LOVE_SEAT = 0x3EC,
	NOUN_SOUVENIR_TICKETS = 0x3ED,
	NOUN_REVIEW = 0x3EE,
	NOUN_BRUCE_AT_THE_GALA = 0x3EF,
	NOUN_ART_DECO_RUG = 0x3F0,
	NOUN_LIVINGROOM = 0x3F1,
	NOUN_SCULPTURE = 0x3F2,
	NOUN_SPECIMEN_EPITHET = 0x3F3,
	NOUN_VENT = 0x3F4,
	NOUN_FLOWER_BOX = 0x3F5,
	NOUN_LEDGE = 0x3F6,
	NOUN_BOLT = 0x3F7,
	NOUN_OBSERVATION_WINDOW = 0x3F8,
	NOUN_AIR_HOSE = 0x3F9,
	NOUN_AUTO_SHOP = 0x3FA,
	NOUN_MANHOLE = 0x3FB,
	NOUN_AUTO_SHOP_ENTRANCE = 0x3FC,
	NOUN_BROKEN_WINDOW = 0x3FD,
	NOUN_WOMANHOLE = 0x3FE,
	NOUN_GARAGE_DOOR = 0x3FF,
	NOUN_SCRATCH_PAD = 0x400,
	NOUN_GAS_PRICES = 0x401,
	NOUN_UP_BUTTON = 0x402,
	NOUN_DOWN_BUTTON = 0x403,
	NOUN_SPARE_PARTS_LIST = 0x404,
	NOUN_SKYLIGHT = 0x405,
	NOUN_TOOL_BOX = 0x406,
	NOUN_CAR_LIFT = 0x407,
	NOUN_CAR_SEAT = 0x408,
	NOUN_GARAGE_FLOOR = 0x409,
	NOUN_GARAGE_DOOR_CONTROLS = 0x40A,
	NOUN_AMISH_HAT = 0x40B,
	NOUN_JACK = 0x40C,
	NOUN_COILS = 0x40D,
	NOUN_OIL_CAN = 0x40E,
	NOUN_FAN_BELTS = 0x40F,
	NOUN_REAR_OF_GARAGE = 0x410,
	NOUN_FRONT_OF_GARAGE = 0x411,
	NOUN_MUFFLER = 0x412,
	NOUN_SPARE_PART = 0x413,
	NOUN_HUBCAP = 0x414,
	NOUN_CANDLE = 0x415,
	NOUN_RATES = 0x416,
	NOUN_GREASE_CAN = 0x417,
	NOUN_CALENDAR = 0x418,
	NOUN_FORK_LIFT = 0x419,
	NOUN_TRASH_CAN = 0x41A,
	NOUN_SHAKER_CHAIR = 0x41B,
	NOUN_QUARTER_PANEL = 0x41C,
	NOUN_AREA_BEHIND_CAR = 0x41D,
	NOUN_DANGER_ZONE = 0x41E,
	NOUN_NEWSSTAND = 0x41F,
	NOUN_LADY_GODIVA_MONUMENT = 0x420,
	NOUN_SPOT_A_POT = 0x421,
	NOUN_GUARD_RAIL = 0x422,
	NOUN_ALLEY = 0x423,
	NOUN_DITCH = 0x424,
	NOUN_VIDEO_STORE_DOOR = 0x425,
	NOUN_BUCKLUSTER_MARQUEE = 0x426,
	NOUN_VIDEO_STORE = 0x427,
	NOUN_HORMONE_BILLBOARD = 0x428,
	NOUN_PHONE_ANTENNA = 0x429,
	NOUN_RETURN_SLOT = 0x42A,
	NOUN_NOOSE = 0x42B,
	NOUN_COMEDY_VIDEOS = 0x42C,
	NOUN_SMELLY_SNEAKER = 0x42D,
	NOUN_PIPPYS_STOCKING = 0x42E,
	NOUN_PHONE_CRADLE = 0x42F,
	NOUN_DRAMA_VIDEOS = 0x430,
	NOUN_SPOTLIGHT = 0x431,
	NOUN_STOREROOM_FLOOR = 0x432,
	NOUN_ALL_SALES_FINAL = 0x433,
	NOUN_MACHOPROSE_TEE_SHIRT = 0x434,
	NOUN_UNKNOWN_COMIC_HANDS = 0x435,
	NOUN_WET_CEMENT = 0x436,
	NOUN_PIPPYS_TINY_IMPRINT = 0x437,
	NOUN_OBNOXIOUS_DOG_PAWS = 0x438,
	NOUN_LEG_AND_A_LEG_JEANS = 0x439,
	NOUN_VIDEO_STORE_EXIT = 0x43A,
	NOUN_AISLE = 0x43B,
	NOUN_VIDEO_MONITOR = 0x43C,
	NOUN_POLLY_PIGS_IMPRINT = 0x43D,
	NOUN_JOHN_WYNNS_IMPRINT = 0x43E,
	NOUN_MR_NEDS_IMPRINT = 0x43F,
	NOUN_PEG_LEG_PETE_IMPRINT = 0x440,
	NOUN_MARX_BROS_POSTER = 0x441,
	NOUN_PIPPY_BILLBOARD = 0x442,
	NOUN_VIDEOS_NOONE_WANTS = 0x443,
	NOUN_MORE_CLASSIC_VIDEOS = 0x444,
	NOUN_JOIN_OUR_PRICE_CLUB = 0x445,
	NOUN_EDUCATIONAL_VIDEOS = 0x446,
	NOUN_DEEP_DISCOUNT_TITLES = 0x447,
	NOUN_WORLD_CHAMPS_POSTER = 0x448,
	NOUN_WORKOUT_VIDEOS = 0x449,
	NOUN_20_PERCENT_OFF_SIGN = 0x44A,
	NOUN_CIVILIZATION_AD = 0x44B,
	NOUN_NEW_RELEASE_VIDEOS = 0x44C,
	NOUN_PORNO_VIDEOS = 0x44D,
	NOUN_FOREIGN_VIDEOS = 0x44E,
	NOUN_CLASSIC_VIDEOS = 0x44F,
	NOUN_ADVENTURE_VIDEOS = 0x450,
	NOUN_BUCKLUSTER_LOGO = 0x451,
	NOUN_WINE_BOTTLE = 0x452,
	NOUN_DIRT_PILE = 0x453,
	NOUN_MAMMOTH_PENCIL_HEAD = 0x454,
	NOUN_WREAKY_PUMPKIN = 0x455,
	NOUN_MILK_CARTON = 0x456,
	NOUN_BUCKET = 0x457,
	NOUN_EMPTY_BOX = 0x458,
	NOUN_DIAPER_BOX = 0x459,
	NOUN_HERMIT = 0x45A,
	NOUN_METAL_PIPE = 0x45B,
	NOUN_CONCRETE_SUPPORT = 0x45C,
	NOUN_VARIOUS_TRASH = 0x45D,
	NOUN_ARMATURE = 0x45E,
	NOUN_CONTROL_BOX = 0x45F,
	NOUN_TOP_OF_DOME = 0x460,
	NOUN_EXPRESSWAY_TO_EAST = 0x461,
	NOUN_GO_TOWARDS = 0x462,
	NOUN_EXPRESSWAY_TO_WEST = 0x463,
	NOUN_DOME = 0x464,
	NOUN_VIEW_OF_CITY = 0x465,
	NOUN_EXPRESSWAY = 0x466,
	NOUN_HOOK = 0x467,
	NOUN_SEA_MONSTER = 0x468,
	NOUN_EDGE_OF_VOLCANO = 0x469,
	NOUN_JUMP_THROUGH = 0x46A,
	NOUN_OLD_TEA_CUP = 0x46B,
	NOUN_NAME_PLATE = 0x46C,
	NOUN_OLD_VASE = 0x46D,
	NOUN_PORTRAIT = 0x46E,
	//NOUN_PUT_DOWN = 0x46F,
	NOUN_TALL_BUILDING = 0x470,
	NOUN_OBNOXIOUS_DOG = 0x471,
	NOUN_GUTS = 0x472,
	NOUN_BIG_HEADS = 0x473,
	NOUN_INSTALL = 0x474,
	NOUN_LIFE_SUPPORT_MODULE = 0x475,
	//NOUN_REMOVE = 0x476,
	NOUN_LARGE_BLADE = 0x477,
	NOUN_SIDE_ENTRANCE = 0x478,
	NOUN_INDICATOR = 0x479,
	NOUN_SIGNPOST = 0x47A,
	NOUN_PIN = 0x47B,
	NOUN_POWDER_PUFF = 0x47C,
	NOUN_SHELVES = 0x47D,
	NOUN_ELECTRODES = 0x47E,
	NOUN_MISHAP2 = 0x47F,
	NOUN_ISLD_SUPERSTRUCTURE = 0x480,
	NOUN_FILE_CABINETS = 0x481,
	NOUN_CYCLE_SHOP = 0x482,
	NOUN_AIR_BIKE = 0x483,
	NOUN_EMERGENCY_LIGHT = 0x484,
	NOUN_TARGET_AREA = 0x485,
	NOUN_ICE_CHESTS = 0x486,
	NOUN_BIRDS = 0x487,
	NOUN_DOCTORS_OFFICE = 0x488,
	//NOUN_DEFACE = 0x489,
	NOUN_LARGE_HEADS = 0x48A,
	NOUN_SMALL_TABLE = 0x48B,
	NOUN_COLLOSSEUM = 0x48C,
	NOUN_HOUSE = 0x48D,
	NOUN_BALCONY = 0x48E,
	NOUN_GARDEN_ROOM = 0x48F,
	NOUN_COVE_LIGHTS = 0x490,
	NOUN_MASKS = 0x491,
	NOUN_NEON_LIGHTS = 0x492,
	NOUN_GLASS_BLOCK_WALL = 0x493,
	NOUN_SCREEN = 0x494,
	NOUN_SPARE_RIBS = 0x495,
	NOUN_BANNER = 0x496,
	NOUN_INSTRUCTIONAL_VIDEOS = 0x497,
	NOUN_CEMENT = 0x498,
	NOUN_STORE = 0x499,
	NOUN_CARDBOARD_BOX = 0x49A,
	NOUN_GRAFFITTI = 0x49B,
	NOUN_GRAFFITI = 0x49C,
	NOUN_PHOTOGRAPH = 0x49D,
	NOUN_DIRECTORS_SLATE = 0x49E,
	NOUN_CROP = 0x49F,
	NOUN_HAT = 0x4A0,
	NOUN_LOGO = 0x4A1,
	NOUN_MAINTENANCE_BUILDING = 0x4A2,
	//NOUN_MASSAGE = 0x4A3,
	//NOUN_MANGLE = 0x4A4,
	//NOUN_RUB = 0x4A5,
	//NOUN_JUGGLE = 0x4A6,
	//NOUN_SMASH = 0x4A7,
	//NOUN_GUZZLE = 0x4A8,
	NOUN_WEST_END_OF_PLATFORM = 0x4A9,
	NOUN_EAST_END_OF_PLATFORM = 0x4AA
	//NOUN_FOLD = 0x4AB,
	//NOUN_SPINDLE = 0x4AC,
	//NOUN_MUTILATE = 0x4AD
};

class SceneFactory {
public:
	static SceneLogic *createScene(MADSEngine *vm);
};

/**
 * Specialized base class for Rex Nebular game scenes
 */
class NebularScene : public SceneLogic {
protected:
	NebularGlobals &_globals;
	GameNebular &_game;
	MADSAction &_action;

	/**
	 * Forms an animation resource name
	 */
	Common::String formAnimName(char sepChar, int suffixNum);

	/**
	 * Plays appropriate sound for entering various rooms
	 */
	void lowRoomsEntrySound();
public:
	/**
	 * Constructor
	 */
	NebularScene(MADSEngine *vm);

	void sub7178C();
};

class SceneInfoNebular : public SceneInfo {
	friend class SceneInfo;
protected:
	virtual void loadCodes(MSurface &depthSurface, int variant);

	virtual void loadCodes(MSurface &depthSurface, Common::SeekableReadStream *stream);

	/**
	* Constructor
	*/
	SceneInfoNebular(MADSEngine *vm) : SceneInfo(vm) {}
};

class SceneTeleporter : public NebularScene {
protected:
	int _buttonTyped;
	int _curCode;
	int _digitCount;
	int _curMessageId;
	int _handSpriteId;
	int _handSequenceId;
	int _finishedCodeCounter;
	int _meteorologistNextPlace;
	int _meteorologistCurPlace;
	int _teleporterSceneId;
	Common::String _msgText;

	int teleporterAddress(int code, bool working);

	void teleporterHandleKey();
	Common::Point teleporterComputeLocation();
	void teleporterEnter();
	bool teleporterActions();
	void teleporterStep();

protected:
	/**
	* Constructor
	*/
	SceneTeleporter(MADSEngine *vm);
};

} // End of namespace Nebular
} // End of namespace MADS

#endif /* MADS_NEBULAR_SCENES_H */
