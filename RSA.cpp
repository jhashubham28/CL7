#include<iostream>
using namespace std;

class RSA{
	int p,q,d,n,phi,e,P,C;
	public:
		int gcd(int,int);
		void rsa();
		int modulo(int,int,int);
		void inv_modulo(int,int);
		void encryption();
		void decryption();
};

int RSA::gcd(int a,int b)
	{
		int r;
		r=b%a;
		while(r!=0)
		{
			b=a;
			a=r;
			r=b%a;
		}
		return a;
	}
int RSA::modulo(int a,int b,int c)
	{
		int x,y;
		x=1;y=a;
		while(b>0)
		{
			if(b%2==1)
			{
				x=(x*y)%c; 
			}
			y=(y*y)%c;
			b=b/2;
		}
		return x%n;
	}	
void RSA::inv_modulo(int a,int b)
	{
		int x;
		a=a%b;
		for(x=1;x<b;x++)
		{
			if((a*x)%b==1)
				d=x;
		}
	}	

void RSA::rsa()
	{
		int cnt;
		cout<<"Enter two numbers: ";
		cin>>p>>q;
		n=p*q;
		cout<<"N is: "<<n;
		phi=(p-1)*(q-1);
		cout<<"P is: "<<phi;
		for(cnt=2;cnt<phi;cnt++)
			{
				if(gcd(cnt,phi)==1)
				{
					inv_modulo(cnt,phi);
					e=cnt;
					encryption();
					decryption();
					break;
				}
			}		
	}	
void RSA::encryption()
	{
		cout<<" \n Value of e : "<<e;
		cout<<" \n Value of d : "<<d;
		cout<<" \n Private Key : "<<"{"<<d<<","<<n<<"}";
		cout<<" \n Public Key : "<<"{"<<e<<","<<n<<"}";
		cout<<"Enter plaintext\n";
		cin>>P;
		while(P>n)
		{
			cout<<"Enter plaintext again\n";
			cin>>P;

		}
		C=modulo(P,e,n);
		cout<<"Ciphertext: "<<C;
	}	
void RSA::decryption()
	{
		P=modulo(C,d,n);
	    cout<<" \n Value of Plaintext after Decryption is : "<<P;
	}
int main()
	{
		RSA r;
		r.rsa();
		return 0;
	}		