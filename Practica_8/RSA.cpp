#include <cmath>
#include "RSA.h"

RSA::RSA(long P, long Q, long D, string mensaje):
p(P),
q(Q),
d(D),
n(0),
e(0),
fi(0),
mensaje_(mensaje)
{
    fi = (p-1) * (q-1);
    n = p * q;
    euclides_ext(d, fi);
    
    if(lehman_peralta(p))
    {
        cout << "--> Los numeros introducidos son compuestos" << endl;
    }
    
    cout << "--> Parámetros = Fi: " << fi << " Q: " << q << " P: " << p << " N: " << n << " E: " << e << endl;
    cout << "--> Mensaje introducido: " << mensaje_ << endl;
}

RSA::~RSA(void)
{}

bool RSA::lehman_peralta(long primo)
{
    long v[5] = {2,3,5,7,11};
    long a[100];
    long r[100];
    long contador[2];
    
    for(long i = 0; i < 5; i++)
    {
        if(primo % v[i] == 0)
        {
            return false;
        }
        
        if(primo == v[i])
        {
            return true;
        }
    }
    
    srand(time(NULL));
    for(long i = 0; i < 100; i++)
    {
        a[i] = rand() % (primo-2) + 2;
        r[i] = exponenciacion_rapida(a[i], ((primo-1)/2), primo);
    }
    
    for(long i = 0; i < 100; i++)
    {
        if(r[i] == 1)
        {
            contador[0]++;
        }
        
        else if(r[i] == -1)
        {
            contador[1]++;
        }
    }
    
    if(contador[0] == 100)
    {
        return false;
    }
    
    else if(contador[0] < 100 && contador[1] >= 1)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int RSA::exponenciacion_rapida(long alfa, long b, long m)
{
	long x = 1;
	long y = alfa;
		
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

int RSA::euclides_ext(long a, long b)
{
    long c[100];
    long d[100];
    
    if(a > b)
    {
        c[0] = a;
        c[1] = b;
    }
    
    else if(a < b)
    {
        c[0] = b;
        c[1] = a;
    }
    
    d[0] = 1;
    d[-1] = 0;
    
    long i  = 1;
    while((c[i-1] & c[i]) != 0)
    {
        c[i+1] = c[i-1] % c[i];
        d[i] = -(c[i-1]/c[i])*d[i-1]+d[i-2];
        i++;
    }
    
    if (c[i]==1)
    {
        if(d[i-1] < 0)
        {
            d[i-1] = fi + d[i-1];
        }
        
        e = d[i-1];
        return true;
    }
    return false;
}

void RSA::cifrado(void)
{
    long i = 0;
    while(n > pow(26,i))
    {
        i++;
    }
    
    block_ = i - 1;
    
    mensaje_ = no_espacio(mensaje_);
    
    mens_decimal = new long[mensaje_.size()];
    solucion_ = new long[mensaje_.size() / block_];
    
    cout << "--> El tamaño del bloque es: " << block_ << endl;
    
    long aux = 0;
    long j = block_;
    long dummy = 0;
    
    for(long k = 0; k < mensaje_.size(); k++)
    {
        mens_decimal[k] = mensaje_[k] - 65;
    }
    
    for(long k = 0; k < mensaje_.size(); k++)
    {
        while(j-1 >= 0)
        {
            aux += mens_decimal[k + dummy] * pow(26, j-1);
            dummy++;
            j--;
        }
        k += (block_-1);
        dummy = 0;
        solucion_[k/block_] = aux;
        aux = 0;
        j = block_;
    }
    
    cout << endl << "--> Codificación numérica del mensaje original: ";
    for(long k = 0; k < mensaje_.size() / block_; k++)
    {
        cout << solucion_[k] << " ";
    }
    cout << endl;
    
    for(long k = 0; k < mensaje_.size() / block_; k++)
    {
        solucion_[k] = exponenciacion_rapida(solucion_[k], e, n);
    }
    
    cout << endl << "--> Mensaje original cifrado: ";
    for(long k = 0; k < mensaje_.size() / block_; k++)
    {
        cout << solucion_[k] << " ";
    }
    cout << endl;
}

void RSA::descifrado(void)
{
    long descifrado[mensaje_.size() / block_];
    
    for(long k = 0; k < mensaje_.size() / block_; k++)
    {
        descifrado[k] = exponenciacion_rapida(solucion_[k], e, n);
    }
    
    cout << "--> Mensaje descifrado: ";
    for(long k = 0; k < mensaje_.size() / block_; k++)
    {
        cout << descifrado[k] << " ";
    }
    cout << endl;
}

string RSA::no_espacio(string cadena)
{
    string aux;
    aux.clear();
    
    for (long i = 0; i < cadena.size(); i++)
    {
        if (cadena[i] != ' ')
        {
            aux += cadena[i];
        }
    }
    return aux;
}