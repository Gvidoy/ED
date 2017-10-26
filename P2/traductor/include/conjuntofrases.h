
#ifndef conjuntofrases_h
#define conjuntofrases_h

#include <stdio.h>
#include "frases.h"

using namespace std;

/**
 *  @brief T.D.A. ConjuntoFrases
 *
 * Una instancia f del tipo de datos abstracto ConjuntoFrases es un objeto con un 
 * conjunto de frases, representado por un vector de la stl.
 * Que representan, una coleccion de objetos del tipo Frase.
 *
 *
 * Un ejemplo de su uso:
 * ConjuntoFrases ConjuntoFrases();
 * @include conjuntofrases.cpp
 *
 * @author Gregorio Vidoy Fajardo
 * @date Octubre 2016
 */

class ConjuntoFrases{
    
private:
    
    /**
     * @page repConjuntofrases Rep del TDA ConjuntoFrases.
     *
     * @section invConjuntoFrases Invariante de la representación.
     *
     * El invariante es traducciones[0] != traducciones[1] =!.... =! traducciones[n-1]
     *
     * @section faConjuntoFrases Función de abstracción.
     *
     * Sea rep un objeto perteneciente al TDA ConjuntoFrases, entonces un objeto valido:
     * rep.traducciones; 
     * rep.traducciones[0], traducciones[1], ..... rep.traducciones[rep.traducciones.size()-1];
     *
     *
     *
     */
    
    vector <Frase> traducciones;
    
    
    
public:
    
    /**
     * @brief Constructor por defecto de la clase. Crea un objeto ConjuntoFrases vacio.
     */
    ConjuntoFrases();
    
    
    /**
     * @brief Añade un elemento al conjunto de frases por el final en el caso que no este ya el elemento.
     * @param origen traduccion a añadir, string.
     * @param destino traduccion a añadir, string.
     */
    void Aniade(string origen, string destino);
    
    /**
     * @brief Añade un elemento al conjunto de frases por el final en el caso que no este ya el elemento.
     * @param frase a añadir, Frase.
          */
    void Aniade(Frase frase);
    
    /**
     * @brief Elimina el elemento al conjunto de frases que coincide con origen.
     * @param origen traduccion a eliminar, string.
     */
    void EliminaFrase (string origen);
    
    /**
     * @brief Elimina una traduccion de un elemento de frase que coincide con origen.
     * @param origen de traduccion a eliminar, string.
     * @param destino traduccion a eliminar, string.
     */
    void EliminaTraduccion (string origen, string destino);
    
    /**
     * @brief Obtiene el numero de elementos de la lista.
     * @return Valor numero de elementos de la lista, [int]
     */
    
    int Size();
    
    /*
     *@brief Obtiene la Frase que coincide con origen.
     *@param origen de la frase, string.
     *@return Devuelve la frase, [Frase]
     */
    
    Frase GetTraducciones(string origen);
    
    /*
     *@brief Comprueba si existe la Frase que coincide con origen.
     *@param origen de la frase, string.
     *@return Devuelve true si esta, [bool]
     */
    bool Esta(string origen);
    
    /*
     *@brief Busca crea y retorna un subconjunto que contenga en origen a c
     *@param c parte de origen, string.
     *@return subconjuntoCF, [ConjuntoFrases].
     */
    ConjuntoFrases Contenga(string c);
    
    
    /** @brief Imprime por la salida estándar un ConjuntoDeFrases
     @param os Salida del CF.
     @param cf CF a imprimir.
     */
    friend ostream& operator<<(ostream& os, ConjuntoFrases cf);
    
    /** @brief Carca en memoria un ConjuntoDeFrases.
     @param is Entrada del CF.
     @param cf CF donde se almacena.
     */
    friend istream& operator>>(istream& is, ConjuntoFrases &cf);
    
    /**
     *@brief Invariante de la representacion de Conjunto de frases, comprueba que no existen. 
     *Frases repetidas en el CF.
     *@return True si cumple el invariante y False si no [bool].
     */
    bool invConjuntoDeFrases();


    
};


#endif /* conjuntofrases_h */
