#include "vernam.h"

using namespace std;

vernam::vernam(string original):        //Constructor
original_bin_(),
key_bin_(),
original_(original),
key_(),
size_original_bin_(0)
{}

vernam::~vernam(void)       //Destructor
{}

void vernam::cadena_binario_o(string original)        //Convertir cadena a binario mensaje
{
    int tam = original.size();
    original_bin_ = new bitset<8>[tam];
    bitset<8> aux[tam];
    
    for (std::size_t i = 0; i < tam; i++)       
    {
        aux[i] = bitset<8>(original.c_str()[i]);
        original_bin_[i] = aux[i].to_ulong();
    }
    size_original_bin_ = tam;
}

void vernam::cadena_binario_m(string original_A)        //Convertir cadena a binario clave
{   
    int tam = original_A.size();
    key_bin_ = new bitset<8>[tam];
    bitset<8> aux[tam];
    
    for (std::size_t i = 0; i < tam; i++)
    {
        aux[i] = bitset<8>(original_A.c_str()[i]);
        key_bin_[i] = aux[i];
    }
}

/*void vernam::random(int tam)     //Funcion que genera numeros aleatorios
{
    key_.resize(tam);
    string aux;
    aux.resize(tam);
    srand(time(NULL));
    
    for(int i = 0; i < tam; i++)
    {
        aux[i] = 33 + rand() % (126 - 33);
        key_[i] = aux[i];
        aux.clear();
    }
}*/

void vernam::cifrado(void)      //Metodo que realiza el cifrado
{
    cadena_binario_o(original_);
    cout << "Entrada" << endl;
    cout << "--> Mensaje original: " << original_ << endl;
    cout << "Salida" << endl;
    cout << "--> Mensaje original en binario: ";

    for(int i = 0; i < size_original_bin_; i++)
    {
        cout << original_bin_[i] << " ";
    }

    //random(size_original_bin_);
    cout << endl << "Entrada" << endl;
    cout << "--> Clave a usar: ";
    cin >> key_;
    
    cadena_binario_m(key_);
    
    for(int i = 0; i < size_original_bin_; i++)
    {
        cout << key_[i] << " ";
    }
    
    cout << endl << "Salida" << endl;
    cout << "--> Mensaje cifrado en binario: "; 
    
    for(int i = 0; i < size_original_bin_; i++)
    {
        bitset<8> aux = original_bin_[i] ^ key_bin_[i];
        cout << aux << " ";
    }
    cout << endl << "--> Mensaje cifrado: ";
    
    solution_ = new bitset<8>[size_original_bin_];
    
    for(int i = 0; i < size_original_bin_; i++)
    {
        solution_[i] = original_bin_[i] ^ key_bin_[i];
        long characters = solution_[i].to_ulong();
        char a = characters;
        cout << a << " ";
    }
    cout << endl;
}

void vernam::descifrado(void)       //Metodo que realiza el descifrado
{
    cout << "Entrada" << endl;
    cout << "--> Mensaje cifrado: ";
    
    for(int i = 0; i < size_original_bin_; i++)
    {
        long characters = solution_[i].to_ulong();
        char b = characters;
        cout << b << " ";
    }
    
    cout << endl << "Salida" << endl;
    cout << "--> Mensaje cifrado en binario: ";
    
    for(int i = 0; i < size_original_bin_; i++)
    {
        cout << key_bin_[i] << " ";
    }
    
    cout << endl << "Salida" << endl;
    cout << "--> Mensaje original en binario: ";
    
    for(int i = 0; i < size_original_bin_; i++)
    {
        bitset<8> aux = solution_[i] ^ key_bin_[i];
        cout << aux << " ";
    }
    cout << endl << "--> Mensaje original descifrado: " << original_ << endl;
}
