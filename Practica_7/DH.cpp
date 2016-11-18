#include "DH.h"

DH::DH(void):
p_(0),
alpha_(0),
Ka_(0),
Kb_(0),
Xa_(0),
Xb_(0),
Ya_(0),
Yb_(0)
{}

DH::DH(int p, int alpha, int xa, int xb):
p_(p),
alpha_(alpha),
Ka_(0),
Kb_(0),
Xa_(xa),
Xb_(xb),
Ya_(0),
Yb_(0)
{
    if(!primo(p_))
    {
        cout << "--> Error, el número " << p_ << " no es primo";
        cin >> p_;
    }
}

DH::~DH(void)
{}

int DH::get_p(void)
{
    return p_;
}
int DH::get_alpha(void)
{
    return alpha_;
}

int DH::get_ka(void)
{
    return Ka_;
}

int DH::get_kb(void)
{
    return Kb_;
}

int DH::get_xa(void)
{
    return Xa_;
}

int DH::get_xb(void)
{
    return Xb_;
}

int DH::get_ya(void)
{
    return Ya_;
}

int DH::get_yb(void)
{
    return Yb_;
}

bool DH::primo(int primo)
{
    int aux = 0;
    
    for(int i = 1; i <= primo; i++)
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


int DH::exponenciacion_rapida(int alfa, int b, int m)
{
	int x = 1;
	int y = alfa;
		
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
    Ya_ = exponenciacion_rapida(alpha_,Xa_,p_);
    Yb_ = exponenciacion_rapida(alpha_,Xb_,p_);
    Ka_ = exponenciacion_rapida(Yb_,Xa_,p_);
}

ostream& operator<<(ostream& os, DH& a)
{
    os << "p: " << a.get_p() << " α: " << a.get_alpha() << " Xa: " << a.get_xa() << " Xb: " << a.get_xb() << " Ya: " << a.get_ya() << " Yb: " << a.get_yb() << " k: " << a.get_ka() << endl;
    return os;
}