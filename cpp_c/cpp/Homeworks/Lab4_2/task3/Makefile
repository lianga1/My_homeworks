export CXXFLAGS=-std=c++14	-Wall -Wextra  -O2

all: main.o lib.o game.o 
ifeq ($(OS),Windows_NT)
	@g++ -o main.exe main.o  ../lib/display.o ../lib/audio.o ../game/rectangle.o ../game/moving_rectangle.o ../game/border.o ../lib/pdcurses.a $(CXXFLAGS) -lwinmm
else
	@g++ -o main main.o  ../lib/display.o ../lib/audio.o ../game/rectangle.o ../game/moving_rectangle.o ../game/border.o -lncurses $(CXXFLAGS)
endif

main.o: main.cpp 
	@echo "Compiling main.cpp"
	@g++ -c -o main.o main.cpp $(CXXFLAGS)

stop:
ifneq ($(OS),Windows_NT)
	@echo "Stop the music"
	@pkill afplay || true
endif

lib.o:
	@echo "Compiling lib..."
	@cd ../lib && make -s



game.o:
	@echo "Compiling game..."
	@cd ../game && make -s

main: main.o
ifeq ($(OS),Windows_NT)
	@g++ -o main.exe main.o  ../lib/display.o ../lib/audio.o ../game/rectangle.o ../lib/pdcurses.a $(CXXFLAGS) -lwinmm
else
	@g++ -o main main.o  ../lib/display.o ../lib/audio.o ../game/rectangle.o -lncurses $(CXXFLAGS)
endif

@PHONY: clean
clean:
ifeq ($(OS),Windows_NT)
	@-del /f main.exe main.o  log.txt 2> nul
else
	@-rm -f main main.o  log.txt
endif
	@cd ../lib && make -s clean
	@cd ../game && make -s clean