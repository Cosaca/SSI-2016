#include "AES.h"
#include "CBC.h"

int main (void)
{
    rijndael A;
    
    cout << "--> Práctica 5: Implementación del Algoritmo Rijndael" << endl;
    cout << endl;
    
    A.encryptionProcess();
    CBC B;
    B.generate();
}