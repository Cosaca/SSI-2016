#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include "RSA.h"

using namespace std;

int main(void)
{
    system("clear");
    cout << "--> Practica 8: Cifrado RSA" << endl << endl;  
    RSA A(229, 199, 9347, "CORRIGIENDO RSA");
    A.cifrado();
    A.descifrado();
    cout << endl;
}