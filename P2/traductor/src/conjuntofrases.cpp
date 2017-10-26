//
//  conjuntofrases.cpp
//  EDP2VectorSTL
//
//  Created by Gregorio Vidoy on 11/2016.
//  Copyright © 2016 Gregorio Vidoy Fajardo. All rights reserved.
//

#include "conjuntofrases.h"

// Constructor sin argumentos:
// Crea una lista vacia.
ConjuntoFrases :: ConjuntoFrases (void){
}

bool ConjuntoFrases :: Esta(string origen){
    bool esta = false;

    
    for(int i = 0; i < (traducciones.size()) && !esta; i++){        
        if(to_lower(traducciones[i].GetOrigen()) == to_lower(origen)){
            esta = true;
        }
    }
    return esta;
}

//Metodo anadir origen, destino 
void ConjuntoFrases :: Aniade(string origen, string destino){
        Frase auxFrase(origen, destino);
        (*this).Aniade(auxFrase);
}

//Metodo anadir frase
void ConjuntoFrases :: Aniade(Frase frase){
    
    bool esta = false;
    int pos = -1;
    
    for(int i = 0; i < (traducciones.size()) && !esta; i++){
        
       if(traducciones[i].GetOrigen() == frase.GetOrigen()){
            esta = true;
            pos = i;
        }
    }
    if(!esta){
        traducciones.push_back(frase);
    }else{
        for(int i = 0; i < frase.GetDestino().size();i++){
            traducciones[pos].anadirDestino(frase.GetDestino()[i]);
        }
    }
}

// Borra la posicion que contiene el dato

void ConjuntoFrases :: EliminaFrase (string origen){
    for(int i = 0; i < traducciones.size(); i++){
        if(traducciones[i].GetOrigen() == origen){
            traducciones.erase(traducciones.begin()+i);
        }
    }
}
//Elimina una traduccion de la frase

void ConjuntoFrases :: EliminaTraduccion (string origen, string destino){
    for(int i = 0; i < traducciones.size(); i++){
        if(traducciones[i].GetOrigen() == origen){
            traducciones[i].eliminaDestino(destino);        }
    }
}

//size

int ConjuntoFrases :: Size(){
    return traducciones.size();
}

Frase ConjuntoFrases :: GetTraducciones(string origen){
    Frase aux;
    for(int i = 0; i < traducciones.size(); i++){
        if(to_lower(traducciones[i].GetOrigen()) == to_lower(origen)){
            aux = traducciones[i];
        }
    }
    return aux;
}

ConjuntoFrases ConjuntoFrases :: Contenga(string c){
    ConjuntoFrases CFsub;
    for(int i = 0; i < traducciones.size();i++){
        if(to_lower(traducciones[i].GetOrigen()).find(to_lower(c)) != string::npos){
            CFsub.Aniade(traducciones[i]);
        }
    }
    
    return CFsub;
}

ostream& operator<< (ostream &os, ConjuntoFrases cf) {

    for(int i = 0; i < cf.Size(); i++){
        os << "Frase " << i+1 << " "<< cf.traducciones[i].GetOrigen() << endl;
        for(int j = 0; j < cf.traducciones[i].GetDestino().size();j++){
            os << "Traduccion " << j+1  << " " << cf.traducciones[i].GetDestino()[j] << endl;
        }
        os << "------------------------------------" << endl;
        os << "------------------------------------" << endl;

    }

    
    return os;
}

istream& operator>>(istream& is, ConjuntoFrases &cf){
    
    string aux;
    int pos;

    //Mientras que no sea fin de archivo
    while (!is.eof()){
        
        string origen;
        string destino;

        getline (is,aux);
        pos = aux.find(";");
        origen = aux.substr(0,pos);
        destino = aux.substr(pos+1);

        Frase fraseAux;
        fraseAux.modOrigen(origen);

        //trato la frase por si en una traduccion hay varias separadas por ";"
        if(destino.find(";") != string::npos){
            int desde = 0;
            int hasta = 0;
            
            for (int i = 0; i < destino.size(); i++){
                hasta = i;
                if(destino[i] == ';'){
                    fraseAux.anadirDestino(destino.substr(desde,hasta));
                    desde = i+1;
                }
            }
            //meto el ultimo
            fraseAux.anadirDestino(destino.substr(desde,hasta-1));
        }else{
            fraseAux.anadirDestino(destino);
        }
        cf.Aniade(fraseAux);

    }
    

    
    return is;
}

//invariante de la representación    
bool ConjuntoFrases :: invConjuntoDeFrases(){
    bool pasa = true;
    for(int i = 0; i < traducciones.size() && pasa; i++){
        for(int j = i+1; j < traducciones.size() && pasa; j++){
            if(traducciones[i].GetOrigen()== traducciones[j].GetOrigen()){
                pasa = false;
            }
        }
    }
    return pasa;
}


