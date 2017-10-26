#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <utility>
#include <ctype.h>
#include "refranes.h"
using namespace std;


pair<int,string> Destaparletras ( const string& original, const string& refranJuego, const char& letra );
void ImprimeRefran ( const string& Refran ) ;


string SeleccionRefran ( Refranes refs ) {
  //Obtengo el numero de refranes leido
  int totalRefranes = refs.size();
  Refranes :: iterator it;
  it = refs.begin();

  srand (time(NULL));
  int nReframElegido = rand() % totalRefranes;

  for (int i  = 0; i < nReframElegido; i++)
    ++it;
  
  string resultado = (*it);

  return resultado;
}

void ImprimeRefran ( const string& Refran ) {

  for ( int i = 0 ; i < Refran.size() ; i++ ) 
    cout << " " << Refran[i] << ' ';

  cout << endl;
}



pair<int,string> Ayuda ( const string& original, const string& result ) {

  char letraAocultar = result[0];
  int pos = 0;

  while ( letraAocultar != '_' ) {
      pos++;
      letraAocultar = result[pos];
  }

  letraAocultar = original[pos];

 //cout << " ------ LETRA OCULTA ---- : " << letraAocultar << endl;
  pair<int,string> Resultado;
  Resultado = Destaparletras ( original, result, letraAocultar );

   // cout << "\n CHECK AYUDA :: original =  " << original <<  endl;
    //cout << "\n CHECK AYUDA :: result = " << result << endl;


  if ( Resultado.second == original ) {
    cout << "\n Boot(Ayuda) says: ¡¡¡ ERES UN PAQUETE !!! \n Boot(Ayuda) says: Solo queda una letra por descubrir..." 
         << "\n Boot(Ayuda) says: No querras que te lo destape entero, ¿no? " << endl;
  
    Resultado.first = 0;
    Resultado.second = result;
  }

//cout << "\n CHECK FINAL AYUDA :: Imprimo second :::: " << endl;
 //ImprimeRefran(Resultado.second);

 return Resultado;
}



string TodoMinuscula ( const string &cad ) {

  string caux; 

  for (unsigned char i=0;i<cad.size();++i)
     caux.push_back(tolower(cad[i]));

  return caux;
}



pair<int,string> Destaparletras ( const string& original, const string& refranJuego, const char& letra ) {
  
  string result = refranJuego;
  int cuentaLetras = 0;

  for ( int i = 0 ; i < result.size() ; i++ ) {

    if ( letra == original[i] ) {
      result[i] = original[i];
      cuentaLetras++;
    }
  }
  
  pair<int,string> Resultado(cuentaLetras,result);
  return Resultado;
}




string Ocultarletras ( const string& original, const int& porcentaje ) {

  string result = original;
  int tamano = 0;
  int cont = 0;
  int ocultas = 0;

  // No usamos size, porque queremos el numero de letras (sin espacios)
  for ( int i = 0 ; i < original.size() ; i++ ) 
    if ( original[i] != ' ' )
      tamano++;
  
  ocultas = (tamano*porcentaje)/100;

  while (cont <= ocultas && cont != tamano) {
    bool encontrado = false;   

    char letraAocultar = '_';

    srand (time(NULL));
    int pos = rand() % (tamano + 1);
    letraAocultar = result[pos];
    
    if ( letraAocultar == '_' || letraAocultar == ' ' ) {
      for ( int i = 0 ; i < original.size() && !encontrado ; i++ )
        if ( result[i] != '_' && result[i] != ' ' ) {
          letraAocultar = result[i];
          encontrado = true;
        }    
    }


    for ( int i = 0 ;  i < original.size() ; i++ )

      if ( result[i] == letraAocultar ) {
        result[i] = '_';
        cont++; 
      }     
  }

  return result;
}  



