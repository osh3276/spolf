#!/bin/bash
set -e

BUILD_DIR="build"

cmake -B "$BUILD_DIR" -DCMAKE_PREFIX_PATH="$(brew --prefix sfml)" "$@"
cmake --build "$BUILD_DIR" --verbose
