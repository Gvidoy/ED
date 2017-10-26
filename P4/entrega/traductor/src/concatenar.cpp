#include "traductor.h"
#include <fstream>
#include <iostream>
using namespace std;

Traductor::const_iterator buscar(Traductor & t, string origen){
    
    bool para = false;

    Traductor::const_iterator it;
   

    it = t.begin();
    while(it != t.end()&& !para){
        if((*it).first == origen){
            //cout << "encontrado" << endl;
            para = true;
        }
        ++it;
    }
    --it;

    if(para == false){
        it = t.end();
        //cout << "NO" << endl;
    }

    return it;

}


void ConcatenarTraducciones(Traductor & t_origen1,Traductor & t_origen2, Traductor & t_destino){
    Traductor::const_iterator it;
    Traductor::const_iterator it2;

    
    for (it=t_origen1.begin(); it!=t_origen1.end();++it){
      vector<string>::const_iterator it_d;

      for (it_d=(*it).second.begin(); it_d!=(*it).second.end();++it_d){
        //cout << "bucle"<< endl;
        //it2=t_origen2.find((*it_d));
      	it2= buscar(t_origen2,(*it_d));
      	//it2 = t_origen2.end();

        if(it2 != t_origen2.end()){
          //cout << "if"<< endl;	
          Frase frase;
          frase.modOrigen((*it).first);
          vector<string>::const_iterator it_d2;

          for (it_d2=(*it2).second.begin(); it_d2!=(*it2).second.end();++it_d2){
            frase.anadirDestino((*it_d2));
          }
          t_destino.Aniade(frase);
        }
      }
      
   
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
   
   ConcatenarTraducciones(t_ori1,t_ori2,t_des);

  ofstream fout(argv[3]);
     if (!fout){
	     cout<<"No puedo crear el fichero "<<argv[3]<<endl;
	     return 0;
     }else{
      ImprimeTraductor(t_des,fout);
     } 
      
}