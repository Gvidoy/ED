SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c

all: $(BIN)/main


$(BIN)/main: $(OBJ)/main.o
	$(CXX) -o $(BIN)/main $(OBJ)/main.o 
$(OBJ)/main.o: $(INC)/VD.h $(SRC)/main.cpp
	$(CXX) $(CPPFLAGS)  $(SRC)/main.cpp  -o $(OBJ)/main.o -I$(INC)
    

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile


# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
