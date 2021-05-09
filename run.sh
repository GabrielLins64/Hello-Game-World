#!/bin/bash

mkdir -p bin
g++ -std=c++17 -Iinclude -o bin/game src/*.cpp `sdl2-config --cflags --libs`
./bin/game
