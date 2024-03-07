
#include "lista.h"

//-------Implementazione

template <class T>
Lista<T>::Lista()
{
    VETTORE= new tipoelem[100];
    MAX_DIM=100;
    Lista<T>::CreaLista();                 
}

template <class T>
Lista<T>::~Lista()
{
    delete[] VETTORE;                 
}


template <class T>
void Lista<T>::CreaLista(){
  lunghezza=0;
  primo_lista=-1;                    
}

template <class T>
Lista<T>:: Lista(int n){
  VETTORE=new tipoelem[n];
  MAX_DIM=n;
  Lista<T>::CreaLista();          
}

template <class T>
bool Lista<T>::ListaVuota() const {
   bool output=false;
   
   if(lunghezza == 0 && primo_lista == -1)
   output=true;
   else
   output=false;
   
   return output;
}

template <class T>
T Lista<T>::LeggiLista(posizione p) const{

tipoelem e;
//controlla la posizione passata che sia compresa tra la prima e l'ultima
assert((primo_lista <= p)&&(p < MAX_DIM));
//se la poszione è valida allora copi il valore in tale posizione
e = VETTORE[p];

return e;
}

template <class T>
void Lista<T>::ScriviLista(tipoelem e,posizione p){

//controlla la posizione passata che sia compresa tra la prima e l'ultima
   assert((primo_lista <= p) && (p < MAX_DIM));
//se la poszione è valida allora scrivo il valore passato in quella posizione 
   VETTORE[p]=e;
}

template <class T>
posizione Lista<T>::PrimoLista() const{
 
    return primo_lista;
}

template <class T>
posizione Lista<T>::SuccLista(posizione p) const{
          
      posizione succ;
      assert((primo_lista <= p)&&(p <= (primo_lista + lunghezza)));
      succ=p +1;
      return succ;
}

template <class T>
posizione Lista<T>::PrecLista(posizione p) const{
          
     posizione prec;
     assert (((primo_lista+1) <=p ) && (p <= (primo_lista + lunghezza)));
     prec=p-1;
     return prec;          
}

template <class T>
void Lista<T>::InsLista(tipoelem e,posizione p){
     
     bool x;
     tipoelem prov;
     int i;
     
     if(primo_lista<0)
     {
       primo_lista=p;
       VETTORE[p]=e;  
       lunghezza++;
       }
     else
     {
      
      if((primo_lista <=p) && (p<=MAX_DIM))    
      {
        x=FineLista(p+1);
        if(x==true)
        {
        VETTORE[p]=e;                
        lunghezza++;
       }
       else
       { 
         prov = VETTORE[p];
         VETTORE[p]= e;
        
        for(i=p+1;i<lunghezza;i++)
        {
           VETTORE[i]= prov;
           prov=VETTORE[i+1];                         
        }
        lunghezza++;     
       }
      }
      else{
        if((0<=p) && (p<=primo_lista))
        {
         primo_lista=p;
         VETTORE[p]=e;
   
   }
  }
 }
}

template <class T> 
bool Lista<T>::FineLista(posizione p) const{
       bool risp = false;
       posizione x = PrimoLista();

       if(((p+1)-x) == lunghezza )
          risp = true;
       return risp;
}

template <class T>
void Lista<T>::CancLista(posizione p){
        
    tipoelem prov;
    posizione p2;
    int i;
    
    if(p == primo_lista)
    {
      primo_lista = Lista::SuccLista(primo_lista);
      lunghezza--;
    }
   else if (Lista::FineLista(p))
   {
        lunghezza--;
   }     
   else {
    bool esito;      
    do 
     {
       p2 = Lista::SuccLista(p);
       prov = Lista::LeggiLista(p2);
       
       Lista::ScriviLista(prov, p);   
       
       p = Lista::SuccLista(p);
       
       esito = Lista::FineLista(p2);
     } while (!esito);
     
     lunghezza--;    
   }
}

template <class T> 
void Lista<T>::stampaLista() {
  T elem = 0;
  posizione z;
  bool esito = Lista::ListaVuota();
  
  if (!(esito)) {
     z = Lista::PrimoLista();        
     do {
         elem = Lista::LeggiLista(z);
         cout << "Elemento in posizione " << z << " : " << elem << endl; 
         esito = Lista::FineLista(z);
         z = Lista::SuccLista(z);
     } while(!esito);
  } else 
      cout << "La lista e` vuota!" << endl;
         
} 