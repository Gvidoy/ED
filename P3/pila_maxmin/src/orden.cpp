//
//  main.cpp
//  Pila_maxmin_VD
//
//  Created by Gregorio Vidoy on 7/11/16.
//  Copyright © 2016 Gregorio Vidoy Fajardo. All rights reserved.
//

#include <iostream>
#include "Pila_maxmin.h"
#include <fstream>


using namespace std;

int main(int argc, char * argv[]){
  if (argc!=3){
      cout<<"Los parametros son: <archivo1> <archivo2>"<<endl;
      return 0;
  }    
  
  ifstream fin(argv[1]);
  if (!fin){
      cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
      return 0;
  }

  ifstream fin2(argv[2]);
  if (!fin2){
      cout<<"No puedo abrir el fichero "<<argv[2]<<endl;
      return 0;
  }
  
  Pila_maxmin p;
  Pila_maxmin p2;
  fin >> p;
  fin2 >> p2;
  

  cout << "Primer conjunto ELEMENTO= " << p.tope().ele << " MAXIMO= " <<  p.tope().maximo  << " MINIMO " << p.tope().minimo << endl;  
  


  cout << "Primer conjunto ELEMENTO= " << p2.tope().ele << " MAXIMO= " <<  p2.tope().maximo  << " MINIMO " << p2.tope().minimo << endl;

  if(p.tope().minimo > p2.tope().maximo){
    cout << "El Primer conjunto es mayor que el segundo" << endl;
  }else if(p2.tope().minimo > p.tope().maximo){
    cout << "El Segundo conjunto es mayor que el segundo" << endl;
  }else{
    cout << "No se puede decir que un conjunto sea menor o mayor que otro" << endl;
  }

  if((p.tope().minimo < p2.tope().minimo) && (p.tope().maximo > p2.tope().maximo)){
    cout << "El Segundo conjunto esta contenido en el primer conjunto" << endl;
  }else if ((p2.tope().minimo < p.tope().minimo) && (p2.tope().maximo > p.tope().maximo)){
    cout << "El Primer conjunto esta contenido en el Segundo conjunto" << endl;
  }else{
    cout << "El Primer conjunto NO esta contenido en el Segundo conjunto ni el Segundo en el primero";
    cout << endl;
  }

  cout << "Pila 1" << endl;
  while (!p.vacia() ){
    elemento x = p.tope();
    cout << x<<endl;
    p.quitar();
  }    

  cout << "Pila 2" << endl;
  while (!p2.vacia() ){
    elemento x = p2.tope();
    cout << x<<endl;
    p2.quitar();
  }  

  return 0;
}
