#include "DH.h"

DH::DH(void):
n_(0),
p_(0),
alpha_(0),
X_(),
Y_(),
K_(0)
{}

DH::DH(long p, long alpha, long num, long* x):
n_(num),
p_(p),
alpha_(alpha),
X_(),
Y_(),
K_(0)
{
    if(!primo(p_))
    {
        cout << "--> Error, el número " << p_ << " no es primo";
        cin >> p_;
    }
    X_ = new long[n_];
    Y_ = new long[n_];
    X_ = x;
}

DH::~DH(void)
{}

bool DH::primo(long primo)
{
    long aux = 0;
    
    for(long i = 1; i <= primo; i++)
    {
        if(primo % i==0)
            aux++;
    }

    if(aux == 2)
    {
        return true;
    }
    else
    {
        return false; 
    }
}

int DH::exponenciacion_rapida(long alph, long b, long m)
{
	long x = 1;
	long y = alph;
		
	while(b > 0)
	{
		if(b % 2 != 0)
		{
			x = (x * y) % m;
			b = b - 1;
		}
			
		else
		{
			y = (y * y) % m;
			b = b / 2;
		}
	}
	return x;
}

void DH::generador(void)
{
    for(long i = 0; i < n_; i++)
    {
        Y_[i] = exponenciacion_rapida(alpha_, X_[i], p_);
    }
    K_ = exponenciacion_rapida(Y_[1], X_[0], p_);
}

void DH::write(void)
{
    cout << "--> P: " << p_ << " α: " << alpha_;
    
    for (long i = 0; i < n_; i++) 
    {
         cout << " X" << (i + 1) << ": " << X_[i] << " Y" << (i + 1) <<": " << Y_[i] << " "; 
    }
    cout << "K: " << K_ << endl;
}

