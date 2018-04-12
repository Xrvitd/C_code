#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cstdlib>
#include<string>
#define debug(x) cerr<<#x<<"="<<x<<endl
using namespace std;
int n,a[1000001]={0},f[1000001]={0};
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	f[i]=1;
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=i-1;j++)
		{
			if(a[j]<a[i])
			{
				f[i]=max(f[i],f[j]+1);
			}
		}
	}
	int m=0;
	for(int i=1;i<=n;i++)
	{
		m=max(f[i],m);
	}
	cout<<m;
}
