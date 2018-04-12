#include<iostream>
using namespace std;
int n,m,k;
int main()
{
   for(int i=1;i<=9;i++)
   {
   	   for(int j=1;j<=i;j++)
   	   {
   	   	  cout<<j<<"*"<<i<<"="<<i*j<<" ";
   	   }
   	   cout<<"\n";
   }
}

