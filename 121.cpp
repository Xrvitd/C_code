#include<iostream>
using namespace std;
int n,m,s=0;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>m;
		s+=m;
	}
	cout<<s;
}
