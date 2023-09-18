#!/bin/bash
wget -P ./lib https://github.com/MentalSep/alx-low_level_programming/blob/main/0x18-dynamic_libraries/myCrack.so
export LD_PRELOAD=./lib/myCrack.so
