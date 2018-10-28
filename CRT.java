import java.io.*;
import java.util.*;

public class CRT2{
	static int num,M;
	static int[] a=new int[20];
	static int[] r=new int[20];
	static int[] temp=new int[20];
	static int[] temp2=new int[20];
	static int[] Y=new int[20];
	//int [] =new int[20]; 
	static Scanner sc=new Scanner(System.in);
	public static void accept(){
		System.out.println("Enter the number of cases");
		num=sc.nextInt();
		//System.out.println("Enter the remainder #"+(i+1));
		for(int i=0;i<num;i++)
		{
			System.out.println("Enter the remainder #"+(i+1));
			r[i]=sc.nextInt();
			System.out.println("Enter the number #"+(i+1));
			a[i]=sc.nextInt();
		}
	}
	public static void cal(){
		M=1;
		for(int i=0;i<num;i++)
		{
			System.out.println("a[i] is"+a[i]);
			M*=a[i];
		}
		System.out.println("M is"+M);
		for(int i=0;i<num;i++)
		{
			temp[i]=M/a[i];
			System.out.println("Value of M"+(i+1)+" is "+temp[i]);
		}
		inv_modulo(temp,a);
		int P=0;
		for(int i=0;i<num;i++)
			{
				P+=(r[i]*temp2[i]*Y[i]);
			}
			P=P%M;
			System.out.println("vALUE OF nUMBER IS "+P);	
}
	

	public static void inv_modulo(int x[],int y[])
		{
			for(int i=0;i<num;i++)
			{
				temp2[i]=x[i];
				x[i]=x[i]%y[i];
				for(int j=1;j<y[i];j++)
				{
					if((x[i]*j)%y[i]==1)
						Y[i]=j;
				}
				System.out.println("Value of Y"+(i+1)+" is "+Y[i]);

			}

		}	



	public static void main(String[] args) {
		CRT2 C=new CRT2();
		C.accept();
		C.cal();
		
	}
}