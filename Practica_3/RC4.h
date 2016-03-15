#include <iomanip>
#include <algorithm>
#include <bitset>
#include <iostream>
#include <cstdlib>
#pragma once

using namespace std;

class RC4
{
    private:
    
    int* K_;            //Clave
    int sz_k_;          //Longitud de la clave
    int* S_;            //Secuencia
    int* M_;            //Texto original
    int sz_m_;          //Longitud del texto original
    int* SEED_;         //Semilla
    bitset<8>* sec_cifrante_;           //Secuencia cifrante en binario
    bitset<8>* text_original_;          //Resultado del texto original en binario
    bitset<8>* text_cifrado_;           //Texto cifrado en binario
    
    public:
    
    RC4(int sz_k, int sz_m);
    ~RC4(void);
    void KSA(void);
    void PRGA(void);
    void to_bin(void);
    void oper_xor(void);
    void write(void);
    void spritz(void);
};