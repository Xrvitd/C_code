#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#define N 50005
using namespace std;
int p,n,m,ans=0;
int w[N],h[N],next[N],v[N],d[N]={0},k[N]={0};
bool f[N]={0};
int add(int a,int b,int c)
{
	p++;
	w[p]=c;
	v[p]=b;
	next[p]=h[a];
	h[a]=p;
}
void dfs(int x)
{
	p=h[x];
	while(p)
	{
		if(!f[v[p]]&&d[v[p]]>d[x]+w[p])
		{
			f[v[p]]=1;
			d[v[p]]=d[x]+w[p];
			k[v[p]]=w[p];
			dfs(v[p]);
		}
		p=next[p];
	}
}
int main()
{
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int q,w,e;
		cin>>q>>w>>e;
		add(q,w,e);
		add(w,q,e);
	}
	memset(d,127,sizeof(d)); 
	f[1]=1;
	d[1]=0;
	dfs(1);
	
	for(int i=1;i<=n;i++)
	{
		cout<<[i]<<" ";
		ans+=k[i];
		m=max(m,d[i]);
	}
	cout<<ans*2-m;

}

