# Macros

MAIN = main/
MAIN_FILE = $(MAIN)main.cpp
TEST_FILE = $(MAIN)test.cpp
OUT = bin/
OUT_FILE = $(OUT)p6
OUT_TEST_FILE = $(OUT)test

# Reglas explícitas

default:
	g++ -std=c++14 -g -Wall $(MAIN_FILE) -o $(OUT_FILE)

test:
	g++ -std=c++14 -g -Wall $(TEST_FILE) -o $(OUT_TEST_FILE)

run:
	$(OUT_FILE)

file:
	$(OUT_FILE) $(IN_FILE)

run-file: default file

run-test:
	$(OUT_TEST_FILE)