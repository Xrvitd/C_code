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
#include<deque>
#define INF 1000000000
#define fi first
#define se second
#define N 100005
#define P 1000000007
#define debug(x) cerr<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
int n,m,ans=0;
int f[10001]={0},d[10001]={0};
bool v[10001]={0};
int find(int x)
{
	return f[x]=(f[x]==x)? x:find(f[x]);
}
struct re 
{
	int s,w[1001];
};
struct re q[1001];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		f[i]=i;
	}
	for(int i=1;i<=m;i++)
	{
		char ch;
		int a,b;
		cin>>ch>>a>>b;
		if(ch=='F')
		{
			f[find(a)]=find(f[b]);
    	}else
    	{
    		q[a].s++;
    		q[a].w[q[a].s]=b;
    		q[b].s++;
    		q[b].w[q[b].s]=a;
    		for(int l=1;l<=q[a].s;l++)
    		{
    			int qh=q[a].w[l];
    			for(int j=1;j<=q[qh].s;j++)
    			{
    				f[find(q[qh].w[j])]=find(f[a]);
    			}
    		}
    		for(int l=1;l<=q[b].s;l++)
    		{
    			int qh=q[b].w[l];
    			for(int j=1;j<=q[qh].s;j++)
    			{
    				f[find(q[qh].w[j])]=find(f[b]);
    			}
    		}
    	}
	}
	for(int i=1;i<=n;i++)
	{
		int k=find(i);
		if(!v[k])
		{
			v[k]=1;
			ans++;
		}
	}
	cout<<ans;
}

