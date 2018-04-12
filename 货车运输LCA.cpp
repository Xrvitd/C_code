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
int n,m,s,ti,c;
int h[N],v[N],next[N],p=0,d[N],f[N],w[N],l[N],j[N][15],ww[N][15],deep[N];
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
struct re
{
	int x,y,bh,qz;
} q[N];
int find(int x)
{
	return f[x]==x ? x:f[x]=find(f[x]);
}
void add(int a,int b,int c)
{
	p++;
	v[p]=b;
	w[p]=c;
	next[p]=h[a];
	h[a]=p;
	l[p]=a;
}
void addd(int a,int b,int c)
{
	p++;
	q[p].x=a;
	q[p].y=b;
	q[p].bh=p;
	q[p].qz=c;
}
bool cmp(const struct re a,const struct re b)
{
	return a.qz>b.qz;
}
void dfs(int x,int s)
{
	deep[x]=s;
	for(int i=1;(1<<i)<s;i++)
	{
		j[x][i]=j[j[x][i-1]][i-1];
		ww[x][i]=min(ww[x][i-1],ww[j[x][i-1]][i-1]);
		//cout<<x<<" "<<i<<" :"<<ww[x][i]<<endl; 
	}
	int p=h[x];
	while(p)
	{
		if(vv[v[p]])
		{
			p=next[p];
			continue;
		}
		vv[v[p]]=1;
		j[v[p]][0]=x;
		ww[v[p]][0]=w[p];
		dfs(v[p],s+1);
		
	}
	return;
}
int just_doit(int x,int y)
{
	int ans=2147483647;
	if(deep[y]>deep[x])
	{
		int tt=x;
		x=y;
		y=tt;
	}
	for(int i=15;i>=0;i--)
	{
		if(deep[x]-(1<<i)>=deep[y])
		{
			ans=min(ans,ww[x][i]);
			x=j[x][i];
		}
	}
	if(x==y)
	{
		return ans;
	} 
	for(int i=15;i>=0;i--)
	{
		if(deep[x]-(1<<i)>=1&&j[x][i]!=j[y][i])
		{
			ans=min(ans,ww[x][i]);
			ans=min(ans,ww[y][i]);
			x=j[x][i];
			y=j[y][i];
		}
	}
	ans=min(ans,ww[x][0]);
	ans=min(ans,ww[y][0]);
	return ans;
}
int main()
{
	n=get_num();
	m=get_num();
	for(int i=1;i<=m;i++)
	{
		int qqq,w,e;
		qqq=get_num();w=get_num();e=get_num();
		addd(qqq,w,e);
		addd(w,qqq,e);
	}
	sort(q+1,q+p+1,cmp);
	for(int i=1;i<=n;i++) f[i]=i;
	int k=0;p=0;
	for(int i=1;i<=m*2;i++)
	{
		int a,b;
		a=q[i].x;
		b=q[i].y;
		if(find(a)!=find(b))
		{
			add(a,b,q[i].qz);
			add(b,a,q[i].qz);
			f[find(a)]=find(f[b]);
			//cout<<a<<" "<<b<<"\n";
			k++;
		}
		if(k==n-1)
		break;
	}
	dfs(1,1);
    c=get_num();
    //cout<<ww[5][1]<<" &&&\n";
	for(int i=1;i<=c;i++)
	{
		int qq,w,ans=0;
		qq=get_num();w=get_num();
		if(find(qq)!=find(w))
		{
			cout<<-1<<"\n";
			continue;
		}
		ans=just_doit(qq,w);
		cout<<ans<<"\n";
	}
	return 0;
}
