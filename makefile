CC = g++
CFLAGS = -Wall -Wextra -pedantic -std=c++11
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

all: sfml-app

sfml-app: testScreen.o 
	$(CC) $^ -o $@ $(LDFLAGS)

test.o: testScreen.cpp Screen.cpp 
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o sfml-app

run: sfml-app
	./sfml-app

.PHONY: all clean run
