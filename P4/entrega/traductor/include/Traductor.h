
#ifndef traductor_h
#define traductor_h

#include <stdio.h>
#include "frases.h"
#include <map>

using namespace std;

/**
 *  @brief T.D.A. Traductor
 *
 * Una instancia f del tipo de datos abstracto Traductor es un objeto con un 
 * conjunto de frases, representado por un map de la stl.
 * Que representan, una coleccion de objetos del tipo Frase.
 *
 *
 * Un ejemplo de su uso:
 * Traductor Traductor();
 * @include Traductor.cpp
 *
 * @author Gregorio Vidoy Fajardo
 * @date Octubre 2016
 */

class Traductor{
    
private:
    
    /**
     * @page repTraductor Rep del TDA Traductor.
     *
     * @section invTraductor Invariante de la representación.
     *
     * El invariante es traducciones[0] != traducciones[1] =!.... =! traducciones[n-1]
     *
     * @section faTraductor Función de abstracción.
     *
     * Sea rep un objeto perteneciente al TDA Traductor, entonces un objeto valido:
     * rep.traducciones; 
     * rep.traducciones[0], traducciones[1], ..... rep.traducciones[rep.traducciones.size()-1];
     *
     *
     *
     */
    
    //vector <Frase> traducciones;

    map<string,Frase> traducciones;
    

    
    
public:
    
    /**
     * @brief Constructor por defecto de la clase. Crea un objeto Traductor vacio.
     */
    Traductor();
    
    
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
     *@brief Obtiene las traducciones de una frase que coincide con origen.
     *@param origen de la frase, string.
     *@return Devuelve la vector<string>, [Frase]
     */
    
    vector<string> GetTraducciones(const string origen);
    
    /*
     *@brief Comprueba si existe la Frase que coincide con origen.
     *@param origen de la frase, string.
     *@return Devuelve true si esta, [bool]
     */
    bool Esta(string origen);

    /*
     *@brief Comprueba si existe la Frase que coincide con origen.
     *@param origen de la frase, string.
     *@return Devuelve it a posicion del elemento si esta, sino end()
     */
    map<string,Frase>::iterator find(string origen);

    
    /*
     *@brief Busca crea y retorna un subconjunto que contenga en origen a c
     *@param c parte de origen, string.
     *@return subconjuntoCF, [Traductor].
     */
    Traductor Contenga(string c);
    
    
    /** @brief Imprime por la salida estándar un ConjuntoDeFrases
     @param os Salida del CF.
     @param cf CF a imprimir.
     */
    friend ostream& operator<<(ostream& os, Traductor cf);
    
    /** @brief Carca en memoria un ConjuntoDeFrases.
     @param is Entrada del CF.
     @param cf CF donde se almacena.
     */
    friend istream& operator>>(istream& is, Traductor &cf);
    
    /**
     *@brief Invariante de la representacion de Conjunto de frases, comprueba que no existen. 
     *Frases repetidas en el CF.
     *@return True si cumple el invariante y False si no [bool].
     */
    bool invTraductor();

    /**
    * @brief clase para iterar sobre el traductor
    * */
    class const_iterator{
        private:
            map<string,Frase>::const_iterator it;
        public:
            const_iterator & operator++(){
                it++;
                return(*this);
            }
            const_iterator & operator--(){
                it--;
                return(*this);
            }
            const pair<const string,Frase> &operator *()const{
                return *it;
            }
            bool operator ==(const const_iterator &i)const{
                return i.it==it;
            }      

            bool operator !=(const const_iterator &i)const{
                return i.it!=it;
            }
            friend class Traductor;
            };
            
            /**
             * @brief Inicializa un const_iterator al comienzo del Traductor
             * */
            const_iterator begin()const{
                const_iterator i;
                i.it=traducciones.begin();
                return i;
            }   
            /**
             * @brief Inicializa un const_iterator al final del Traductor
             * */
            const_iterator end()const{
                const_iterator i;
                i.it=traducciones.end();
                return i;
            }  

/*
    class iterator{
        private:
            map<string,Frase>::iterator it;
        public:
            iterator & operator++(){
                it++;
                return(*this);
            }
            iterator & operator--(){
                it--;
                return(*this);
            }
            pair<const string,Frase> &operator *(){
                return *it;
            }
            bool operator ==(const iterator &i){
                return i.it==it;
            }      

            bool operator !=(const iterator &i){
                return i.it!=it;
            }


            friend class Traductor;
            };


            iterator bbegin(){
                iterator i;
                i.it=traducciones.begin();
                return i;
            }   
         
            iterator eend(){
                iterator i;
                i.it=traducciones.end();
                return i;
            }  
*/

    
};


#endif /* Traductor_h */
