all: configure build

configure:
	mkdir build && cmake -B build -S .

build:
	cmake --build build

debug:
	cmake --build build && G_MESSAGES_DEBUG=Plugin_Example rofi -show example -plugin-path ./build/lib

install:
	cmake --install build

clear:
	rm -r build | exit

rerun:
	cmake --build build && G_MESSAGES_DEBUG=Plugin_Example rofi -show example -plugin-path ./build/lib


