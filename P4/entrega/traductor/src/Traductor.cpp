//
//  Traductor.cpp
//  EDP2VectorSTL
//
//  Created by Gregorio Vidoy on 11/2016.
//  Copyright © 2016 Gregorio Vidoy Fajardo. All rights reserved.
//

#include "Traductor.h"

// Constructor sin argumentos:
// Crea una lista vacia.
Traductor :: Traductor (void){
}

bool Traductor :: Esta(string origen){
    bool esta = false;
    bool para = false;

    map<string,Frase>::iterator it;

    it = traducciones.find(origen);

    //Probamos si hay suerte con la busqueda del maps O(log(n))
    if(it != traducciones.end()){
        esta = true;
    }else{
        //Si no hay suerte probamos en mayuscula por si la frase no se a escrito 
        //exactamente igual
        it = traducciones.begin();
        while(it != traducciones.end() && !esta && !para){
            if(to_lower(it->first) == to_lower(origen)){
                esta = true;
            }else if (to_lower(it->first) == to_lower(origen)){
                para = true;
            }
            it++;
        }


    }

    return esta;
}

map<string,Frase>::iterator Traductor :: find(string origen){
    
    map<string,Frase>::iterator it;
  
        
    bool para = false;
    //Probamos si hay suerte con la busqueda del maps O(log(n))
    it = traducciones.find(origen);


    //Si no hay suerte probamos en mayuscula por si la frase no se a escrito 
    //exactamente igual
    it = traducciones.begin();
    while(it != traducciones.end() && !para){
        if(to_lower(it->first) == to_lower(origen)){
            para = true;
        }
        it++;
    }
    

    --it;

    if(para == false){
        it = traducciones.end();
    }

    return it;
}

//Metodo anadir origen, destino 
void Traductor :: Aniade(string origen, string destino){
        Frase auxFrase(origen, destino);
        (*this).Aniade(auxFrase);
}

//Metodo anadir frase
void Traductor :: Aniade(Frase frase){

    map<string,Frase>::iterator it;



    it = traducciones.find(frase.GetOrigen());
    
    if(it == traducciones.end()){
        traducciones[frase.GetOrigen()] = frase;
    }else{
        for(int i = 0; i < frase.GetDestino().size();i++){
            //it->second.anadirDestino(frase.GetDestino()[i]);
        }
    }
    
    
}

// Borra la posicion que contiene el dato

void Traductor :: EliminaFrase (string origen){
    
    map<string,Frase>::iterator it;

    it = traducciones.find(origen);

    if(it != traducciones.end()){
        traducciones.erase(it);
    }

}
//Elimina una traduccion de la frase

void Traductor :: EliminaTraduccion (string origen, string destino){
    
    map<string,Frase>::iterator it;

    it = traducciones.find(origen);

    if(it != traducciones.end()){
        it->second.eliminaDestino(destino);
    }
}

//size

int Traductor :: Size(){
    return traducciones.size();
}

vector<string> Traductor :: GetTraducciones(const string origen){
    vector<string> aux;

    map<string,Frase>::iterator it;

    it = traducciones.find(origen);

    if(it != traducciones.end()){
        aux = it->second.GetDestino();
    }

    return aux;
}

Traductor Traductor :: Contenga(string c){
    Traductor CFsub;
    map<string,Frase>::iterator it;
    
    it = traducciones.begin();

    while(it != traducciones.end()){
        if(to_lower(it->second.GetOrigen()).find(to_lower(c)) != string::npos){
            CFsub.Aniade(it->second);
        }
        it++;
    }

    return CFsub;
}

ostream& operator<< (ostream &os, Traductor cf) {

    map<string,Frase>::iterator it;
    
    it = cf.traducciones.begin();

    int i  = 0;

    while(it != cf.traducciones.end()){
        os << "Frase " << i+1 << " "<< it->second.GetOrigen() << endl;
        for(int j = 0; j < it->second.GetDestino().size();j++){
            os << "Traduccion " << j+1  << " " <<it->second.GetDestino()[j] << endl;
        }
        os << "------------------------------------" << endl;
        os << "------------------------------------" << endl;

        it++;
        i++;
    }

    return os;
}

istream& operator>>(istream& is, Traductor &cf){
    
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
        //Elimino espacios al principio
        while(origen[0] == 32){
            origen.erase(0,1);
        }
        //Pongo la primera letra en mayuscula
        origen[0] = toupper(origen[0]);

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
            destino = destino.substr(desde,hasta-1);

            //meto el ultimo
            fraseAux.anadirDestino(destino);
        }else{
            fraseAux.anadirDestino(destino);
        }
        cf.Aniade(fraseAux);

    }
    

    
    return is;
}

//invariante de la representación    
bool Traductor :: invTraductor(){
    bool pasa = true;
    
    map<string,Frase>::iterator it;
    map<string,Frase>::iterator itSig;
    
    it = traducciones.begin();
    itSig = traducciones.begin();
    itSig++;

    while(it != traducciones.end() && pasa){
        while(itSig != traducciones.end()){
            if(it->second.GetOrigen()== itSig->second.GetOrigen()){
                pasa = false;
            }
            itSig++;
        }
        it++;
        itSig = it;
        itSig ++;
    }

    return pasa;
}


