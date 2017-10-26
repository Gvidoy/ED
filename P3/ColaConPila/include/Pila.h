
//
//  Pila.h
//  Pila
//
//  Created by Gregorio Vidoy on 7/11/16.
//  Copyright © 2016 Gregorio Vidoy Fajardo. All rights reserved.
//



#ifndef Pila__
#define Pila__
#include <iostream>
/**
 *  @brief T.D.A. Pila_maxmin_Lista
 * Una instancia @e c del tipo de dato abstracto Pil sobre un dominio @e T es
 * una sucesión finita de elementos del mismo con un funcionamiento @e LIFO
 * (Last In, First Out}). En una pila, las operaciones de inserción, borrado y 
 * consulta tienen lugar en uno de los extremos, denominado @e tope de la pila.
 * Una cola de longitud @e n la denotamos
 * - <a1,a2,a3,..,an<
 * 
 *
 * @author GREGORIO VIDOY FAJARDO
 * @date NOVIEMBRE 2016
 */

using namespace std;


template <class T>
struct Celda {
    T d;
    Celda<T> *sig;
};


template <class T>
class Pila{
    private:
        Celda<T> *datos;

        void Copiar (const Pila<T> &p);
        void Borrar();

    public:

        /**
         * @brief Constructor por defecto
         */
        Pila(){datos = 0;}
        /**
         * @brief Constructor por de copia copia P en (*this)
         * @Param P Lista a copiar
         */
        Pila (const Pila<T> &P) {Copiar (P);}

        /**
         * @brief Constructor por defecto libera la memoria
         */
        ~Pila () {Borrar();}
        /**
         * @brief Operador de asignacion
         * @param P a asignar
         */
        Pila<T> operator= (const Pila<T> &P);
        
        /**
         * @brief Devuelve el tope de la Pila
         * @param P a copiar
         */
        T tope()const;
        /**
         * @brief Comprueba si la pila esta vacia
         * @return True, false, [bool]
         */
        bool vacia()const;
        
        /**
         * @brief Inserta un elemento en el tope de la pila
         * @param v elemento a añadir
         */
        void poner(const T &v);
        /**
         * @brief Elimina el elemento del tope de la pila
         */
        void quitar();
        
        /**
         * @brief Devuelve el numero de elementos que contiene la pila
         * @return ocupacion de la pila, [int]
         */
        int size()const;



        
};

#include "Pila.cpp"

#endif
