#include "DH.h"

int main(void)
{
    long sec = 0;
    cout << "--> Práctica 7: Intercambio de claves de Diffie-Hellman" << endl;
    cout << "--> Introduzca el número de secretos que va a utilizar: " << endl;
    cin >> sec;
    
    long* secreto;
    secreto = new long [sec];
    
    for (long i = 0; i < sec; i++) 
    {
        cout << "--> Introduzca el secreto " << (i + 1) << ": ";
        cin >> secreto[i];
    }
    cout << endl;

    DH A(2053,53,sec,secreto);

    A.generador();
    A.write();
}