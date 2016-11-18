#include <iostream>
#include <cstdlib>
#include <bitset>
#include <string>
#include <sstream>
#include "AES.h"
#pragma once

#define TAM 16
#define N 4
//#define R 10
//#define S 16

using namespace std;

class CBC
{
    private:
    
    bitset<8>*  plain_text;             //Texto plano
    bitset<8>*  cifrated_text;          //Texto cifrado
    bitset<8>*  plain_text_2;           //Siguiente texto plano
    bitset<8>*  inic_vector;            //Vector con el que se inicializa
    
    int pos(int i, int j, int k);
    
    public:
    
    CBC(void);                          //Constructor
    ~CBC(void);                         //Destructor
    
    void generate(void);                //Metodo que usa el modo CBC
    //void write(void);
};
