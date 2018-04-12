#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<cstdlib>
using namespace std;
int n,m,f[50010][40],j[50010][40],deep[50010];
bool rd[1000001],v[50010];
inline int get_num()
{
	int num=0;
	bool flag=0;
	char c;
	while((c=getchar())==' '||c=='\n'||c=='\r');
	if(c=='-')flag=1;
	else num=c-'0';
	while(isdigit(c=getchar()))
	num=num*10+c-'0';
	return (flag ? -1 : 1 )*num;
}
struct zqm
{
	int v,next,w;
}q[1000001];
int p,h[100001];
void add(int a,int b,int c)
{
	p++;
	q[p].v=b;
	q[p].next=h[a];
	h[a]=p;
	q[p].w=c;
}
void dfs(int x,int s)
{
    deep[x]=s;
    for(int i=1;(1<<i)<s;i++)
    {
    	j[x][i]=j[j[x][i-1]][i-1];
    	f[x][i]=f[x][i-1]+f[j[x][i-1]][i-1];
    }
	int pp=h[x];
	while(pp)
	{
		int k=q[pp].v;
		if(v[k])
		{
			pp=q[pp].next;
			continue;
		}
		v[k]=1;
		j[k][0]=x;
		f[k][0]=q[pp].w;
		dfs(k,s+1);
		pp=q[pp].next;
	}
}
int lca(int x,int y)
{
	int ans=0;
	if(deep[y]>deep[x])
	{
		int kkk=x;
		x=y;
		y=kkk;
	}
	for(int i=17;i>=0;i--)
	{
		if(deep[x]-(1<<i)>=deep[y])
		{
			ans+=f[x][i];
			x=j[x][i];
		}
	}
	if(x==y) return ans;
	for(int i=17;i>=0;i--)
	{
		if(deep[x]-(1<<i)>=1&&j[x][i]!=j[y][i])
		{
			ans+=f[x][i]+f[y][i];
			x=j[x][i];
			y=j[y][i];
		}
	}
	if(x!=y)
	ans+=f[x][0]+f[y][0];
	return ans;
}
int main()
{
	n=get_num();
	for(int i=1;i<n;i++)
	{
		int q,w,e;
		q=get_num();w=get_num();e=get_num();
		add(w,q,e);
		add(q,w,e);
	}
   	dfs(0,1);
    m=get_num();
    for(int i=1;i<=m;i++)
    {
    	int w,e;
    	w=get_num();e=get_num();
    	cout<<lca(w,e)<<endl;
    }
	
}
