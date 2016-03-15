#include "vigenere.h"

using namespace std;

vigenere::vigenere(string original, string key_word):       //Constructor
original_(original),
key_word_(key_word),
cifrated_text_()
{}

vigenere::~vigenere(void)       //Destructor
{}

void vigenere::cap_letters(void)        //Metodo que convierte a mayusculas la clave y el mensaje
{
    for(int i = 0; i < key_word_.size(); i++)
    {
        key_word_[i] = toupper(key_word_[i]);
    }
    
    /*for(int i = 0; i < original_.size(); i++)
    {
        original_[i] = toupper(original_[i]);
    }*/
}

void vigenere::no_space(void)       //Metodo que quita los espacios a la cadena de caracteres
{
    string aux;
    int space = 0;
    
    for(int i = 0; i < original_.size(); i++)
    {
        int str_to_int = original_[i]; 
        if(str_to_int == 32)
        {
            space++;
        }
    }
    
    aux.resize(original_.size() - space);
    int j = 0;
    
    for(int i = 0; i < original_.size(); i++)
    {
        int str_to_int = original_[i]; 
        if(str_to_int != 32)
        {
            aux[j] = str_to_int;
            j++;
        }
    }
    original_.clear();
    original_ = aux;
}
    
void vigenere::encode(void)     //Metodo que se encarga del cifrado de la palabra clave
{
    cap_letters();
    no_space();
    int j = 0;
    cifrated_text_.resize(original_.size());
    for(int i = 0; i< original_.size(); i++)
    {
        
        if(j == (key_word_.size()-1))
        {
            cifrated_text_[i] = (((original_[i] + key_word_[j]) % 26) + 65);
            j = 0;
        }
        else
        {
            cifrated_text_[i] = (((original_[i] + key_word_[j]) % 26) + 65);
            j++;
        }
    }
    cout << "--> Palara clave: " << key_word_ << endl;
    cout << "--> Texto original: " << original_ << endl;
    cout << "--> Texto cifrado: " << cifrated_text_ << endl;
    
    int i = 0;      //Modificacion de las letras de la clave
    
    for(i = 0; i < key_word_.size(); i++)
    {
        cout << "[" << key_word_[i] << "]" << endl;
        for(j = 0; j < original_.size(); j += key_word_.size())
        {
            cout << "--> Letra: " << cifrated_text_[j+i] << endl;
        }
    }
}

void vigenere::decode(void)     //Metodo que se encarga del descifrado del mensaje
{
    int aux = 0;
    int j = 0;
    decoded_res_.resize(original_.size());
    for(int i = 0; i< original_.size(); i++)
    {
        if(j == (key_word_.size()-1))
        {
            aux = (cifrated_text_[i] - key_word_[j]);    
            while(aux < 0)
            {
	            aux = aux + 26;
            }
            decoded_res_[i] = aux + 65;          
            j = 0;
        }
        else
        {  
            aux = (cifrated_text_[i] - key_word_[j]);
            while(aux < 0)
            {
	            aux = aux + 26;                     
            }
            decoded_res_[i] = aux + 65;
            j++;
        }
    }
   cout << "--> Mensaje final descifrado: " << decoded_res_ << endl;
}