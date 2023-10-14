CC = g++
CFLAGS = -Wall -Wextra -pedantic -std=c++11
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system
VALGRIND = valgrind

# Flag to compile using valgrind
VALGRIND_FLAGS = --leak-check=full --show-reachable=yes
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
	rm -f $(OBJECTS)

run: $(TARGET)
	./$(TARGET)

valgrind: $(TARGET)
	$(VALGRIND) $(VALGRIND_FLAGS) ./$(TARGET)

.PHONY: all clean run
