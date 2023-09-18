#!/bin/bash
wget -P ./lib https://github.com/MentalSep/alx-low_level_programming/raw/main/0x18-dynamic_libraries/libdynamic.so
export LD_PRELOAD=./lib/myCrack.so
