#include<iostream>
using namespace std;
int n,m;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>m;
		int a,b,c;
		a=m/100;
		b=m%100/10;
		c=m%10;
		if((a*a*a+b*b*b+c*c*c) == m)
		{
			cout<<"YES\n";
		}else
		{
			cout<<"NO\n";
		}
	}
}
