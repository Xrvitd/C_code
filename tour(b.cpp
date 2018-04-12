#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#define N 50005
using namespace std;
int p,n,m,ans=0;
int w[N],h[N],next[N],v[N],d[N]={0},k[N]={0},q[100001];
bool f[N]={0};
int add(int a,int b,int c)
{
	p++;
	w[p]=c;
	v[p]=b;
	next[p]=h[a];
	h[a]=p;
}
void bfs(int x)
{
	int ha=0,ti=1;
	while(ha<=ti)
	{
		ha++;
		int i=q[ha],p=h[i];
		f[i]=0;
		while(p)
		{
			if(d[i]+w[p]<d[v[p]])
			{
				d[v[p]]=d[i]+w[p];
				k[v[p]]=w[p];
				if(!f[v[p]])
				{
					ti++;
					q[ti]=v[p];
					f[v[p]]=1; 
				}
			}
			p=next[p];
		}
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
	q[1]=1;
	dfs(1);
	
	for(int i=1;i<=n;i++)
	{
		//cout<<d[i]<<" ";
		ans+=k[i];
		m=max(m,d[i]);
	}
	cout<<ans*2-m;

}

