
#ifndef frases_h
#define frases_h

#include <stdio.h>
#include <vector>
#include <iostream>
#include <utility>

using namespace std;

/**
 *  @brief T.D.A. Frase.
 *
 * Una instancia f del tipo de datos abstracto f Frase es un objeto con una frase,
 * compuestos por dos valores string y el dato abstracto,
 * destino representado por un vector de la stl.
 * Que representan, respectivamente, frase original y sus traducciones.
 *
 *
 * Un ejemplo de su uso:
 * Frase frase();
 * @include frase.cpp
 *
 * @author Gregorio Vidoy Fajardo
 * @date Octubre 2016
 */



class Frase {
    
private:
    /**
     * @page repFrase Rep del TDA Frase.
     *
     * @section invFrase Invariante de la representación.
     *
     * El invariante es destino[0] != destino[1] =!.... =! destino[n-1]
     *
     * @section faFrase Función de abstracción.
     *
     * Sea rep un objeto perteneciente al TDA Frase, entonces un objeto valido:
     * rep.origen; rep.destino[0], repdestino[1], ..... rep.destino[rep.destino.size()-1];
     *
     *
     *
     */
    

    pair<string,vector<string>> datos;

    
    
public:
    
    
    
    /**
     * @brief Constructor por defecto de la clase. Crea un objeto Frase vacio.
     */
    Frase();
    
    /**
     *@brief Constructor por parametros de la clase. Crea un objeto Frase con origen y destino
     *@param origen de la frase, string.
     *@param destino asociado a la frase, string.
     */
    Frase(string origen, string destino);
    
    
    /** @brief Obtiene el origen de la frase
     *@return origen, [string].
     */
    string GetOrigen();
    
    /** @brief Obtiene el/los destinos de la frase
     *@return Traduccion destino/s, [vector<string>]
     */
    vector <string> GetDestino();
    
    /** @brief Modifica el origen de la frase.
     *@param origen de la frase, string
     */
    void modOrigen(string Origen);
    
    /** @brief Añade un destino si no existe, de la frase.
     *@param un destino de la frase, string
     */
    void anadirDestino(string Destino);
    
    /** @brief Elimina un destino si existe, de la frase
     *@param un destino a eliminar de la frase, string
     */
    void eliminaDestino(string Destino);
     
    /**
     *@brief invariante de la representacion Frases, comprueba que no existen 
     *destinos repetidos;
     *@return True si cumple el invariante y False si no [bool].
     */
    bool invFrases();

    /**
     * @brief clase para iterar sobre las traduciones
     * */
    class const_iterator{
        private:
            vector<string>::const_iterator it;
        public:
            const_iterator & operator++(){
                it++;
                return(*this);
            }
            const_iterator & operator--(){
                it--;
                return(*this);
            }
            const string &operator *()const{
                return *it;
            }
            bool operator ==(const const_iterator &i)const{
                return i.it==it;
            }      

            bool operator !=(const const_iterator &i)const{
                return i.it!=it;
            }
        friend class Frase;
    };

    /**
     * @brief Inicializa un iterator al comienzo de las traducciones
     * */
    vector<string>::const_iterator begin()const{
        const_iterator i;
        i.it=datos.second.begin();
        return i.it;
    }   
    /**
     * @brief Inicializa un iterator al final de las traducciones
     * */
    vector<string>::const_iterator end()const{
        const_iterator i;
        i.it=datos.second.end();
        return i.it;
    }  

};
    /**
     * @page Funciones externas.
     * Función que ayuda a la comparación de string 
     * Para el apoyo de funciones como buscar o esta.
     */

    /** @brief Obtiene una copia del string en mayuscula para comparar, 
    *no modifica el original.
    *@param cadena a transformar, string
    *@return copia de cadena en mayuscula, [string].
    */
    string to_lower(string cadena);


#endif /* frases_h */
