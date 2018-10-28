import java.io.*;
import java.math.*;
import java.util.*;
public class RSA2{
	static int p,n,q,e,d,P,C,phi;
	Scanner sc=new Scanner(System.in);
	public static int gcd(int a,int b)
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
	public static int modulo(int a,int b,int c)
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
	public static void inv_modulo(int a,int b)
	{
		int x;
		a=a%b;
		for(x=1;x<b;x++)
		{
			if((a*x)%b==1)
				d=x;
		}
	}
	public void rsa()
	{
		int cnt;
		
		System.out.println("Enter two numbers: ");
		p=sc.nextInt();
		q=sc.nextInt();
		n=p*q;
		System.out.println("N is "+n);
		phi=(p-1)*(q-1);
		System.out.println("Phi is "+phi);
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

	public void encryption()
	{
		System.out.println("E: "+e);
		System.out.println("D: "+d);
		System.out.println("Private key: {"+d+","+n+"}");
		System.out.println("Public key: {"+e+","+n+"}");
		System.out.println("Enter plaintext");
		P=sc.nextInt();
		
		while(P>n)
		{
			System.out.println("Enter plaintext");
			P=sc.nextInt();

		}
		C=modulo(P,e,n);
		System.out.println("Ciphertext:  "+C);
		
	}		
	public void decryption()
	{
		
		P=modulo(C,d,n);
		System.out.println("Plaintext:  "+P);
		
	}	

	public static void main(String args[])
		{
			RSA2 R=new RSA2();
			R.rsa(); 
		}	
} 