#include "RC4.h"

int main(void)
{
 system("clear");
 
 int text = 0;
	int key = 0;
	
	cout << "--> Práctica 3: Cifrado RC4" << endl;
	cout << "--> Introduzca los numeros que va a tener la semilla: " << endl;
 cin >> key;
 cout << "--> Introduzca los numeros de elementos del texto original: " << endl;
 cin >> text;
 cout << endl;
    
 RC4 B(key, text);
 B.PRGA();
 B.oper_xor();
 B.write();
 
 RC4 C(key, text);
 C.spritz();
 C.oper_xor();
 C.write();
}