int main ( int argc, char * argv[] ) {

  if (argc!=3 && argc!=2){
      cout<<"Los parametros son:"<<endl;
      cout<<"1.Dime el nombre del fichero los refranes"<<endl;
      cout<<"2.-[Opcional] porcentaje de letras sin ocultar"<<endl;
      return 0;
  }    
  
  ifstream fin(argv[1]);
  if (!fin) {
      cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
      return 0;
  }

  int porcentaje=50;
  if (argc==3)
    porcentaje=atoi(argv[2]);

  Refranes refs(3);
    int rondas = 1;

  fin>>refs;
  string Refran = SeleccionRefran(refs);

  cout << "\n ********************** ... QUE COMIENCE EL JUEGO ...  ********************** " 
       << endl << "\t\t\t\t¡¡¡ ADIVINA !!! \t"
       << endl << " RONDA ["<< rondas << "] " << endl;




  // ESTE NOS VALE
  cout << "\n Ocultando refrán... " << endl << endl;
  string refranOculto = Ocultarletras ( Refran, porcentaje );




  char continuar = 's';
  char letra;
  string eleccion;
  int encontradas = 0;

  while ( continuar == 's' ) {


    ImprimeRefran(refranOculto);
    //.ignore();
    cout << "\n Pulsa 0 para obtener ayuda" << endl;
    cout << " Dime un caracter (o el refran para resolver): ";


    //cin >> eleccion;

    getline(cin,eleccion);



    eleccion = TodoMinuscula(eleccion);
    //cout << "\n ELECCIONN ?? ::: " << eleccion;
    if ( eleccion.size() == 1 ) {
          
      pair<int,string> destapa;
      letra = eleccion[0];

      if ( letra != '0' ) { 
        destapa = Destaparletras(Refran, refranOculto, letra);
        if ( destapa.second == refranOculto ) {
          destapa.first = 0;
          cout << "\n Boot(Ayuda) says: Letra ya destapada " << endl;
        }
      }
      
      else 
        destapa = Ayuda(Refran, refranOculto);

      refranOculto = destapa.second;
      encontradas = destapa.first;
      cout << "\n Encontradas : " << encontradas << endl;
      
      if ( refranOculto == Refran ) {
        cout << "\n Lo has adivinado: ";
        ImprimeRefran(Refran);
        cout << "\n\n ¿ Quieres seguir jugando [S/N] ? ";
        cin >> continuar;
        cin.ignore();
        continuar = tolower(continuar);

        if ( continuar == 's' ) {
          Refran = SeleccionRefran(refs);
          refranOculto = Ocultarletras ( Refran, porcentaje );
          rondas++;
            cout << "\n ********************** ... QUE COMIENCE EL JUEGO ...  ********************** " 
                 << endl << "\t\t\t\t¡¡¡ ADIVINA !!! \t"
                 << endl << " RONDA ["<< rondas << "] " << endl;
        }
      
      }

    }

    else {
      //eleccion.pop_back();
      //cout << "\n CHECK POP BACK BIEN HECHO?? ::: " << eleccion;
      
      if ( eleccion == Refran ) {
        cout << "\n ¡¡¡¡¡ LO HAS ADIVINADO !!!!! : ";
        ImprimeRefran(Refran);
        cout << "\n\n ¿ Quieres seguir jugando [S/N] ? ";
        cin >> continuar;
        cin.ignore(256,'\n');

        continuar = tolower(continuar);

        if ( continuar == 's' ) {
          Refran = SeleccionRefran(refs);
          refranOculto = Ocultarletras ( Refran, porcentaje );
          rondas++;
          cout << "\n ********************** ... QUE COMIENCE EL JUEGO ...  ********************** " 
                 << endl << "\t\t\t\t¡¡¡ ADIVINA !!! \t"
                 << endl << " RONDA ["<< rondas << "] " << endl;
        }
      }
      else 
        cout << "\n ¡¡¡¡¡¡¡¡¡ MEEEEEECCCCCC !!!!!!!!! EEEEEEERROOOOOORRRRR " << endl;
    }
  }


  return 0;
}  