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
int n,m,k,ss,pp,qq,qz[100001],h[N],v[N],next[N],q[N],p=0,w[N],d[N];
bool f[N];
struct zqm
{
	int s,x;
};
inline int get_num()
{
int num = 0;
char c;
bool flag = false;
while ((c = getchar()) == ' ' || c == '\n' || c == '\r');
if (c == '-') flag = true;
else num = c - '0';
while (isdigit(c = getchar()))
num = num * 10 + c - '0';
return (flag ? -1 : 1) * num;
}
int add(int a,int b)
{
	p++;
	v[p]=b;
	next[p]=h[a];
	h[a]=p;
}
void pd()
{
	for(int o=1;o<=k;o++)
	{
		w[qz[o]]=qq;
		int b=qz[o];
		int ha=0,ti=1;
		zqm qw[100001];
		qw[1].x=b;
		qw[1].s=0;
		bool vv[100001];
		while(ha<=ti)
		{
			ha++;
			p=h[qw[ha].x];
			
			while(p)
			{
				ti++;
				qw[ti].x=v[p];
				qw[ti].s=qw[ha].s+1;
				if(qw[ti].s>=ss)
				{
				    ti--;
				}
				vv[v[p]]=1;
				w[v[p]]=qq;
				p=next[p];
			}
		}
	}
}
void spfa()
{
	memset(d,127,sizeof(d));
	int ha=0,t=1;
	q[1]=1;
	d[1]=0;
	f[1]=1;
	while(ha<=t)
	{
		ha++;
		int i=q[ha],p=h[i];
		f[i]=0;
		while(p)
		{
			if(d[i]+w[p]<d[v[p]])
			{
				d[v[p]]=d[i]+w[p];
				if(!f[v[p]])
				{
					t++;
					q[t]=v[p];
					f[v[p]]=1; 
				}
			}
			p=next[p];
		}
	}
	return d[ta];
}
int main()
{
	cin>>n>>m>>k>>ss;
	cin>>pp>>qq;
	for(int i=1;i<=k;i++)
	{
		cin>>qz[i];
	}
	for(int i=1;i<=m;i++)
	{
		int z,xx,c;
		cin>>z>>xx;
		add(z,xx);
		add(xx,z);
	}
	for(int i=1;i<=n;i++)
	{
		w[i]=pp;
	}
	pd();
	w[1]=0;
	w[n]=0;
	for(int i=1;i<=n;i++)
	{
		cout<<w[i]<<" ";
	}

}

