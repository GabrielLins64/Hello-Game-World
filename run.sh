#!/bin/bash

g++ -std=c++17 -Iinclude -o bin/game src/*.cpp `sdl2-config --cflags --libs`
./bin/main
