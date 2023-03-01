# Macros

MAIN = main/
MAIN_FILE = $(MAIN)main.cpp
SRC = src/
BIG = $(SRC)BigInt/
CALC = $(SRC)Calculator/
SRC_FILES = $(BIG)Base_Class/Number.cpp
BIN = bin/
EXE_FILE = $(BIN)operations
IN = input/
IN_FILE = $(IN)board.txt
OUT = output/

# Reglas explícitas
# g++ -std=c++14 -g -Wall -o bin/main main/main.cc
# g++ $(MAIN_FILE) $(SRC_FILES) -o $(OUT_FILE)
default:
#	g++ -std=c++17 -g -Wall -o $(EXE_FILE) $(MAIN_FILE) $(SRC_FILES)
	g++ -std=c++14 -g -Wall $(MAIN_FILE) $(SRC_FILES) -o $(EXE_FILE)

file:
	$(EXE_FILE) $(IN_FILE)
#	$(eval RECENT_FILE := $(shell ls "$(OUT)" -1rt | tail -n1))
#	@cat $(OUT)$(RECENT_FILE)

run: 
	$(EXE_FILE) $(IN_FILE)

run-file: 
	make default file

clean:
	rm $(BIN)*
	rm $(OUT)*

