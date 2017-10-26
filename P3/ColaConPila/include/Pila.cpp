//
//  Pila_maxmin_List.cpp
//  Pila_maxmin_List
//
//  Created by Gregorio Vidoy on 7/11/16.
//  Copyright © 2016 Gregorio Vidoy Fajardo. All rights reserved.
//


#include <cassert>

template <class T>
void Pila<T> :: Copiar (const Pila &P) {
    if (P.datos == 0){
        datos = 0;
    }else {
        datos = new Celda<T>;
        datos->d = P.datos->d;
        Celda<T> *p = datos;
        Celda<T> *q = P.datos->sig;
        while (q != 0) {
            p->sig = new Celda<T>;
            p = p->sig;
            p->d = q->d;
            q = q->sig;
        }
        p->sig = 0; }
}


template <class T>
void Pila<T>::Borrar() {
    while (datos != 0) {
        Celda<T> *aux = datos;
        datos = datos->sig;
        delete aux;
    } 
}

template <class T>
T Pila<T> :: tope () const {
    assert (datos != 0);
    return datos->d;
}


template <class T>
void Pila<T>::poner (const T &v) {
    Celda<T> *aux = new Celda<T>;
    aux->d = v;
    if (datos == 0) {
        datos = aux;
        datos->sig=0;
    }
    else {
        aux->sig=datos;
        datos=aux; 
    }
}


template <class T>
void Pila<T> :: quitar () {
    assert (datos != 0);
    Celda<T> *aux = datos;
    datos = datos->sig;
    delete aux;
}

template <class T>
int Pila<T>::size()const{
    int cont = 0;
    Pila aux;
    aux = (*this);

    while(aux.datos != 0){
        aux.quitar();
        cont++;
    }
    return cont;
}

template <class T>
Pila<T> Pila<T>::operator= (const Pila<T> &P){
    (*this).Copiar(P);
    return *this;
}

