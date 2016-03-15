#include <cstdio>
#include <iostream>
#include <cstdlib>

using namespace std;

class vigenere
{
    private:
    
    string key_word_;
    string original_;
    string cifrated_text_;
    string decoded_res_;
    
    public:
    
    vigenere(string original, string key_word);
    ~vigenere(void);
    void cap_letters(void);
    void no_space(void);
    void encode(void);
    void decode(void);
    //friend ostream& operator <<(ostream& os, const vigenere& A);
};