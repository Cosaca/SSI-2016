#include "DH.h"
#include <stdlib.h>

int main(void)
{
    system("clear");
    
    DH A(2053,53,17,31);
    DH B(1973,125,21,32);
    
    A.generador();
    B.generador();
    //C.generador();
    
    cout << "--> Práctica 7: Intercambio de claves de Diffie-Hellman" << endl;
    cout << endl << "--> Primer ejemplo: " << A;
    cout << endl << "--> Segundo ejemplo: " << B;
    cout << endl;
    //cout << "Tercer ejemplo: " << C;
}