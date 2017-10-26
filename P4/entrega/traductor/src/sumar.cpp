#include "traductor.h"
#include <fstream>
#include <iostream>
using namespace std;
void SumaTraducciones(const Traductor & t_origen, Traductor & t_destino){
    Traductor::const_iterator it;
    for (it=t_origen.begin(); it!=t_origen.end();++it){
      vector<string>::const_iterator it_d;
      Frase frase;
      frase.modOrigen((*it).first);

      for (it_d=(*it).second.begin(); it_d!=(*it).second.end();++it_d){
        frase.anadirDestino((*it_d));
      }
      t_destino.Aniade(frase);
    }
 
}

void ImprimeTraductor(const Traductor &T,ostream &os){
   Traductor::const_iterator it;
   for (it=T.begin(); it!=T.end();++it){
       os<<(*it).first<<";";
       vector<string>::const_iterator it_d;
       for (it_d=(*it).second.begin(); it_d!=(*it).second.end();++it_d){
	       os<<(*it_d)<<";";
       }
      os<< endl;
   }
}   


int main(int argc, char * argv[]){

  if (argc!=2 && argc!=4){
      cout<<"Ejemplo de uso sumar traducciones1.txt traducciones2.txt resultado.txt"<<endl;
      return 0;
   }

   ifstream f1 (argv[1]);
   if (!f1){
    cout<<"No puedo abrir el primer fichero "<<argv[1]<<endl;
    return 0;
   }
   
   Traductor t_ori1;
   f1>>t_ori1; //Cargamos en memoria, en el traductor.

  ifstream f2 (argv[2]);
   if (!f2){
    cout<<"No puedo abrir el segundo fichero "<<argv[2]<<endl;
    return 0;
   }
   
   Traductor t_ori2;
   f2>>t_ori2; //Cargamos en memoria, en el traductor.
   


   Traductor t_des;
   
   SumaTraducciones(t_ori1,t_des);
   SumaTraducciones(t_ori2,t_des);

  ofstream fout(argv[3]);
     if (!fout){
	     cout<<"No puedo crear el fichero "<<argv[3]<<endl;
	     return 0;
     }else{
      ImprimeTraductor(t_des,fout);
     } 
      
}