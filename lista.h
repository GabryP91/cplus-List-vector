#ifndef _lista
#define _lista

#include <iostream>
#include <assert.h>
using namespace std;

typedef int posizione;

template <class T>
class Lista{
public:
       Lista();
       Lista(int);
      ~Lista();
     
     typedef T tipoelem;
     //funzione per creare lista
     void CreaLista();
     //funzione per sapere se lista è vuota
     bool ListaVuota() const;
     //funzione per la lettura di una posizione della lista
     tipoelem LeggiLista(posizione) const;
     //funzione per la scrittura di una elemento in una poszione della lista
     void ScriviLista(tipoelem,posizione);
      //funzione per la lettura del primo valore della lista
     posizione PrimoLista() const;
     //funzione per la lettura del successivo valore della lista
     posizione SuccLista(posizione) const;
     //funzione per la lettura del precedente valore della lista
     posizione PrecLista(posizione) const;
     //funzione per la scrittura di una elemento in una poszione della lista(vesrione 2)
     void InsLista(tipoelem,posizione);
     //funzione per la cancellazione di una una poszione della lista
     void CancLista(posizione);
     //funzione per la stampa della lista completa
     void StampaLista();
     //funzione per sapere se lista è finita passando una posizione
     bool FineLista(posizione) const;

     //rendere questa funzione friend      
     void stampaLista();

private:
        int lunghezza;
        int primo_lista;
        tipoelem *VETTORE;
        int MAX_DIM; 
};


#endif
