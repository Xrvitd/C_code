#include<iostream>
#include<cstdio>
using namespace std;
int n,a,b,c,d,e,g;
long long f;
int gcd(int a,int b)
{
	return b==0 ? a : gcd(b,a%b);
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b>>c>>d;
		e=gcd(b,d);
		f=a*c/gcd(a,c);
		g=gcd(e,f);
		e/=g;
		f/=g;
		if(e==1) printf("%d\n",f); else 
		printf("%d/%d\n",f,e);
	}
	return 0;
 } 

