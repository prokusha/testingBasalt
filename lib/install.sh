#!/bin/bash

PROJECT_DIR=$(dirname "$PWD/lib")

BUILD_DIR="$PROJECT_DIR/build"

if [ ! -d "$BUILD_DIR" ]; then
    mkdir "$BUILD_DIR"
fi

cd "$BUILD_DIR"

cmake "$PROJECT_DIR"

cmake --build .

sudo cmake --install .

sudo ldconfig
