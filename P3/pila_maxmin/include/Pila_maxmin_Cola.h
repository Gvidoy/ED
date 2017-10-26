
//
//  Pila_maxmin_Cola.h
//  Pila_maxmin_Cola
//
//  Created by Gregorio Vidoy on 7/11/16.
//  Copyright © 2016 Gregorio Vidoy Fajardo. All rights reserved.
//

#include "colA.h"
#include <iostream>

#ifndef Pila_maxmin_Cola
#define Pila_maxmin_Cola

/**
 *  @brief T.D.A. Pila_maxmin_Cola
 *
 * Una instancia @e c del tipo de dato abstracto Pila sobre un dominio @e T es
 * una sucesión finita de elementos del mismo con un funcionamiento @e LIFO
 * (Last In, First Out}). En una pila, las operaciones de inserción, borrado y 
 * consulta tienen lugar en uno de los extremos, denominado @e tope de la pila.
 * Una cola de longitud @e n la denotamos
 * - <a1,a2,a3,..,an<
 * 
 *
 * Manteniendo en todo momento el orden de elementos, maximo, minimo, en cada
 * insercion. 
 *
 * @author GREGORIO VIDOY FAJARDO
 * @date NOVIEMBRE 2016
 */

using namespace std;

struct elemento{
    int ele; ///<elemento a almacenar
    int maximo; ///<el máximo
    int minimo; ///< el mínimo
    friend ostream& operator<< (ostream &os,elemento &l){
        os << l.ele << endl;
    return os;
    }
};

typedef int T;

class Pila_maxmin{
    
    private:
    Cola <elemento> datos;
    public:
    /**
     * @brief Devuelve el tope de la Pila
     * @return ultimo elemento insertado en la pila, [element]
     */
    elemento tope()const;
    /**
     * @brief Comprueba si la pila esta vacia
     * @return True, false, [bool]
     */
    bool vacia()const;
    
    /**
     * @brief Inserta un elemento en el tope de la pila
     * @param v elemento a añadir
     */
    void poner(T &v);
    /**
     * @brief Elimina el elemento del tope de la pila
     */
    void quitar();
    
    /**
     * @brief Devuelve el numero de elementos que contiene la pila
     * @return ocupacion de la pila, [int]
     */
    int size()const;
    /** @brief Carga en memoria (Una pila) un conjunto de datos 
     @param is Entrada del flujo.
     @param p Pila_maxmin donde se almacena.
     */
    friend istream& operator>>(istream& is, Pila_maxmin &p);

};

#include "Pila_maxmin_Cola.cpp"

#endif
