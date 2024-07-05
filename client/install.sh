#!/bin/bash

PROJECT_DIR=$(dirname "$PWD/client")

BUILD_DIR="$PROJECT_DIR/build"

if [ ! -d "$BUILD_DIR" ]; then
    mkdir "$BUILD_DIR"
fi

cd "$BUILD_DIR"

cmake "$PROJECT_DIR"

cmake --build .

sudo cmake --install .

