#include <cstdio>
#include <iostream>
#include <bitset>
#include <cstdlib>

using namespace std;

class vernam
{
    private:
    
    int size_original_bin_;
    bitset<8>* original_bin_;
    bitset<8>* key_bin_;
    bitset<8>* solution_;
    string original_;
    string key_;
    
    public:
    
    vernam(string original);
    ~vernam(void);
    void cadena_binario_o(string original);
    void cadena_binario_m(string original_A);
    void random(int tam);
    void cifrado(void);
    void descifrado(void);
    friend ostream& operator <<(ostream& os, const vernam& A);
};
