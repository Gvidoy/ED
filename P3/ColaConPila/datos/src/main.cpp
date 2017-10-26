//
//  main.cpp
//  Pila_maxmin_VD
//
//  Created by Gregorio Vidoy on 7/11/16.
//  Copyright © 2016 Gregorio Vidoy Fajardo. All rights reserved.
//

#include <iostream>
#include "VD.h"

using namespace std;

int main(int argc, const char * argv[]) {
 
    VectorDinamico <int> vd;
    //VectorDinamico vd;
  
   
    int datos = 21;
    
    for (int i = 0; i < datos; i++){
        vd.push_back(i);
    }
    
    for (int i = 0; i < datos; i++){
        cout << "el vector tiene" << vd[i] << endl;

    }
    
    
    
    cout <<  "size " << vd.size() << endl;
    
    cout << "capacidad " << vd.Capacidad() << endl;
    
    for (int i = 0; i < 7; i++){
        vd.pop_back();
    }
    
    cout <<  "size " << vd.size() << endl;
    
    cout << "capacidad " << vd.Capacidad() << endl;
    
    
    return 0;
}
