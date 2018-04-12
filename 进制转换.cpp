#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int n,m,a[100001],p=0;
char c;
int main()
{
	cin>>n>>m; 
	int kl=n;
	while(n!=0)
	{
		p++;
		a[p]=n%m;
		n=n/m;
		if(a[p]<0)
		{
			a[p]-=m;
			n++;
		}
		
	}
	cout<<kl<<'=';
	for(int i=p;i>=1;i--)
	{
		if(a[i]<10)
		cout<<a[i];
		else
		{
			char b=a[i]-10+'A';
			cout<<b;
			
		}
		
	}
	cout<<"(base"<<m<<")";

}

