//
//  frases.cpp
//  EDP2VectorSTL
//
//  Created by Gregorio Vidoy on 11/2016.
//  Copyright © 2016 Gregorio Vidoy Fajardo. All rights reserved.
//

#include "frases.h"
#include <vector>
#include <iostream>

//Constructor por defecto
Frase::Frase(){
    origen = "0";
}

//Constructor con parametros origen y un destino
Frase::Frase(string origen, string destino){
    (*this).origen = origen;
    (*this).destino.push_back(destino);
}

//retorna el valor del destino
string Frase :: GetOrigen(){
    return origen;
}

//retorna el valor de traduciones
vector <string>  Frase::GetDestino(){
    return destino;
}

//acceso y modificacion de origen
void Frase :: modOrigen(string Origen){
    (*this).origen = Origen;
}

//añade un destino string al conjunto de traducciones
void Frase :: anadirDestino(string Destino){
	bool esta = false;
    for(int i = 0; i < destino.size() && !esta; i++){
    	if(destino[i]== Destino){
    		esta = true;
 	   	}
	}
	if(!esta){
		(*this).destino.push_back(Destino);
	}
}

//Elimina un destino del conjunto de traducciones parametro
//destino a eliminar, string
void Frase :: eliminaDestino(string Destino){
    bool sigo = true;
    for(int i = 0; i < (destino.size()) && sigo; i++){
        if(destino[i] == Destino){
            destino.erase(destino.begin()+i);
            sigo = false;
        }
    }
}
//invariante de la representación    
bool Frase :: invFrases(){
    bool pasa = true;
    for(int i = 0; i < destino.size() && pasa; i++){
        for(int j = i+1; j < destino.size() && pasa; j++){
            if(destino[i]== destino[j]){
                pasa = false;
            }
        }
    }
    return pasa;
}
    
//Funcion que devuelve una copia de un string en mayuscula
string to_lower(string cadena)
{
    string aux;

    for(int i = 0; i < cadena.size(); i++)
    {

        aux.push_back(tolower(cadena[i]));
    }
    return aux;
}


