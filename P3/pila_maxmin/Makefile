SRC = ./src
INC = ./include
OBJ = ./obj
BIN = ./bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c


all: usopilas_max orden

usopilas_max: $(BIN)/usopilas_max
orden: $(BIN)/orden

# ************* usopilas_max ***********************************   
$(BIN)/usopilas_max: $(OBJ)/usopilas_max.o
	$(CXX) -o $(BIN)/usopilas_max $(OBJ)/usopilas_max.o 
$(OBJ)/usopilas_max.o: $(INC)/Pila_maxmin.h $(SRC)/usopilas_max.cpp
	$(CXX) $(CPPFLAGS)  $(SRC)/usopilas_max.cpp  -o $(OBJ)/usopilas_max.o -I$(INC)/

# *********************** orden ********************************
$(BIN)/orden: $(OBJ)/orden.o 
	$(CXX) -o $(BIN)/orden $(OBJ)/orden.o 
$(OBJ)/orden.o: $(SRC)/orden.cpp $(INC)/Pila_maxmin.h
	$(CXX) $(CPPFLAGS) $(SRC)/orden.cpp -o $(OBJ)/orden.o -I$(INC)/	



# ************* Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile


# ************* Limpieza *************************************
clean :
	@echo "Limpiando y actualizando contenido de los directorios"
	rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : 
	@echo "Limpiando ejecutables y documentacion"
	rm $(BIN)* doc/html*


# ********************* Empaquetamiento *********************
tar: 
	@echo "Empaquetando..."
	tar --exclude "*.tgz" --exclude datos --exclude "*~" -czvf ./Pila_min.tgz ../Pila_min




