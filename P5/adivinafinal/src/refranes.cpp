
#include "refranes.h"
#include <vector>
//#include <iostream>


//-------------------------------------------------//
//--------------FUNCIONES PUBLICAS-----------------//
//-------------------------------------------------//

//Constructor por defecto
    Refranes :: Refranes () {
        ab.AsignaRaiz("");      
        len_prefijo = 3;
        n_ref = 0;
        caracteres_totales = 0;
    }


//Constructor por parametros. Inicia len_prefijo a un valor 
    Refranes :: Refranes ( int lpre ) {
        ab.AsignaRaiz(""); 
        len_prefijo = lpre;
        n_ref = 0;
        caracteres_totales = 0;
    }

//devuelve el numero de refranes alamacenados
    int Refranes :: size () const {
        return n_ref;
    }

//Inserta un refran en el conjunto
    void Refranes :: Insertar ( const string &refran ) {
        
        ArbolGeneral<string> :: iter_preorden itAPUNTA = ab.begin();
        ArbolGeneral<string> :: iter_preorden itUltimoEncontrado = ab.begin();
        bool bandera = false;

        if ( ab.Size() == 1 ) { // Primer caso, arbol vacio
            for ( int i = 0 ; i < len_prefijo ; i++ ) {
                string refranAUX;
                refranAUX.push_back(refran[i]);
                ArbolGeneral<string> aux(refranAUX);
                ab.Insertar_hijoMasIzquierda(itAPUNTA.GetNodo(),aux);
                ++itAPUNTA;
            }

            string resto = refran.substr(len_prefijo,refran.size()-1);
            ArbolGeneral<string> aux2(resto);
            ab.Insertar_hijoMasIzquierda(itAPUNTA.GetNodo(),aux2);
            
            n_ref++;    
        }

        else if ( !Esta(refran).first ){ // arbol con algo

            bandera = true;

            for ( int i = 0 ; i < len_prefijo ; i++ ) {
                bool encontrado = false; // bandera para salir del while
                string refranAUX;
                refranAUX.push_back(refran[i]);

                ArbolGeneral<string> :: iter_preorden itRECORRE = ab.begin();
                
                //Buscamos si esta
                while ( itRECORRE != ab.end() && !encontrado ) {
                    //Si es nivel 0 y no esta no compruebo padres
                    if ( (*itRECORRE) == refranAUX && itRECORRE.getLevel() == i && i == 0  ){
                        encontrado = true;
                        itUltimoEncontrado = itRECORRE;
                        itAPUNTA = itUltimoEncontrado; 
                    }
                    //Si no es el nivel 0 compruebo todos los padres no justo el antetior sino todos hasta el nivel 0
                    else if( (*itRECORRE) == refranAUX && itRECORRE.getLevel() == i && i != 0  ){
                        string letrasAnt;
                        letrasAnt = refran.substr(0,i);
                        string letrasPadre;
                        
                        //Cojo las letras de los padres
                        ArbolGeneral<string> :: Nodo Naux = itRECORRE.GetNodo();

                        while ( Naux->padre != 0 ) {
                            //string auxiliar = Naux->etiqueta;
                            string auxiliar = Naux->padre->etiqueta;
                            letrasPadre.insert(0, auxiliar);
                            Naux = Naux->padre;
                        }
                        //cout << "--------letraPadre = " << letrasPadre << " ---letrasAnt= " << letrasAnt << endl;
                        if(letrasPadre == letrasAnt ){
                            //cout << " ENCONTRADOOO --------letraPadre = " << letrasPadre << " ---letrasAnt= " << letrasAnt << endl;
                            encontrado = true;
                            itUltimoEncontrado = itRECORRE;
                            itAPUNTA = itUltimoEncontrado; 
                        }
                    }

                    ++itRECORRE;
                }
                
                //Si no lo encuentra lo inserto apartir del ultimo encontrado
                if ( !encontrado ) {
                    ArbolGeneral<string> aux(refranAUX);
                    ab.Insertar_hijoMasIzquierda(itUltimoEncontrado.GetNodo(),aux);
                    ++itUltimoEncontrado;
                    itAPUNTA = itUltimoEncontrado; 
                }
            }
            //Pego lo que me quede despues del prefijo
            if ( bandera == true ) {
                string resto = refran.substr(len_prefijo,refran.size()-1);
                ArbolGeneral<string> aux2(resto);
                ab.Insertar_hijoMasIzquierda(itAPUNTA.GetNodo(),aux2);
            }
            n_ref++;
        }
    }

    void Refranes :: BorrarRefran (const string &refran) {
        
        iterator LocalizaRefran = begin(); 
        iterator FIN = end();
        bool SITUADO = false;
        
        // Localizamos el refran
        while ( LocalizaRefran != FIN && !SITUADO ) {
            
            if ( (*LocalizaRefran) == refran )
                SITUADO = true;
            else
                ++LocalizaRefran;
        }
        // Al salir, LocalizaRefran apunta a la hoja donde termina refran. Empezamos a subir

        if ( SITUADO ) { // TEMA QUE QUEMA
        
            ArbolGeneral<string> :: Nodo actual = LocalizaRefran.it.GetNodo();
            ArbolGeneral<string> AlaHoguera; // aqui se almacena la morralla
            bool FIN = false;
            
            
            //int contadorPRUEBA = 0;
            while ( actual->padre != 0 && !FIN ) {
                
                //cout << " ENTRO PRIMER WHILE ::::: " << endl;
                string MiFinEtiqueta = actual->etiqueta;                
                //mi_cadena.insert(0, auxiliar);
                
                actual = actual->padre; // me posiciono en mi padre
                
                if ( actual->izqda->etiqueta == MiFinEtiqueta ) { // soy yo el hijo izquierda
                    //cout << " PRIMERA PODA ??? " << MiFinEtiqueta << endl;
                    ab.Podar_hijoMasIzquierda(actual, AlaHoguera);
                    //cout << " PRIMERA PODA :: ETIQUETA ??? " /*<< actual->izqda->etiqueta*/ << endl;
                    if ( actual->izqda != 0 ) { // hemos terminado, lo que queda forma parte de otro refran
                        FIN = true;
                        //cout << " FIIIIIINNNN !!! ------------------ " << endl;
                    }
                } // HASTA AQUI BIEN
                else { // soy alguno de los hermanos derecha, tengo que encontrarme
                    ArbolGeneral<string> :: Nodo hijoDerecho = actual->izqda; // es el "begin" del while
                    bool finDERECHA = false;
                    
                    while ( /*hijoDerecho->drcha != 0  &&*/ !finDERECHA ) {
                        
                        //cout << " INICIO segundo WHILE " << endl;
                        
                        if ( hijoDerecho->drcha->etiqueta == MiFinEtiqueta ) {
                           // cout << " SEGUNDA PODA ??? " << MiFinEtiqueta << endl;
                            //actual = hijoDerecho;
                            ab.Podar_hermanoDerecha(hijoDerecho, AlaHoguera);
                           
                        //else
                            finDERECHA = true;
                        }
                        hijoDerecho = hijoDerecho->drcha;
                        //cout << " SALGO segundo WHILE ------ " << endl;
                    }
                    //cout << " FIN ELSE FINAL !!!!! " << endl; 
                   // actual = actual->izqda;
                    FIN = true;
                }
                //cout << " SALGO PRIMER WHILE ------ " << endl;
            }
            n_ref--;
        }


    }


