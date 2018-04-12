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
int n,m,ti=0,dfn[100010],dfl[100101],sum;
int p=0,h[100011],t[500010];
struct zqm
{
	int v,next,w;
}q[200001];
void add(int a,int b)
{
	p++;
	q[p].v=b;
	q[p].next=h[a];
	h[a]=p;
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
void dfs(int x)
{
	ti++;
	if(!dfn[x])
	{
		dfn[x]=ti;
	}
    int pp=h[x];
    while(pp)
    {
    	int k=q[pp].v;
    	if(!dfn[k])
    	{
    		dfs(k);
    	}
    	pp=q[pp].next;
    }
    dfl[x]=ti;
}
void build(int x,int l,int r)
{
	if(l==r)
	{
		t[x]=1;
		return;
	}
	int mid=(l+r)>>1;
	build(2*x,l,mid);
	build(2*x+1,mid+1,r);
	t[x]=t[2*x]+t[2*x+1];
}
void chenge(int x,int l,int r,int e)
{
	if(l==r)
	{
		if(l==dfn[e])
		{
			if(t[x]==1)
			{
				t[x]=0;
			}
			else
			{
				t[x]=1;
			}
		}
		return;
	}
	int mid=(l+r)>>1;
	if(mid>=dfn[e])
	{
		chenge(2*x,l,mid,e);
	}else
	{
		chenge(2*x+1,mid+1,r,e);
	}
	t[x]=t[2*x]+t[2*x+1];
}
void find(int x,int l,int r,int w,int e)
{
	if(l==w&&r==e)
	{
		sum+=t[x];
		return;
	}
	int mid=(l+r)>>1;
	if(mid>=e)
	{
		find(2*x,l,mid,w,e);
	}else
	{
		if(mid<w)
		{
			find(2*x+1,mid+1,r,w,e);
		}else
		{
			find(2*x,l,mid,w,mid);
			find(2*x+1,mid+1,r,mid+1,e);
		}
	}
}
int main()
{
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int q,w;
		cin>>q>>w;
		add(q,w);
		add(w,q);
	}
	dfs(1);
	/*for(int i=1;i<=n;i++)
	{
		cout<<dfn[i]<<" "<<dfl[i]<<endl;
	}*/
	build(1,1,n);
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		char c;
		int e;
		cin>>c;
		if(c=='C')
		{
			cin>>e;
			chenge(1,1,n,e);
		}else
		{
			cin>>e;
			sum=0;
			find(1,1,n,dfn[e],dfl[e]);
			cout<<sum<<endl;
		}
	}
}

