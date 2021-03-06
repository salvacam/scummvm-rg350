#!/bin/bash

export PATH=/opt/gcw0-toolchain/usr/bin:$PATH

# Disable high resolution engines since we have 320x240 hardware
./configure --host=gcw0 --with-mad-prefix=/opt/gcw0-toolchain/usr --enable-plugins --default-dynamic --enable-release && make -j6 gcw-opk && ls -l scummvm.opk
