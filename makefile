CC = g++
CFLAGS = -Wall -Wextra -pedantic -std=c++11
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

# List of source files
SOURCES = Screen.cpp testScreen.cpp

# List of object files
OBJECTS = $(SOURCES:.cpp=.o)

# The target executable
TARGET = sfml-app

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
