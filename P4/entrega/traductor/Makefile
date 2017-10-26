SRC = ./src/
INC = ./include/
OBJ = ./obj/
BIN = ./bin/
LIB = ./lib/
CXX = g++
CPPFLAGS = -Wall -g -c -std=c++11 -I$(INC) 

all: traductor_inverso pruebatraductor sumar concatenar

traductor_inverso: $(BIN)traductor_inverso
pruebatraductor: $(BIN)pruebatraductor
sumar: $(BIN)sumar	
concatenar: $(BIN)concatenar	

# ************ Compilación de módulos ************
 
$(BIN)traductor_inverso : $(OBJ)traductor_inverso.o $(LIB)traductor.a
	$(CXX) -o $(BIN)traductor_inverso $(OBJ)traductor_inverso.o -I$(INC) $(LIB)traductor.a


$(BIN)pruebatraductor : $(OBJ)pruebatraductor.o $(LIB)traductor.a
	$(CXX) -o $(BIN)pruebatraductor $(OBJ)pruebatraductor.o -I$(INC) $(LIB)traductor.a

$(BIN)sumar : $(OBJ)sumar.o $(LIB)traductor.a
	$(CXX) -o $(BIN)sumar $(OBJ)sumar.o -I$(INC) $(LIB)traductor.a

$(BIN)concatenar : $(OBJ)concatenar.o $(LIB)traductor.a
	$(CXX) -o $(BIN)concatenar $(OBJ)concatenar.o -I$(INC) $(LIB)traductor.a	


$(OBJ)traductor_inverso.o : $(SRC)traductor_inverso.cpp $(OBJ)Traductor.o $(OBJ)frases.o
	$(CXX) $(CPPFLAGS) -o $(OBJ)traductor_inverso.o $(SRC)traductor_inverso.cpp $(OBJ)Traductor.o $(OBJ)frases.o 

$(OBJ)pruebatraductor.o : $(SRC)pruebatraductor.cpp $(OBJ)Traductor.o $(OBJ)frases.o
	$(CXX) $(CPPFLAGS) -o $(OBJ)pruebatraductor.o $(SRC)pruebatraductor.cpp $(OBJ)Traductor.o $(OBJ)frases.o 	

$(OBJ)sumar.o : $(SRC)sumar.cpp $(OBJ)Traductor.o $(OBJ)frases.o
	$(CXX) $(CPPFLAGS) -o $(OBJ)sumar.o $(SRC)sumar.cpp $(OBJ)Traductor.o $(OBJ)frases.o 

$(OBJ)concatenar.o : $(SRC)concatenar.cpp $(OBJ)Traductor.o $(OBJ)frases.o
	$(CXX) $(CPPFLAGS) -o $(OBJ)concatenar.o $(SRC)concatenar.cpp $(OBJ)Traductor.o $(OBJ)frases.o 	

$(LIB)traductor.a : $(OBJ)Traductor.o $(OBJ)frases.o
	ar rvs $(LIB)traductor.a $(OBJ)Traductor.o $(OBJ)frases.o

$(OBJ)frases.o : $(SRC)frases.cpp $(INC)frases.h
	$(CXX) $(CPPFLAGS) -o $(OBJ)frases.o $(SRC)frases.cpp 

$(OBJ)Traductor.o : $(SRC)Traductor.cpp $(OBJ)frases.o
	$(CXX) $(CPPFLAGS) -o $(OBJ)Traductor.o $(SRC)Traductor.cpp $(OBJ)frases.o 
 






# ************ Generación de documentación ******************
documentacion:
	@echo "Generando documentacion de Doxygen..."
	doxygen doc/doxys/Doxyfile

	

# ************ Limpieza ************
clean :
	@echo "Limpiando directorios..."
	rm $(BIN)* $(OBJ)* $(LIB)* $(SRC)*~ $(INC)*~ ./*~
  


mrproper : 
	rm $(BIN)* doc/html/* 


contenido:
	@echo "Borrando contenido de los directorios..."
	rm -f $(BIN)* $(OBJ)* $(LIB)* 



# ************ Creacion ************
install:
	mkdir $(BIN) $(OBJ) $(LIB) 



# ************************* Empaquetado ****************************
# Genera el archivo .tgz de la práctica mediante la linea de comandos
# coge el nombre del directorio como nombre
tar: clean
	@echo "Empaquetando..."
	tar --exclude "*.tgz" --exclude datos --exclude "*~" -zcvf ./traductor.tgz ../traductor 


