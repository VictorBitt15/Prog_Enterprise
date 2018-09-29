CC = g++

BIN = ./bin
OBJ = ./build
INC = ./include
SRC = ./src

PROG = $(BIN)/empresa

CPPFLAGS = -Wall -pedantic -std=c++11 -I$(INC)

OBJS = $(OBJ)/empresa.o $(OBJ)/funcionario.o $(OBJ)/sindicato.o $(OBJ)/main.o

all: mkdirs $(PROG)

mkdirs:
	mkdir -p $(BIN)
	mkdir -p $(OBJ)

$(PROG): $(OBJS)
	$(CC) $(CPPFLAGS) -o $(PROG) $(OBJS)

$(OBJ)/empresa.o: $(SRC)/empresa.cpp $(INC)/empresa.h $(OBJ)/funcionario.o
	$(CC) $(CPPFLAGS) -c $(SRC)/empresa.cpp -o $(OBJ)/empresa.o

$(OBJ)/funcionario.o: $(SRC)/funcionario.cpp $(INC)/funcionario.h
	$(CC) $(CPPFLAGS) -c $(SRC)/funcionario.cpp -o $(OBJ)/funcionario.o

$(OBJ)/sindicato.o: $(SRC)/sindicato.cpp $(INC)/sindicato.h $(OBJ)/empresa.o $(OBJ)/funcionario.o
	$(CC) $(CPPFLAGS) -c $(SRC)/sindicato.cpp -o $(OBJ)/sindicato.o

$(OBJ)/main.o: $(SRC)/main.cpp $(OBJ)/funcionario.o $(OBJ)/empresa.o $(OBJ)/sindicato.o
	$(CC) $(CPPFLAGS) -c $(SRC)/main.cpp -o $(OBJ)/main.o

clean:
	rm -f $(BIN)/*
	rm -f $(OBJ)/*
