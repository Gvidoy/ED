//
//  Pila_maxmin_List.cpp
//  Pila_maxmin_List
//
//  Created by Gregorio Vidoy on 7/11/16.
//  Copyright © 2016 Gregorio Vidoy Fajardo. All rights reserved.
//

#include <cassert>
typedef int T;


elemento Pila_maxmin::tope()const{
    Cola<elemento> colaAux = (*this).datos;

    while(colaAux.num_elementos() != 1){
        colaAux.quitar();
    }
    elemento auxTope = colaAux.frente();
    return auxTope;
}


bool Pila_maxmin::vacia()const{
    return datos.vacia();
}

void Pila_maxmin::poner( T &v){


    elemento aux;

    aux.ele = v;
    

    if(datos.num_elementos() == 0){
        aux.maximo = v;
        aux.minimo = v;
    }else{
        elemento auxTope = (*this).tope();
        if(auxTope.maximo < v){
            aux.maximo = v;
            aux.minimo = auxTope.minimo;
        }else{
            aux.maximo = auxTope.maximo;
                if(auxTope.minimo >= v){
                    aux.minimo = v;
                }else{
                    aux.minimo = auxTope.minimo;
                }
        }
    }

  /* 
    cout << "Elemento= " << aux.ele << endl;
    cout << "Maximo= " << aux.maximo << endl;
    cout << "Minimo= " << aux.minimo << endl;
*/


    datos.poner(aux);
    
}

void Pila_maxmin::quitar(){
    assert (datos.num_elementos() > 0);
    Cola<elemento> colaAux = (*this).datos;
    Cola<elemento> colaAuxFinal;

    while(colaAux.num_elementos() != 1){
        colaAuxFinal.poner(colaAux.frente());
        colaAux.quitar();
    }
    (*this).datos = colaAuxFinal;
    
}

int Pila_maxmin::size()const{
    return datos.num_elementos();
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
