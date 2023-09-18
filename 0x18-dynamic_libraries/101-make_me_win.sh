#!/bin/bash
wget --output-document=$HOME/myCrack.so https://github.com/MentalSep/alx-low_level_programming/raw/main/0x18-dynamic_libraries/myCrack.so
export LD_PRELOAD=$HOME/myCrack.so
