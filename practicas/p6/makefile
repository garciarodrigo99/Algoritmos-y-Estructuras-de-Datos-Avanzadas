# Macros

MAIN = main/
MAIN_FILE = $(MAIN)main.cpp
TESTAVL_FILE = $(MAIN)testAVL.cpp
OUT = bin/
OUT_FILE = $(OUT)p6
OUT_TESTAVL_FILE = $(OUT)testAVL
OUT_TRACE_FILE = $(OUT)p6_trace

# Reglas explícitas

default:
	g++ -std=c++14 -g -Wall $(MAIN_FILE) -o $(OUT_FILE)

trace:
	g++ -DTRAZA -std=c++14 -g -Wall $(MAIN_FILE) -o $(OUT_TRACE_FILE)

testAVL:
	g++ -DTRAZA -std=c++14 -g -Wall $(TESTAVL_FILE) -o $(OUT_TESTAVL_FILE)

run:
	$(OUT_FILE)

run-testAVL:
	$(OUT_TEST_FILE)

run-trace:
	$(OUT_TRACE_FILE)