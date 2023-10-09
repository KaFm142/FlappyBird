CC = g++
CFLAGS = -Wall -Wextra -pedantic -std=c++11
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

# List of source files
SOURCES = Menu.cpp testMenu.cpp Screen.cpp Player.cpp

# List of object files
OBJECTS = $(SOURCES:.cpp=.o)

# The target executable
TARGET = flappyBird.exe  # Note the .exe extension

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $^ -o $@ $(LDFLAGS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
