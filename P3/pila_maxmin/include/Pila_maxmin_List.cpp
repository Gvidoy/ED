//
//  Pila_maxmin_List.cpp
//  Pila_maxmin_List
//
//  Created by Gregorio Vidoy on 7/11/16.
//  Copyright © 2016 Gregorio Vidoy Fajardo. All rights reserved.
//

#include "Pila_maxmin_List.h"
#include <cassert>
typedef int T;


elemento Pila_maxmin::tope()const{
    elemento aux = datos.Get(--datos.end());
    return aux;
}


bool Pila_maxmin::vacia()const{
    bool Esvacia = false;
    if(datos.size()== 0){
        Esvacia = true;
    }
    return Esvacia;
}

void Pila_maxmin::poner( T &v){
    elemento aux;

    aux.ele = v;
    

    if(datos.size() == 0){
        aux.maximo = v;
        aux.minimo = v;
    }else{
        if(datos.Get(--datos.end()).maximo < v){
            aux.maximo = v;
            aux.minimo = datos.Get(--datos.end()).minimo;
        }else{
            aux.maximo = datos.Get(--datos.end()).maximo;
                if(datos.Get(--datos.end()).minimo >= v){
                    aux.minimo = v;
                }else{
                    aux.minimo = datos.Get(--datos.end()).minimo;
                }
        }
    }

   /* 
    cout << "Elemento= " << aux.ele << endl;
    cout << "Maximo= " << aux.maximo << endl;
    cout << "Minimo= " << aux.minimo << endl;
    */


    datos.Insertar(datos.end(),aux);
    
}

void Pila_maxmin::quitar(){
    assert (datos.size() > 0);
    datos.Borrar(--datos.end());
}

int Pila_maxmin::size()const{
    return datos.size();
}

istream& operator>>(istream& is, Pila_maxmin &p){
    string aux;
    int n = 0;
    //Mientras que no sea fin de archivo
    while (!is.eof()){
        getline (is,aux);
        //Evito saltos de linea vacios
        if(aux.size() != 0){
            n = stoi(aux);
            p.poner(n);
        }
    } 
    return is;
}
