# Macros

MAIN = main/
MAIN_FILE = $(MAIN)main.cpp
SRC = src/
BIG = $(SRC)BigInt/
CALC = $(SRC)Calculator/
SRC_FILES = #$(CALC)*.cpp $(BIG)*.cpp
BIN = bin/
EXE_FILE = $(BIN)operations
IN = input/
IN_FILE = $(IN)board.txt


# Reglas explícitas
# g++ -std=c++14 -g -Wall -o bin/main main/main.cc
# g++ $(MAIN_FILE) $(SRC_FILES) -o $(OUT_FILE)
default:
	g++ -std=c++14 -g -Wall -o $(EXE_FILE) $(MAIN_FILE) $(SRC_FILES)

file:
	$(EXE_FILE) $(IN_FILE)

run: 
	file

run-file: 
	default file

clean:
	rm output/*
	rm $(BIN)*