//Devuelve si un refran esta en el conjunto. Si esta devuelve un iterador a el
    pair<bool, Refranes :: iterator> Refranes :: Esta (const string &refran) {
        
        size_t sizeT = -1;
        bool bandera = false;
        iterator it = end();
        pair<bool, iterator> aux(bandera,it);
        

        for ( it = begin() ; it != end() && !bandera ; ++it )
            if ( (*it).find(refran) != sizeT ) {
                bandera = true;
                aux.first = bandera;
                aux.second = it;
            }

        return aux; 

    }

//Elimina todos los refranes
    void Refranes :: clear () {
        ab.Clear();
        len_prefijo = 0;
        n_ref = 0;
        caracteres_totales = 0;
    }



//--------------------------------------------------//
//--------------FUNCIONES AMIGAS--------------------//
//--------------------------------------------------//

//Lectura/Escritura de un conjunto de refranes
    istream& operator>> (istream &is, Refranes &R) {

        while(!is.eof()){
            string refran;
            getline(is,refran);
            
            if (refran[refran.size()-1] == ' ')
                refran.pop_back();
            
            R.Insertar(refran);
        }
        return is;
    }

    ostream & operator<<(ostream &os, Refranes &R){
            
       Refranes :: iterator itrr; 
       itrr = R.begin();

        while ( itrr != R.end() ) {
            os << (*itrr) << endl;
            ++itrr;
        }

        return os;
    }

