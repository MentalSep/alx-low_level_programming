#!/bin/bash
wget -P ./lib https://raw.githubusercontent.com/MentalSep/alx-low_level_programming/main/0x18-dynamic_libraries/myCrack.so
export LD_PRELOAD=./lib/myCrack.so
