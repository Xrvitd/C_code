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
int n,m,p,s,t,v[100001],h[100001],w[100001],next[100001],q[1000001],d[100001];
bool f[1000001];
int add(int a,int b,int c)
{
	p++;
	v[p]=b;
	w[p]=c;
	next[p]=h[a];
	h[a]=p;
}
void spfa()
{
	int ha=0,ti=1;
	q[1]=s;
	d[1]=0;
	f[1]=1;
	while(ha<=ti)
	{
		ha++;
		
	    p=h[ha];
	    f[ha]=0; 
	    
		while(p)
		{
			if(d[v[p]]>w[p]+d[p])
			{
				d[v[p]]=w[p]+d[p];
				if(!f[v[p]])
				{
					ti++;
					q[ti]=v[p];
				}
			}
			p=next[p];
		}
	}
} 
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int q,w,e;
		cin>>q>>w>>e;
		add(q,w,e);
		add(w,q,e);
	}
	cin>>s>>t;
	spfa();
	cout<<d[t];
}