//Devuelve el numero total de los caracteres en todos los refranes    
    int Refranes :: Caracteres_Refranes () {
        
        int contador = 0;

        iterator it = begin();
        iterator itF = end(); 

        while ( it != itF ) { 
            contador += (*it).size(); 
            ++it;
        }
        
        return contador;
    }


//Devuelve el numero de caracteres usados
    int Refranes :: Caracteres_Almacenados () {
        
        int contador = 0;

        ArbolGeneral<string> :: iter_preorden it = ab.begin();
        ArbolGeneral<string> :: iter_preorden itF = ab.end(); 

        while ( it != itF ) { 
            contador += (*it).size(); 
            ++it;
        }
        contador--; // para no contar la raiz
        
        return contador; 
    }

//Numero de nodos necesarios para la configuración
    int Refranes :: Numero_Nodos () const {
        return ab.Size(); 
    }

//-------------------------------------------------//
//------------- FUNCIONES iterador ----------------//
//-------------------------------------------------//       

    string& Refranes :: iterator :: operator* () {
            string mi_cadena = "";
            
            if ( it.GetNodo() != 0 ) {
                ArbolGeneral<string> :: Nodo aux = it.GetNodo();
                while ( aux->padre != 0 ) {
                    string auxiliar = aux->etiqueta;
                    mi_cadena.insert(0, auxiliar);
                    aux = aux->padre;
                }
                cad = mi_cadena;
            }
        return cad; // llama al operador* del arbol que a su vez llama a la etiqueta del nodo. que en este caso es un string, el refran en cuestion
    }

    bool Refranes :: iterator :: operator== ( const iterator &i ) const {
        return it == i.it && cad == i.cad;        
    }
    bool Refranes :: iterator :: operator!= ( const iterator &i ) const {
        return it != i.it; 
    }

    Refranes :: iterator & Refranes :: iterator :: operator ++ () {

        if ( it.GetNodo() != 0 ) {
            ++it;
            if ( it.GetNodo() != 0 ) {

                while ( !it.Hoja() ){ 
                    ++it;
                }
            }     
        }

        return *this;
    }

//-------------------------------------------------//
//------------- FUNCIONES const_iterator ----------//
//-------------------------------------------------//   
    Refranes :: const_iterator :: const_iterator (){
        cad="";
    }
    Refranes :: const_iterator :: const_iterator (const iterator  &i) {
        it = i.it;
        cad = i.cad;
    }
    string & Refranes::const_iterator::operator *(){
        return cad;
    }
    bool Refranes::const_iterator::operator==(const const_iterator &i)const{
        return it == i.it && cad == i.cad; 
    }
    bool Refranes::const_iterator::operator!= ( const const_iterator &i ) const {
        return it != i.it; 
    }
    Refranes :: const_iterator & Refranes :: const_iterator :: operator ++() { 
        return *this;
    }



//-------------------------------------------------//
//------------- BEGIN y END -----------------------//
//-------------------------------------------------//

   Refranes :: iterator Refranes :: begin () {

        iterator itb;
        ArbolGeneral<string> :: iter_preorden it;
        it = ab.begin();

        while ( !it.Hoja() ) {
            //itb.cad+=(*it);
            ++it;
        }
        //itb.cad+=(*it);
        itb.it = it;
        return itb;
    }
    
    Refranes :: iterator Refranes :: end () {
        iterator ite;
        ite.it = ab.end();
        ite.cad = "";
        return ite;
    }
      
    Refranes :: const_iterator Refranes :: Cbegin () const {
        const_iterator itb;
        ArbolGeneral<string> :: const_iter_preorden it;
        it = ab.cbegin();

        while ( !it.Hoja() ) {
            //itb.cad+=(*it);
            ++it;
        }
        //itb.cad+=(*it);
        itb.it = it;
        return itb;
    }
    
    Refranes :: const_iterator Refranes :: Cend () const {
        const_iterator ite;
        ite.it = ab.cend();
        return ite;
    }

   //Funcion de prueba para pintar el arbol
    void Refranes :: pinta () const {

        ArbolGeneral<string> :: const_iter_preorden it = ab.cbegin();
        ArbolGeneral<string> :: const_iter_preorden itF = ab.cend(); 

        while ( it != itF ) { 
            cout << (*it) << " EN NIVEL = " << it.getLevel() << endl;
            ++it;
        }
        
        
}
