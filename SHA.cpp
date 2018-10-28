#include <openssl/sha.h>
#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{  
  unsigned char str[] = "sanket";
   unsigned char hash[SHA_DIGEST_LENGTH]; // == 20
   char encrypted[SHA_DIGEST_LENGTH];

  SHA1(str, sizeof(str) - 1, hash);

for(int i=0;i<SHA_DIGEST_LENGTH;i++)
         sprintf(&encrypted[i*2], "%02x", (unsigned int)hash[i]);
         
         cout<<"Encrypted String:- "<<encrypted;
  return 0;
}


//for output run following command
//g++ sha1.cpp -lcrypto