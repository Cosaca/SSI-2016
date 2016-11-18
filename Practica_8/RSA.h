#include <iostream>
#include <cstdlib>
#include <cstring>
#pragma once

using namespace std;

const char ABC[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','Y','Z'};

class RSA
{
    private:
    
    long p;              //Numero primo (privado)
    long q;              //Numero primo (privado)
    long n;              //Resultado de p*q
    long d;              //Entero primo con fi(n)
    long fi;             //Resultado de (p-1)*(q-1)
    long e;              //Inverso de modulo fi(n)
    long block_;         //Tamaño del bloque a analizar
    long* mens_decimal;  //Mensaje pasado a decimal
    long* solucion_;     //Variable en la que guardo la solucion
    string mensaje_;     //Mensaje original
    
    public:
    
    RSA(long P, long Q, long D, string mensaje);          //Constructor
    ~RSA(void);                                           //Destructor
    
    int exponenciacion_rapida(long alpha, long x, long m);        //Metodo que realiza exp. rapida
    bool lehman_peralta(long primo);                              //Test de primalidad
    int euclides_ext(long a, long b);                             //Algoritmo de euclides extendido
    string no_espacio(string m);                                  //Metodo que quita espacios
    void cifrado(void);                                           //Metodo que realiza el cifrado
    void descifrado(void);                                        //Metodo que realiza el descifrado
};