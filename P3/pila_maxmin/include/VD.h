//
//  VD.h
//  Pila_maxmin_VD
//
//  Created by Gregorio Vidoy on 7/11/16.
//  Copyright © 2016 Gregorio Vidoy Fajardo. All rights reserved.
//

#ifndef VD_h
#define VD_h

/**
 *  @brief T.D.A. VD
 *
 *
 * Una instancia @e c del tipo de dato abstracto VD sobre un dominio @e T es
 * una sucesión finita de elementos del mismo . 

 *
 * @author GREGORIO VIDOY FAJARDO
 * @date NOVIEMBRE 2016
 */
#define NULO 0

///////////////////////////////////////////////////////////////

template <class T>
class VD
{
private:
    T * datos;	// Dirección de memoria donde se
    // almacenan los datos.
    int   tam;			// Número de casillas reservadas.
    int   usados;		// Número de casillas usadas.
    
    // Capacidad inicial, por defecto
    static const int TAM_DEF = 10;
    
public:
    
    /**
     * @brief Constructor por defecto
     */
    VD (void);
    
    /**
     * @brief Constructor con par·metros
     * @param tam_inicial Tamaño inicial
     * @param valor_inicial Valor inicial
     */
    VD (int tam_inicial, T valor_inicial=NULO);
    
    /**
     * @brief Constructor con par·metros
     * @param otro Otro vector a copiar
     */

    VD (const VD<T> & otro);
    
    /**
     * @brief Destructor
     */
    ~VD(void);
    
    /**
     * @brief Comprueba si el vector esta vacio 
     * @return True, false, [bool]
     */
    bool Vacio (void)const;
    
    /**
     * @brief Devuelve el numero maximo de casillas disponibles
     * @return capacidad del vector, [int]
     */
    int Capacidad (void);
    

    /**
     * @brief Devuelve el numero de casillas ocupadas
     * @return ocupacion del vector, [int]
     */
    int size(void)const;
    
    /**
     * @brief Inserta un elemento al vector dinamico (al final)
     * @param valor elemento a añadir
     */
    void push_back (T valor);
    
    /**
     * @brief Elimina el ultimo elemento del vector     
     */
    void pop_back ();
    
    /**
     * @brief Metodo de acceso individual a elementos
     * Metodo de escritura
     * @pre 0 <= posicion < size()
     * @param posicion, posicion de vector a acceder
     */
    T & operator [] (const int posicion);
    /**
     * @brief Metodo de acceso individual a elementos
     * Metodo de lectura
     * @pre 0 <= posicion < size()
     * @param posicion, posicion de vector a acceder
     */
    T & operator [] (const int posicion)const;
    
    /**
     * @brief Operador de asignacion
     * @param otro, otro vector a asignar
     */
    VD & operator = (const VD<T> & otro);
  
    

    
private:
    
    /**
     * @brief Pedir memoria para alojar "casillas" datos
     * @param num_casillas, cantidad de memoria a solicitar
     */
    void PedirMemoria (int num_casillas);
    
    /**
     * @brief Liberar la memoria ocupada
     */
    void LiberarMemoria (void);
    
    /**
     * @brief Copiar datos
     * @param otro, otro vector a copiar
     */
    void CopiarDatos (const VD<T> & otro);
    
    /**
     * @brief Inicializa el vector con un elemento determinado
     * @param valor_inicial, elemento a inicializar
     */
    void Inicializar (T valor_inicial=NULO);

    /**
     * @brief Redimensiona el vector dinámico
     * @param n, nuevo tamaño del vector
     */
    void RedimensionaAlmacen (int n);
    
    
    
};

#include "VD.cpp"


#endif /* VD_h */
