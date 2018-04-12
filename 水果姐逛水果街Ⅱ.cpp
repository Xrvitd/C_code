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
#define N 1000005
#define P 1000000007
#define debug(x) cerr<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
int n,m;
int a[200010],p=0,nex[N*2],h[N*2],v[N*2],j[N][20],ma[N][20],mi[N][20],lr[N][20],rl[N][20],deep[N];
void add(int aa,int b)
{
	p++;
	v[p]=b;
	nex[p]=h[aa];
	h[aa]=p;
}
bool vv[N];
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
		ma[x][i]=max(ma[x][i-1],ma[j[x][i-1]][i-1]);
		mi[x][i]=min(mi[x][i-1],mi[j[x][i-1]][i-1]);
		lr[x][i]=max(ma[j[x][i-1]][i-1]-mi[x][i-1],max(lr[x][i-1],lr[j[x][i-1]][i-1]));
		rl[x][i]=max(ma[x][i-1]-mi[j[x][i-1]][i-1],max(rl[x][i-1],rl[j[x][i-1]][i-1]));
	}
	int k=h[x];
	while(k)
	{
		if(vv[v[k]])
		{
			k=nex[k];
			continue;
		}
			vv[v[k]]=1;
			j[v[k]][0]=x;
		    ma[v[k]][0]=max(a[x],a[v[k]]);
		    mi[v[k]][0]=min(a[x],a[v[k]]);
		    lr[v[k]][0]=a[x]-a[v[k]];
		    rl[v[k]][0]=a[v[k]]-a[x];
			dfs(v[k],s+1);
			k=nex[k];
	}
}
int just_doit(int x,int y)
{
	int ans=0,xmi=a[x],yma=a[y];
	if(x==y)
	{
		return 0;
	}
	if(deep[x]>deep[y])
	{
		int mii=a[x],maa=0;
		for(int i=15;i>=0;i--)
	    {
		if(deep[x]-(1<<i)>=deep[y])
		{
			ans=max(ans,max(lr[x][i],ma[x][i]-xmi));
			xmi=min(xmi,mi[x][i]);
			x=j[x][i];
		}
	    }
	}else
	{
		if(deep[x]<deep[y])
		{
		int mii=2147483647,maa=a[y];
		for(int i=15;i>=0;i--)
	    {
		if(deep[y]-(1<<i)>=deep[x])
		{
			ans=max(ans,max(rl[y][i],yma-mi[y][i]));
			yma=max(yma,ma[y][i]);
			y=j[y][i];
		}
	    }
		}
		else
		{
			xmi=a[x];
			yma=a[y];
		}
	}
	if(x==y)
	{
		return ans;
	}
	int may=0,mix=a[x];
	for(int i=15;i>=0;i--)
	{
		if(deep[x]-(1<<i)>=1&&j[x][i]!=j[y][i])
		{
			ans=max(ans,max(lr[x][i],ma[x][i]-xmi));
			ans=max(ans,max(rl[y][i],yma-mi[y][i]));
			xmi=min(xmi,mi[x][i]);
			yma=max(yma,ma[y][i]);
			x=j[x][i];
			y=j[y][i];
		}
	}
	ans=max(ans,max(yma-xmi,max(a[j[y][0]]-xmi,yma-a[j[x][0]])));
	return ans;
}
int main()
{
	n=get_num();
	for(int i=1;i<=n;i++)
	{
		a[i]=get_num();
	}
	for(int i=1;i<n;i++)
	{
		int q,w;
		q=get_num();w=get_num();
		add(q,w);
		add(w,q);
	}
	vv[1]=1;
	dfs(1,1);
	//cout<<rl[6][1];
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		int q,w;
		q=get_num();w=get_num();
		cout<<just_doit(q,w)<<"\n";
	}

}

