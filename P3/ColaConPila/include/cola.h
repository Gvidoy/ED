/**
 * @file cola.h
 * @brief Fichero cabecera del TDA Cola
 *
 * Gestiona una secuencia de elementos con facilidades para la inserción y
 * borrado de elementos en un extremo
 */

#ifndef __Cola_H__
#define __Cola_H__

#include <cassert>
#include <Pila.h>

/**
 *  @brief T.D.A. Cola
 *
 *
 * Una instancia @e c del tipo de dato abstracto Cola sobre un dominio @e T es
 * una sucesión finita de elementos del mismo con un funcionamiento @e FIFO
 * (First In, First Out}). En una cola, las operaciones de inserción tienen
 * lugar en uno de los extremos, denominado @e final de la cola, mientras que
 * el borrado y consulta se lleva a cabo en el otro extremo, denominado
 * @e frente de la cola. Una cola de longitud @e n la denotamos
 
 * - <a1,a2,a3,..,an<
 
 * En esta cola, tendremos acceso únicamente al elemento del @e Frente,
 * es decir, a @e a1. El borrado o consulta de un elemento será sobre @e a1,
 * mientras que la inserción de un nuevo elemento se hará después de
 * @e an (final de la cola).
 *
 * Si n=0 diremos que la cola está vacía.
 *
 * El espacio requerido para el almacenamiento es O(n), donde n es el número
 * de elementos de la cola.
 * Manteniendo en todo momento el orden de elementos, maximo, minimo, en cada
 * insercion.
 *
 * @author
 * @date
 */

template <class T>
struct elemento{
    T ele; ///<elemento a almacenar
    T maximo; ///<el máximo
    T minimo; ///< el mínimo
};



template <class T>
class Cola{
    
private:
    Pila<elemento <T> > datos;
    
public:
    /**
     * @brief Constructor por defecto
     */
    Cola(){}
    /**
     * @brief Constructor de copias
     * @param original La cola de la que se hará la copia.
     */
    Cola(const Cola<T> & original);
    // ------------------ Destructor ------------------

    // --------------- Otras funciones ---------------
    /**
     * @brief Operador de asignación
     * @param otra La cola que se va a asignar.
     */
    Cola& operator= (const Cola<T> & otra);
    /**
     * @brief Comprueba si la cola está vacía
     */
    bool vacia() const{
        return datos.vacia();
    }
    /**
     * @brief Devuelve el elemento del frente de la cola
     */
    T frente ();

    /**
     * @brief Añade un elemento al final de la cola
     * @param elem Elemento que se va a añadir.
     */
    void poner(const T & elem);
    /**
     * @brief Quita el elemento del frente de la cola
     */
    void quitar();
    /**
     * @brief Devuelve el número de elementos de la cola
     */
    int num_elementos() const{
        return datos.size();
    }
};

#include "cola.cpp"

#endif // __Cola_H__
