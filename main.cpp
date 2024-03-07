#include <cstdlib>
#include <iostream>
#include "lista.cpp"
using namespace std;

int main(int argc, char *argv[])
{
    Lista<int> l1;
    Lista<char> l2;
    Lista<float> l3;
    
    bool esito1 = l1.ListaVuota();

    bool esito2 = l2.ListaVuota();

    cout << "Subito dopo la creazione la lista e` vuota? " << endl;

    if(esito1 == 1){
        cout << "no"<< endl;
        l1.InsLista(10, 1);
        l1.InsLista(3,2);
        l1.InsLista(9,3);
        l1.InsLista(5,4);
    }

    if(esito2 == 1){
        cout << "no"<< endl;
        l2.InsLista('c', 1);
        l2.InsLista('i',2);
        l2.InsLista('a',3);
        l2.InsLista('o',4);
    }
 
     
   l1.stampaLista();
   l1.CancLista(2);
   cout << endl<< "Lista due"<< endl;
   l2.stampaLista(); 

    system("PAUSE");
    return EXIT_SUCCESS;
}
