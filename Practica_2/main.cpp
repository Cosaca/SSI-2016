#include "RC4.h"

int main(void)
{
	system("clear");
	
	int text = 0;
	int key = 0;
	
    cout << "--> Práctica 3: Generador RC4" << endl;
	cout << "--> Introduzca los numeros que va a tener la clave: " << endl;
	cin >> key;
   	cout << "--> Introduzca los numeros de elementos del texto a cifrar: " << endl;
    cin >> text;
    cout << endl;
    
    RC4(key, text);
    B.PRGA();
    B.oper_xor();
    B.write();
}