#include <iostream>
#include <cmath>
#pragma once

using namespace std;

class DH
{
    private:
        
    int p_;             //Valor primo de p
    int alpha_;         //Valor almacenado en α
    int Ka_;            //Valor almacenado en ka
    int Kb_;            //Valor almacenado en kb
    int Xa_;            //Valor almacenado en xa
    int Xb_;            //Valor almacenado en xb
    int Ya_;            //Valor almacenado en ya
    int Yb_;            //Valor almacenado en yb
        
    public:
        
    DH(void);                                   //Constructor
    DH(int p, int alpha, int xa, int xb);
    ~DH(void);                                  //Destructor
        
    int get_p(void);        //Metodos que obtienen los valores de los atributos
    int get_alpha(void);
    int get_ka(void);
    int get_kb(void);
    int get_xa(void);
    int get_xb(void);
    int get_ya(void);
    int get_yb(void);
        
    bool primo(int primo);                                  //Metodo que calcula si p es primo
    int exponenciacion_rapida(int alp, int x, int m);       //Metodo que realiza la exponenciacion rapida
    void generador(void);                                   //Metodo que genera los numeros intermedios
        
    friend ostream& operator<<(ostream& os, DH&);           //Metodo que imprime los valores
};