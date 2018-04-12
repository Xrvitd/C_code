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
int n,m;
int h[N],v[N],next[N],p=0,d[N],f[N],w[N],l[N],j[N][15],ww[N][15],deep[N];
bool vv[N];
void add(int a,int b)
{
	p++;
	v[p]=b;
	next[p]=h[a];
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
void dfs(int x,int s)
{
	deep[x]=s;
	for(int i=1;(1<<i)<s;i++)
	{
		j[x][i]=j[j[x][i-1]][i-1];
	}
	int pp=h[x];
	while(pp)
	{
		if(vv[v[pp]])
		{
			pp=next[pp];
			continue;
		}
		vv[v[pp]]=1;
		j[v[pp]][0]=x;
		dfs(v[pp],s+1);
		pp=next[pp];
	}
}
int LCA(int x,int y)
{
	int ans=0; 
	if(deep[y]>deep[x])
	{
		int kk=y;
		y=x;
		x=kk;
	}
	for(int i=15;i>=0;i--)
	{
		if((deep[x]-(1<<i))>=deep[y])
		{
			ans+=(1<<i);
	    	x=j[x][i];
		}
	}
	if(x==y)return ans;
	for(int i=15;i>=0;i--)
	{
		if(j[x][i]!=j[y][i]&&deep[x]-(1<<i)>=1)
		{
			ans+=(1<<i);
			ans+=(1<<i);
			x=j[x][i];
			y=j[y][i];
		}
	}
	ans+=2;
	return ans;
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
	
	vv[1]=1;
	dfs(1,1);
    cin>>m;
    int l=1;
    int sum=0;
    for(int i=1;i<=m;i++)
    {
    	int q;
    	cin>>q;
    	sum+=LCA(l,q);
    	cout<<l<<" "<<q<<" : "<<LCA(l,q)<< " \n";
    	l=q;
    }
    cout<<sum;
}

