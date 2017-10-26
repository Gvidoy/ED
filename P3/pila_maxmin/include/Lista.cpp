//Lista.cpp

//#include "Lista.h"

template <class T>
void Lista<T>::Copiar(const Lista<T> &l){
    if (l.cab->sig==0){
        cab=new Celda;
        cab->sig=0;
        
    }else{
            cab = new Celda;
            Celda *p=cab, *q=l.cab;
            while (q->sig != 0){
                p->sig=new Celda;
                p->sig->ele = q->sig->ele;
                p=p->sig;
                q=q->sig;
            }
            p->sig=0;
    }
}

template <class T>
void Lista<T>::Borrar_All(){
    while (cab->sig!=0){
        Celda *aux=cab->sig;
        cab->sig = cab->sig->sig;
        delete aux;
    }
    delete cab;
}

template <class T>
Lista<T>::Lista(){
    cab=new Celda;
    cab->sig=0;
}

template <class T>
Lista<T>::Lista(const Lista<T> &l){
    Copiar(l);
}

template <class T>
Lista<T>::~Lista()
{
    Borrar_All();
}

template <class T>
Lista<T> & Lista<T>::operator=(const Lista<T> &l){
    if (this != &l){
        Borrar_All();
        Copiar(l);
    }
    return *this;
}

template <class T>
void Lista<T>::Insertar(Posicion p, T v){
    Celda *aux=p.punt->sig;
    p.punt->sig=new Celda;
    p.punt->sig->ele=v;
    p.punt->sig->sig=aux;
}

template <class T>
T Lista<T>:: Get(Posicion p)const{
    return (*p);
}

template <class T>
void Lista<T>::Borrar(Posicion p)
{
    assert(p.punt->sig != 0);
    Celda *aux = p.punt->sig;
    p.punt->sig=p.punt->sig->sig;
    delete aux;
}

template <class T>
typename Lista<T>::Posicion Lista<T>::begin()const{

    Posicion p;
    
    p.punt= cab;//cab->sig;
    p.primera = cab;
    
    return p;
     
}
template <class T>
 int Lista<T>::size()const{
    int resul = 0;
    Celda *aux = cab;
    while (aux->sig!=0){
        aux=aux->sig;
        resul++;
    }
     return resul;
 }

template <class T>
typename Lista<T>::Posicion Lista<T>::end()const{
    Posicion p;
    Celda *aux = cab;
    while (aux->sig!=0){
        aux=aux->sig;
    }
    p.punt=aux;
    p.primera=cab;
    return p;
}
