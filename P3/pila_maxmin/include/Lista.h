/**
 * @file Lista.h
 * @brief Fichero cabecera del TDA Lista
 *
 * Gestiona una secuencia de elementos con facilidades para la inserción y
 * borrado de elementos
 */

//Lista.h
#ifndef __LISTA_H
#define __LISTA_H

#include <cassert>


/**
 *  @brief T.D.A. Lista
 *
 *
 * Una instancia @e c del tipo de dato abstracto Lista sobre un dominio @e T es
 * una sucesión finita de elementos del mismo . 
 * 

 *
 * @author GREGORIO VIDOY FAJARDO
 * @date NOVIEMBRE 2016
 */





template <class T>
class Lista {
    private:
        struct Celda
        {
            T ele;
            Celda *sig;
        };
public:
    class Posicion {
        private:
            Celda *punt;
            Celda *primera;
        public:
            Posicion(): punt(0), primera(0) {
            }
            
            /**
            * @brief Operador de comparacion
            * @param op la lista a comparar
            * @return true/false [bool]
            */
            bool operator== (const Posicion &op) {
                return punt==op.punt;
            }

            /**
            * @brief Operador de desigualdad
            * @param op la lista a comparar
            * @return true/false [bool]
            */
            bool operator!= (const Posicion &op) {
                return punt!=op.punt;
            }
            /**
            * @brief Operador de pos incremento
            */
            Posicion & operator++(){
                assert(punt!=0);
                punt=punt->sig;
                return *this;
            }
            /**
            * @brief Operador de pos decremento
            */
            Posicion & operator--(){
                if (primera==punt){
                    punt=0;
                }else{
                    Celda *q = primera;
                    while (q->sig!=punt){
                        q=q->sig;
                    }
                    punt=q;
                }
                return *this;
            }

            /**
            @brief Operador de indirección. Devuelve el elemento al que hace referencia posicion
            *@return Elemento al cual hace referencia posicion.
            */
            T & operator*() {
                return punt->sig->ele;
            }
        
            friend class Lista;
        
    };

    private:
        Celda *cab;
        /**
        * @brief Copia una lista en otra
        * @param L lista a copiar
        */
        void Copiar (const Lista &L);

        /**
        * @brief Libera la memoria
        */
        void Borrar_All();
    public:
        /**
         * @brief Constructor por defecto
         */
        Lista();
        /**
         * @brief Constructor de copias
         * @param l La Lista de la que se hará la copia.
         */
        Lista(const Lista &l);
        
        /**
        * @brief Destructor
        */
        ~Lista();

        /**
        * @brief Operador de asignación
        * @param otra La lista que se va a asignar.
        */
        Lista & operator=(const Lista &l);

        /**
        * @brief Añade un elemento en la posicion indicada
        * @param p Posicion donde ubicarlo
        * @param v Elemento que se va a añadir.
        */
        void Insertar (Posicion p, T v);

        /**
        * @brief Elimina un elemento en la posicion indicada
        * @param p Posicion a eliminar
        */
        void Borrar (Posicion p);

        /**
        * @brief Devuelve el elemento que se encuentra en la posicion indicada
        * @param p Posicion del elemento a devolver
        */
        T Get(Posicion p)const;

        /**
        * @brief Modifica un elemento en la posicion indicada
        * @param p Posicion donde ubicarlo
        * @param v Elemento que se va a modificar.
        * @return contenido de la posicion, [T].
        */
        void Set(Posicion p, T v);
        
        /**
        * @brief Devuelve el numero de elementos que hay en la lista
        * @return tamaño de la lista, [int]
        */
        int size()const;

        /**
        * @brief Devuelve puntero apuntando al primer nodo de la lista
        * @return posicion inicial de la lista, [Posicion]
        */
        Posicion begin()const;

        /**
        * @brief Devuelve puntero  al final de la lista
        * @return posicion final de la lista, [Posicion]
        */
        Posicion end()const;
    };
    
#include "Lista.cpp"
    
    #endif
