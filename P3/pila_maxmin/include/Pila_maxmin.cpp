//Pila_maxmin.cpp
#include “Pila_maxmin.h”
#if CUAL_COMPILA==1
#include <Pila_maxmin_VD.cpp> 
#elif CUAL_COMPILA==2 
#include <Pila_maxmin_List.cpp> 
#else
#include <Pila_maxmin_Cola.cpp> 
#endif