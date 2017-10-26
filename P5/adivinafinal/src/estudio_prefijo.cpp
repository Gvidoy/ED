
/**
 * @file:   estudio_prefijo.cpp
 * @author: Gregorio Vidoy Fajardo y Jesus Ruiz Castellano
 *
 * @date: 18 de enero de 2017, 18:15
 */

#include <cstdlib>
#include "refranes.h"

using namespace std;

/**
 * @brief Metodo para imprimir la cabecera de la tabla  
 */
void cabeceraTabla(ostream &os){
   
        //Prefijo
    os << "Prefijo" << ";"
        //Car.Total
        << "Car.Total" << ";"
        //Car.Arb    
        << "Car.Arb " << ";"
        //%Red    
        << "%Red" << ";"
        //# Nodos    
        << "#Nodos " << ";"
        //%Red/#Nodos    
        << "%Red/#Nodos" << ";"
        << "\n";     
}


/**
 * @brief Metodo para imprimir la cabecera de la tabla  
 */
void sacarDatosRefranes( Refranes &ref, ostream &os){
   
    double red = 100.0 - ((ref.Caracteres_Almacenados()*100.0)/ref.Caracteres_Refranes());
        //Prefijo
    os << ref.getLen_prefijo() << ";"
        //Car.Total
        << ref.Caracteres_Refranes() << ";"
        //Car.Arb    
        << ref.Caracteres_Almacenados() << ";"
        //%Red    
        << red << ";"
        //# Nodos    
        << ref.Numero_Nodos() << ";"
        //%Red/#Nodos    
        << red/ref.Numero_Nodos() << ";" << "\n";         
}


int main(int argc, char** argv) {
    
    if ( argc != 3 ) {
        cout << " Los parametros son : " << endl;
        cout << " 1.- Dime el nombre del fichero los refranes" << endl;
        cout << " 2.- Dime el nombre del fichero CSV de salida {nombreArchivo.csv}" << endl;
        return 0;
    }
        

    ofstream salida(argv[2]);
    if (!salida) {
      cout<<"No puedo crear el fichero de salida "<<argv[2]<<endl;
      return 0;
    }
    
    cabeceraTabla(salida);
    
    for ( int i = 2 ; i <= 14 ; i++ ) {
       
        ifstream fin(argv[1]);
        if (!fin){
            cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
            return 0;
        }

        Refranes refs(i);
        fin >> refs;
        sacarDatosRefranes(refs, salida);
    }

    
    return 0;
}

