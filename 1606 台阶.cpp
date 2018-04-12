#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int n,m,ans=0,f[10000001];
int main()
{
	cin>>n>>m;
	f[0]=1;f[1]=1;
	for(int i=1;i<=n;i++)
	{
		if(i!=m)
		{
			f[i]=f[i-1]+f[i-2];
			f[i]%=123321;
		}
	}
    cout<<f[n]%123321;
}
