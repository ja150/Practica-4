SRC = src
INC = include
OBJ = obj
BIN = bin
LIB = lib

CXX = g++

all: $(BIN)/ejercicio4

$(BIN)/ejercicio4 : $(OBJ)/ejercicio4.o
	$(CXX) -o $(BIN)/ejercicio4 $(OBJ)/ejercicio4.o
$(OBJ)/ejercicio4.o : $(SRC)/ejercicio4.cpp $(SRC)/funciones.cpp
	$(CXX) -c $(SRC)/ejercicio4.cpp -I./$(INC) -o $(OBJ)/ejercicio4.o
