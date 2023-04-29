# Macros

MAIN = main/
MAIN_FILE = $(MAIN)main.cpp
TEST_FILE = $(MAIN)test.cpp
OUT = bin/
OUT_FILE = $(OUT)p6
OUT_TEST_FILE = $(OUT)test
OUT_TRACE_FILE = $(OUT)p6_trace

# Reglas explícitas

default:
	g++ -std=c++14 -g -Wall $(MAIN_FILE) -o $(OUT_FILE)

trace:
	g++ -DTRAZA -std=c++14 -g -Wall $(MAIN_FILE) -o $(OUT_TRACE_FILE)

test:
	g++ -std=c++14 -g -Wall $(TEST_FILE) -o $(OUT_TEST_FILE)

run:
	$(OUT_FILE)

run-test:
	$(OUT_TEST_FILE)

run-trace:
	$(OUT_TRACE_FILE)