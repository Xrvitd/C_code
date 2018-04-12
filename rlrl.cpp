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
int n,m,p,s,t;
int h[10001],v[10001],w[100001],next[10001], d[100001],q[100001];
bool f[10001];
void add(int a,int b,int c)
{
	p++;
	w[p]=c;
	v[p]=b;
	next[p]=h[a];
	h[a]=p;
}
void spfa()
{
	int ha=0,t=1;
	q[1]=s;
	f[s]=1;
	d[s]=0;
	memset(d,127,sizeof(d));
	while(ha<=t)
	{
		ha++;
		int i=q[ha];
		p=h[i];
		f[i]=0;
		while(p)
		{
			if(d[v[p]]>d[i]+w[p])
			{
				d[v[p]]=d[i]+w[p];
				if(!f[v[p]])
				{
					t++;
					f[v[p]]=1;
					q[t]=v[p];
				}
				p=next[p];
			}
		}
	}
}
int main()
{
	cin>>n>>m>>s>>t;
	for(int i=1;i<=m;i++)
	{
		int q,w,e;
		cin>>q>>w>>e;
		add(q,w,e);
		add(w,q,e);
	}
	spfa();
	cout<<d[t];

}

