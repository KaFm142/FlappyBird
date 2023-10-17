CC = g++
CFLAGS = -Wall -Wextra -pedantic -std=c++11 -g
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system
VALGRIND = valgrind

# List of source files
SOURCES = Menu.cpp main.cpp Screen.cpp \
Player.cpp Gameplay.cpp Bird.cpp Unflyable.cpp\
OriginalBird.cpp Pipes.cpp Obstancles.cpp\
Chicken.cpp Penguin.cpp Flyable.cpp\
Falcon.cpp Owl.cpp

TESTMENU = Menu.cpp TestMenu.cpp Screen.cpp \
Player.cpp Gameplay.cpp Bird.cpp Unflyable.cpp\
OriginalBird.cpp Pipes.cpp Obstancles.cpp\
Chicken.cpp Penguin.cpp Flyable.cpp\
Falcon.cpp Owl.cpp

TESTGAMEPL = Menu.cpp TestGameplay.cpp Screen.cpp \
Player.cpp Gameplay.cpp Bird.cpp Unflyable.cpp\
OriginalBird.cpp Pipes.cpp Obstancles.cpp\
Chicken.cpp Penguin.cpp Flyable.cpp\
Falcon.cpp Owl.cpp

TESTPLAYER = Player.cpp TestPlayer.cpp

# List of object files
OBJECTS = $(SOURCES:.cpp=.o)
TESTMENUOBJECT = $(TESTMENU:.cpp=.o)
TESTGAMEPLOBJECT = $(TESTGAMEPL:.cpp=.o)
TESTPLAYEROBJECT = $(TESTPLAYER:.cpp=.o)

# The target executable
TARGET = flappyBird  
TESTMENUTARGET = testmenu
TESTGAMEPLTARGET = testgameplay
TESTPLAYERARGET = testplayer

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $^ -o $@ $(LDFLAGS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

testmenu: $(TESTMENUTARGET)

testgameplay: $(TESTGAMEPLTARGET)

testplayer:$(TESTPLAYERARGET)

$(TESTMENUTARGET): $(TESTMENUOBJECT)
	$(CC) $^ -o $@ $(LDFLAGS)

$(TESTGAMEPLTARGET): $(TESTGAMEPLOBJECT)
	$(CC) $^ -o $@ $(LDFLAGS)

$(TESTPLAYERARGET): $(TESTPLAYEROBJECT)
	$(CC) $^ -o $@ $(LDFLAGS)

clean:
	rm -f $(OBJECTS) $(TESTMENUOBJECT) $(TESTGAMEPLOBJECT) $(TESTPLAYEROBJECT) 

run: $(TARGET)
	./$(TARGET)

testmenurun: $(TESTMENUTARGET)
	./$(TESTMENUTARGET)
testgameplrun: $(TESTGAMEPLTARGET)
	./$(TESTGAMEPLTARGET)
testgameplrun: $(TESTPLAYER)
	./$(TESTPLAYER)

.PHONY: all clean run
