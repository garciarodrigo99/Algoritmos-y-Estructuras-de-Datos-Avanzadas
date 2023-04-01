# Macros

MAIN = main/
MAIN_FILE = $(MAIN)main.cpp
#SRC = src/Key/Derivated_class/
#DNI = $(SRC)DNI/dni.cpp
OUT = bin/
OUT_FILE = $(OUT)p5

# Reglas explícitas

default:
	g++ -std=c++14 -g -Wall $(MAIN_FILE) -o $(OUT_FILE)

manual:
	$(OUT_FILE)

file:
	$(OUT_FILE) $(IN_FILE)

run: manual

run-file: default file

#g++ -std=c++14 -g -Wall -o bin/main main/main.cpp src/Key/Derivated_class/DNI/dni.cpp src/Key/Derivated_class/Matricula/matricula.cpp