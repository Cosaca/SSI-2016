#include <iostream>
#include <cmath>
#pragma once

using namespace std;

class DH
{
    private:
    
    long    n_;         //Valor que almacena  
    long    p_;         //Valor que almacena p
    long    alpha_;     //Valor que almacena α
    long    K_;         //Valor que almacena ki
    long*   X_;         //Valor que almacena xi
    long*   Y_;         //Valor que almacena yi
    
    public:
    
    DH(void);                                       //Constructor por defecto
    DH(long p, long alpha, long num, long* x);      //Constructor
    ~DH(void);                                      //Destructor
    
    bool primo(long primo);                                 //Metodo que comprueba si p es primo
    int exponenciacion_rapida(long alph, long x, long m);   //Metodo que realiza la exponenciacion rapida
    void generador(void);                                   //Metodo que genera los valores intermedios
    void write(void);                                       //Metodo que formatea el resultado
};
    