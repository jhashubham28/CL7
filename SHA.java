import java.io.*;
import java.security.*;
import java.util.Scanner;

	public class SHA{
		String str1,str2;
		SHA()
		{
			str1=null;
			str2=null;
		}
		StringBuffer applyAlgorithm(String str) throws NoSuchAlgorithmException
		{
			byte[] input=str.getBytes();
			MessageDigest SHA1=MessageDigest.getInstance("SHA1");
			SHA1.update(input);
			byte[] digest=SHA1.digest();
			StringBuffer hexDigest=new StringBuffer();
			for(int i=0;i<digest.length;i++)
			{
				hexDigest.append(Integer.toString((digest[i] & 0xff) +0x100,16).substring(1));
			}
			System.out.println("After conversion digest is :"+hexDigest);
				return hexDigest;
		}
		public static void main(String[] args) throws NoSuchAlgorithmException  {
			SHA sh1=new SHA();
			Scanner sc=new Scanner(System.in);
			System.out.println("Enter the first text for conversion");
			sh1.str1=sc.nextLine();
			StringBuffer res1=sh1.applyAlgorithm(sh1.str1);
			System.out.println("Enter the second text for conversion");
			sh1.str2=sc.nextLine();
			StringBuffer res2=sh1.applyAlgorithm(sh1.str2);
			if(res1.toString().equals(res2.toString()))
				System.out.println("Both are equal");
			else
				System.out.println("Both are unequal");
			
		}

	}