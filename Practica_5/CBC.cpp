#include "CBC.h"

CBC::CBC(void)
{
    plain_text =    new bitset<8>[TAM];
    cifrated_text = new bitset<8>[TAM];
    plain_text_2 =  new bitset<8>[TAM];
    inic_vector =   new bitset<8>[TAM];
    
    unsigned char block_1[TAM] = 
    {
        0xe8, 0xb1, 0x1b, 0xea, 0x4a, 0x65, 0x9a, 0x7e, 0x22, 0x4f, 0x92, 0x4b, 0xda, 0x8d, 0x72, 0x39
    };

    unsigned char block_2[TAM] =
    {
        0xda, 0x47, 0x51, 0x74, 0x9a, 0x1d, 0x45, 0xc9, 0x2b, 0x11, 0x43, 0x22, 0xe5, 0x10, 0x36, 0x65
    };

    for (int i = 0; i < TAM; i++)
    {
        inic_vector[i] = false;
        plain_text_2[i] = block_2[i];
        plain_text[i] = block_1[i];
    }
}

CBC::~CBC(void)
{}

int CBC::pos(int i, int j, int k)
{
    return i*k+j;
}

void CBC::generate(void)
{
    bitset<8> aux[TAM];
    
    for(int i = 0; i < TAM; i++)
    {
        aux[i] = inic_vector[i] ^ plain_text[i];
    }
    
    rijndael A(aux);
    A.encryptionProcess();
    cifrated_text = A.get_cifrado();
    
    int aux_1 = 0;
    cout << endl << "--> Primera matriz del CBC" << endl;
    
    for(int i = 0; i < (TAM/4); i++)
    {
        for(int j = 0; j < (TAM/4); j++)
        {
            cout << hex << cifrated_text[pos(j, i, N)].to_ulong() << " ";
        }
        cout << endl;
    }
    
    for (int i = 0; i < TAM; i++)
    {
        aux[i] = 0; 
        aux[i] = cifrated_text[i] ^ plain_text_2[i];
    }
    
    rijndael B(aux);
    B.encryptionProcess();
    cifrated_text = B.get_cifrado();
    
    cout << endl << "--> Segunda matriz del CBC" << endl;
    
    for (int i = 0; i < (TAM/4); i++)
    {
        for (int j = 0; j < (TAM/4); j++)
        {
            cout << hex << cifrated_text[pos(j, i, N)].to_ulong() << " ";
        }
        cout << endl;
    }
}