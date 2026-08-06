cmake_minimum_required(VERSION 3.16)
project(spolf LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Prefer SFML 3 (macOS/brew), fall back to SFML >= 2.6 for Linux distros
# that only ship 2.6.x (Debian/Ubuntu: libsfml-dev).
# Components must be lowercase: SFML 2.6's config matches them against the
# sfml-* targets case-sensitively.
find_package(SFML 3 QUIET COMPONENTS graphics window system)
if(NOT SFML_FOUND)
	find_package(SFML 2.6 QUIET COMPONENTS graphics window system)
	if(NOT SFML_FOUND)
		message(FATAL_ERROR
			"SFML not found. Install it and retry:\n"
			"  - macOS:  brew install sfml\n"
			"  - Debian/Ubuntu:  sudo apt install libsfml-dev\n"
			"  - custom install:  cmake -DCMAKE_PREFIX_PATH=/path/to/sfml ..."
		)
	endif()
endif()

add_executable(spolf src/main.cpp)

# Target naming differs between SFML 2.6 (sfml-graphics) and SFML 3 (SFML::Graphics).
if(TARGET SFML::Graphics)
	target_link_libraries(spolf PRIVATE
		SFML::Graphics
		SFML::Window
		SFML::System
	)
else()
	target_link_libraries(spolf PRIVATE
		sfml-graphics
		sfml-window
		sfml-system
	)
endif()
