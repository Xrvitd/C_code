#include<iostream>
using namespace std;
int n,m=0,k;
int a[101];
int main()
{
   cin>>n;
   a[1]=3;
   for(int i=2;i<=n;i++)
   {
   	a[i]=a[i-1]+5;
   }
   for(int i=1;i<=n;i++)
   {
   	m=m+a[i];
   	if(m%4==2)
   	{
   		cout<<m<<" ";
   	}
   }
}

