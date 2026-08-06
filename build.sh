#!/bin/bash
set -e

BUILD_DIR="build"

if [[ "$(uname -s)" == "Darwin" ]]; then
	# macOS: SFML comes from Homebrew.
	cmake -B "$BUILD_DIR" -DCMAKE_PREFIX_PATH="$(brew --prefix sfml)" "$@"
else
	# Linux: use the distro SFML (Debian/Ubuntu: sudo apt install libsfml-dev)
	# or pass -DCMAKE_PREFIX_PATH=<sfml prefix> for a custom SFML install.
	cmake -B "$BUILD_DIR" "$@"
fi

cmake --build "$BUILD_DIR" --verbose
