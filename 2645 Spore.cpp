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
int n,m,ha=0,qu[1000001],h[10001],ti=1,p=0,ans=-2147483647,d[10001],visit[10001];
bool f[10001];
bool bok=0;
struct zqm
{
	int v,next,w;
}q[100001];
void add(int a,int b,int c)
{
	p++;
	q[p].v=b;
	q[p].w=c;
	q[p].next=h[a];
	h[a]=p;
}
void spfa()
{
	qu[1]=1;
	f[1]=1;
	memset(d,127,sizeof(d));
	d[1]=0;
	while(ha<=ti)
	{
		ha++;
		int i=qu[ha];
		int k=h[i];
		f[i]=0;
		while(k)
		{
			int x=q[k].v;
			if(d[x]>d[i]+q[k].w)
			{
				d[x]=d[i]+q[k].w;
				if(!f[x])
				{
					ti++;
					visit[x]++;
				if(visit[x]>=n+2)
				{
					bok=1;
					return;
				}
					qu[ti]=x;
					f[x]=1;
				}
			}
			k=q[k].next;
		}
	}
} 
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
int main()
{
	while(cin>>n>>m)
	{
		if(n==m&&m==0)break;
		memset(q,0,sizeof(q));
		memset(qu,0,sizeof(qu));
		memset(f,0,sizeof(f));
		memset(h,0,sizeof(h));
		for(int i=1;i<=m;i++)
		{
			int q,w,e,r;
			cin>>q>>w>>e>>r;
			add(q,w,e);
			add(w,q,r);
		}
		ha=0;
		ti=1;
		bok=0;
		spfa();
		if(d[n]>=2000000000||bok)
		{
			cout<<"No such path\n";
		}else
    	cout<<d[n]<<endl;
	}
	
}

