#include<iostream>
#include<cmath>
using namespace std;
int n;
bool z(int x)
{
	if(x==2) return 1;
	for(int i=2;i<=sqrt(x)+1;i++)
	{
		if(x%i==0) return 0;
	}
	return 1;
}
int main()
{
	cin>>n;
	for(int i=n-1;;i--)
	{
		if(z(i))
		{
			cout<<i;
			return 0;
		}
	}
}
