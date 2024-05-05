CC=g++
CFLAGS=-g -std=c++17 

SRC=$(wildcard src/*.cpp)
DEPS=$(wildcard inc/*.h)
OBJ=$(patsubst src/%.cpp, obj/%.o, $(SRC))


all: main

main: $(OBJ) obj/main.o
	@$(CC) $^ -o $@ $(CFLAGS)
	@echo "Build done successfully"


obj/main.o: main.cpp $(DEPS)
	@$(CC) -c $< -o $@ $(CFLAGS) 

obj/%.o: src/%.cpp $(DEPS) 
	@$(CC) -c $< -o $@ $(CFLAGS)
	@echo "Object file $@ created"

.PHONY: clean

clean:
	rm -f obj/*.o main
