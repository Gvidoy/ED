//
//  Pila_maxmin_VD.cpp
//  Pila_maxmin_VD
//
//  Created by Gregorio Vidoy on 7/11/16.
//  Copyright © 2016 Gregorio Vidoy Fajardo. All rights reserved.
//

#include "Pila_maxmin_VD.h"
#include <cassert>
#include <stdio.h>
typedef int T;


elemento Pila_maxmin::tope()const{
    elemento aux = (*this).datos[datos.size()-1];
    return aux;
}


bool Pila_maxmin::vacia()const{
    return (*this).datos.Vacio();
}

void Pila_maxmin::poner( T &v){
    elemento aux;

    aux.ele = v;
    
    if(datos.size() == 0){
        aux.maximo = v;
        aux.minimo = v;
    }else{
        if(datos[datos.size()-1].maximo < v){
            aux.maximo = v;
            aux.minimo = datos[datos.size()-1].minimo;
        }else{
            aux.maximo = datos[datos.size()-1].maximo;
            if(datos[datos.size()-1].minimo >= v){
                aux.minimo = v;
            }else{
                aux.minimo = datos[datos.size()-1].minimo;
            }
        }
    }
    /*
    cout << "Elemento= " << aux.ele << endl;
    cout << "Maximo= " << aux.maximo << endl;
    cout << "Minimo= " << aux.minimo << endl;
    */
    datos.push_back(aux);
    
}

void Pila_maxmin::quitar(){
    assert (datos.size() > 0);
    datos.pop_back();
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
