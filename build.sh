#!/bin/sh

export PKG_CONFIG_PATH=$HOME/opt/raylib/lib/pkgconfig/

echo "Compilation starts!"

clang++ `pkg-config --cflags raylib` -o scp.o ./src/main.cpp `pkg-config --libs raylib` -lm -lglfw -ldl -lpthread

echo "Compilation finished!"