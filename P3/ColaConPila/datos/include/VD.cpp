//
//  VD.cpp
//  Pila_maxmin_VD
//
//  Created by Gregorio Vidoy on 7/11/16.
//  Copyright © 2016 Gregorio Vidoy Fajardo. All rights reserved.
//

//#include "VD.h"
#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;


// Constructor sin argumentos
template <class T>
VectorDinamico <T>::VectorDinamico (void) :
tam (TAM_DEF), usados (0)
{
    // Reservar memoria
    PedirMemoria (tam);
}

// Constructor con uno/dos argumentos
template <class T>
VectorDinamico<T>::VectorDinamico (int tam_inicial,
                                  T valor_inicial) :
tam (tam_inicial), usados (0)
{
    // Reservar memoria
    PedirMemoria (tam);
    // Inicializar el vector dinámico
    Inicializar (valor_inicial);
}

// Constructor de copia
template <class T>
VectorDinamico <T>:: VectorDinamico (const VectorDinamico<T> & otro)
{
    // Reservar memoria
    PedirMemoria (otro.tam);
    // Copiar desde "otro"
    CopiarDatos (otro);
}

// Destructor
template <class T>
VectorDinamico <T>:: ~VectorDinamico(void)
{
    LiberarMemoria ();
}

// Devuelve el estado (vacio/ocupado) del vector
template <class T>
bool VectorDinamico <T>:: Vacio (void)
{
    return ((usados==0) ? true : false);
}

// Devuelve el numero maximo de casillas disponibles
template <class T>
int VectorDinamico <T>:: Capacidad (void)
{
    return (tam);
}

// Devuelve el numero de casillas ocupadas
template <class T>
int VectorDinamico <T>:: size(void)
{
    return (usados);
}

// push_back un elemento al vector dinamico (al final)
// PRE: usados < tam
template <class T>
void VectorDinamico <T>:: push_back (T valor)
{
    // Comprobar si es necesario redimensionar el almacén
    
    if (size() == Capacidad()) {
        
        // Redimensionar
        RedimensionaAlmacen (tam);
    }
    
    datos [usados] = valor;
    usados++;
}

//Elimina el ultimo elemento del vector
template <class T>
void VectorDinamico <T>:: pop_back (){
    usados--;
    
    if (size() <= (Capacidad()/3)) {
        
        // Redimensionar
        RedimensionaAlmacen (-(tam/2));
    }
}


// Metodo de acceso individual a elementos
// Metodo de lectura
// PRE: 0 <= posicion < size()
template <class T>
T & VectorDinamico <T>::  operator [] (const int posicion)
{
    return (datos [posicion]);
}


// Operador de asignacion
template <class T>
VectorDinamico<T> & VectorDinamico <T>:: operator = (const VectorDinamico <T>& otro)
{
    if (this != &otro) // Importantisimo: evitar autoasignacion
    {
        LiberarMemoria ();			// Liberar memoria reservada
        PedirMemoria (otro.tam);	// Pide memoria
        CopiarDatos (otro);
    }
    return (*this); // devuelve el objeto implicito:
    // parte izquierda de la asignación
}






//**********************************************
// METODOS PRIVADOS
//**********************************************

// Pedir memoria para alojar "casillas" datos
template <class T>
void VectorDinamico <T>:: PedirMemoria (int num_casillas)
{
    datos = 0;
    if (num_casillas > 0)
        datos = new T[num_casillas];
}

// Liberar la memoria ocupada
template <class T>
void VectorDinamico <T>:: LiberarMemoria (void)
{
    if (datos)
        delete [] datos;
}

// Copiar datos
template <class T>
void VectorDinamico <T>:: CopiarDatos (const VectorDinamico & otro)
{
    // Datos privados de "otro"
    tam = otro.tam;
    usados = otro.usados;
    memcpy (datos, otro.datos, otro.usados*sizeof(T));
}

// Inicializar el vector a un valor común
template <class T>
void VectorDinamico <T>:: Inicializar (T valor_inicial)
{
    for (int i=0; i<tam; i++)
        datos[i] = valor_inicial;
}

// Redimensiona el vector dinámico de acuerdo al
// tipo de redimensión establecido.
// Copia todos los datos en el nuevo almacén.
template <class T>
void VectorDinamico <T>:: RedimensionaAlmacen (int n)
{

    tam = tam + n;
    
    // Pedir memoria para el nuevo almacen
    T * tmp = new T[tam];
    
    // Copiar los datos de manera eficiente:
    memcpy (tmp, datos, usados*sizeof(T));

    
    // Liberar la memoria del antiguo almacén
    delete [] datos; 
    
    datos = tmp; // Reasignacion
}


