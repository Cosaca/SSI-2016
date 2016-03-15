#include "RC4.h"

using namespace std;

RC4::RC4(int sz_k, int sz_m):       //Constructor
K_(NULL),
S_(NULL),
M_(NULL),
SEED_(NULL),
sz_k_(sz_k),
sz_m_(sz_m),
sec_cifrante_(),
text_original_(),
text_cifrado_()

{
    S_ = new int [256];
    SEED_ = new int [256];
    K_ = new int [sz_k_];
    M_ = new int [sz_m_];
    sec_cifrante_ = new bitset<8> [sz_m_];
    text_original_ = new bitset<8> [sz_m_];
    text_cifrado_ = new bitset<8> [sz_m_];
    KSA();
    to_bin();
}

RC4::~RC4(void)     //Destructor
{}

void RC4::KSA(void)     //Inicializacion
{
    for(int i = 0; i < 256; i++)
    {
        S_[i] = i;
    }
    
    cout << "Entrada" << endl;
    
    for(int i = 0; i < sz_k_; i++)
    {
        cout << "--> Introduzca los elementos de la semilla clave: ";
        cin >> K_[i];
    }
    
    cout << endl;
    
    for(int i = 0; i < sz_m_; i++)
    {
        cout << "--> Introduzca los elementos del texto original: ";
        cin >> M_[i];
    }
    
    cout << endl;
    
    int aux = 0;
    
    for(int i = 0; i < 256; i++)
    {
        SEED_[i] = K_[aux];
        aux++;
        if(aux == sz_k_)
        {
            aux = 0;
        }
    }
    
    int j = 0;
    
    for(int i = 0; i < 256; i++)
    {
        j = (j + S_[i] + SEED_[i]) % 256;
        swap(S_[i], S_[j]);
    }
}

void RC4::PRGA(void)        //Generacion de secuencia cifrante
{
    int i = 0;
    int j = 0;
    int t = 0;
    
    for(int x = 0; x < sz_m_; x++)
    {
        i = (i + 1) % 256;
        j = (j + S_[i]) % 256;
        swap(S_[i], S_[j]);
        t = (S_[i] + S_[j]) % 256;
        
        sec_cifrante_[x] = S_[t];
    }
}

void RC4::to_bin(void)      //Metodo que pasa a binario el mensaje original
{
    for(int i = 0; i < sz_m_; i++)
    {
        text_original_[i] = M_[i];
    }
}

void RC4::oper_xor(void)        //Operacion XOR
{
    for(int i = 0; i < sz_m_; i++)
    {
        text_cifrado_[i] = text_original_[i] ^ sec_cifrante_[i];
    }
}

void RC4::write(void)       //Metodo que imprime el resultado
{
    int aux = 0;
    
    cout << "Salida" << endl;
    cout << "S: " << endl;
    
    for (int i = 0; i <= 255; i++)
    {
        cout << setw(4) << fixed << S_[i] << " ";
        aux++;
        
        if(aux == 16)
        {
            cout << endl;
            aux = 0;
        }
    }
    
    cout << endl << endl;
    cout << "--> Elementos clave: ";
    
    for (int i = 0; i < sz_k_; i++)
    {
        cout << K_[i] << " ";
    }
    cout << endl <<  "--> Elementos a cifrar: ";
    
    for (int i = 0; i < sz_m_; i++)
    {
        cout << M_[i] << " ";
    }
    cout << endl << endl;
    
    for (int i = 0; i < sz_m_; i++)
    {
        cout << "--> Byte " << i+1 << " de secuencia cifrante: " << sec_cifrante_[i] << endl;
        cout << "--> Byte " << i+1 << " de texto original: " << text_original_[i] << endl;
        cout << "--> Byte " << i+1 << " de texto cifrado: " << text_cifrado_[i] << endl;
    }
    cout << endl;
    
    for (int i = 0; i< sz_m_; i++)
    {
        cout << "--> Elemento en hexadecimal" << "0x" << hex << text_cifrado_[i].to_ulong() << " " << endl;
    }
    cout << endl;
}

void RC4::spritz(void)        //Modificacion
{
    int i = 0;
    int j = 0;
    int w = 0;
    int k = 0;
    int t = 0;
    
    for(int x = 0; x < sz_m_; i++)
    {
        i = (i + w) % 256;
        j = (k + S_[j + S_[i]]) % 256;
        k = i + k + S_[j] % 256;
        swap(S_[i], S_[j]);
        t = S_[j + S_[i + S_[t + k]]];
        
        sec_cifrante_[x] = t;
    }
}
