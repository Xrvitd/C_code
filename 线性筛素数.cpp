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
#include<bitset>
#include<iomanip>
using namespace std;
int n,m,ans=0,l=0;
int p[11000001];
bool v[1100001];
int main()
{
       
	    memset(v,true,sizeof(v)); 
		cin>>n>>m;
		v[1]=1;
		for(int i=2;i<=n;i++)
		{
			if(v[i]==0) 
			{
				l++;
				p[l]=i;
			}
			for(int j=1;p[j]*i<=n&&j<=l;j++)
			{
				v[i*p[j]]=1;
				if(i%p[j]==0) break;
			}
		}
		for(int i=1;i<=m;i++)
		{
			int q;
			cin>>q;
			if(v[q])
			printf("Yes\n");
			else
			printf("No\n");
		}
}

