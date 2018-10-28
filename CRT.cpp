//CRT theorem
#include<iostream>
using namespace std;

void accept();
void calculate_P();
void mod_inverse(int a[], int m[]);
int product();

class crt
{
	int n[10],b[10],num,i,N,temp[10],Y[20],temp2[20];
	public:
		void accept();
		int product();
	        	void mod_inverse(int [], int []);
		void calculate_P();
};

void crt :: accept()
{
	cout<<" Enter the values : ";
	cin>>num;
               i=0;
	while(i<num)
	{
		cout<<" Enter "<<i+1<<" n value : ";
		cin>>n[i];
 		cout<<" Enter respective remainder "<<i+1<<" b value : ";
		cin>>b[i];
		i++;	
	}
}

void crt :: calculate_P()
{	
	int p=0;
	for(i=0;i<num;i++)
	{
		p=p+(temp2[i]*b[i]*Y[i]);	
	}
	p=p%N;
	cout<<" \n P value is : "<<p<<"\n";
}

void crt :: mod_inverse(int a[], int m[])
{
	int x;
	for(i=0;i<num;i++)
	{	
		temp2[i]=a[i];//To avoid overwriting
    		a[i] = a[i] % m [i];
    		for (x=1; x<m[i]; x++)
       			{
				if ((a[i]*x) % m[i] == 1)
				Y[i]=x;          		
			}
	}
	for(i=0;i<num;i++)
	cout<<"\n"<<" Value of Y"<<i+1<<" is : "<<Y[i]<<"\n";		
}

int crt :: product()
{
	N=1;
	for(i=0;i<num;i++)
	{
		N*=n[i];
	}
	cout<<" \n Value of M is : "<<N<<"\n";
	for(i=0;i<num;i++)
	{
		temp[i]=N/n[i];
	}
	for(i=0;i<num;i++)
	{
		cout<<" \n Value of M"<<i+1<< " is : ";
		cout<<temp[i]<<"\n";
        }
	mod_inverse(temp,n);
}
 
int main()
{
	crt c;
	c.accept();
	c.product();
	c.calculate_P();	
	return 0;
}

/* OUTPUT-
 a106@comp6:~$ g++ crt.cpp
a106@comp6:~$ ./a.out
 Enter the values : 5
 Enter 1 n value : 2
 Enter respective remainder 1 b value : 0
 Enter 2 n value : 3
 Enter respective remainder 2 b value : 1
 Enter 3 n value : 5
 Enter respective remainder 3 b value : 0
 Enter 4 n value : 7
 Enter respective remainder 4 b value : 6
 Enter 5 n value : 11
 Enter respective remainder 5 b value : 6
 
 Value of M is : 2310
 
 Value of M1 is : 1155
 
 Value of M2 is : 770
 
 Value of M3 is : 462
 
 Value of M4 is : 330
 
 Value of M5 is : 210

 Value of Y1 is : 1

 Value of Y2 is : 2

 Value of Y3 is : 3

 Value of Y4 is : 1

 Value of Y5 is : 1
 
 P value is : 160
*/
