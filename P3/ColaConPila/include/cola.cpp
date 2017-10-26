/**
 * @file cola.cpp
 * @brief Implementación del TDA Cola
 *
 */
#include <cassert>
// #include <cola.h>  El codigo ya se incluye en cola.h
/* _________________________________________________________________________ */


template <class T>
Cola<T>::Cola(const Cola<T> & original){
    datos = original;
}

/* _________________________________________________________________________ */


/* _________________________________________________________________________ */

template <class T>
Cola<T>& Cola<T>::operator=(const Cola<T> & otra){

    (*this).datos = otra.datos;

    return *this; //Devolvemos el objeto para permitir el encadenamiento (a=b=c)
}

template <class T>
T Cola<T>::frente (){
    assert(datos.size()!=0);             //Si la cola está vacía, abortar

    Pila<elemento <T> > pilaAux = (*this).datos;
    T auxele;

    //saco hasta el primer elemento insertado
    while(pilaAux.size() != 1){
        pilaAux.quitar();
    }

    T auxele = pilaAux.tope().ele;

    return auxele;
}


/*_________________________________________________________________________ */

template <class T>
void Cola<T>::poner(const T & elem){

    elemento<T> aux;

    aux.ele = elem;
    

    if(datos.size() == 0){
        aux.maximo = elem;
        aux.minimo = elem;
    }else{
        elemento<T> auxTope = datos.tope();
        if(auxTope.maximo < elem){
            aux.maximo = elem;
            aux.minimo = auxTope.minimo;
        }else{
            aux.maximo = auxTope.maximo;
                if(auxTope.minimo >= elem){
                    aux.minimo = elem;
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

/* _________________________________________________________________________ */

template <class T>
void Cola<T>::quitar(){
    assert(datos.size()!=0);             //Si la cola está vacía, abortar

    Pila<elemento <T> > pilaAux = (*this).datos;
    Pila<elemento <T> > pilaAux2;
    Pila<elemento <T> > pilaAuxFinal;

        //saco hasta el primer elemento insertado
        while(pilaAux.size() != 1){
            pilaAux2.poner(pilaAux.tope());
            pilaAux.quitar();
        }

        //Recostruyo la pila
        while(pilaAux2.size() != 0){
            pilaAuxFinal.poner(pilaAux2.tope());
            pilaAux2.quitar();
        }

    (*this).datos = pilaAuxFinal;



}
