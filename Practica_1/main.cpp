#include "vernam.h"
#include <iostream>
#include <cstdlib>

using namespace std;

int main(void)
{
    vernam A("ATACAR MARTES 23 9:30 HORAS");
    int opcion = 5;
   	
   	do
   	{
   	    cout << endl << "--> Práctica 1: Cifrado de Vernan" << endl;
	    cout << "1. Realizar el cifrado" << endl;
	    cout << "2. Realizar el descifrado" << endl;
	    cout << "0. Cerrar programa" << endl;
	    cout << "--> Introduzca una opción (0-2): ";
	    cin >> opcion;
	
	    switch(opcion)
	    {
	        case 0:
	            exit(0);
	        break;
	        case 1:
	            system("clear");
	            A.cifrado();
	        break;
	        case 2:
	      	    system("clear");
	    	    A.descifrado();
	        break;
	        default:
	      	    system("clear");
	            cout << "--> No es válido" <<endl;
	        break;
	    }
   	}
   	while(opcion != -1);
}