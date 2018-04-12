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
int n,m,rd[500010],fa[500010],w[500010],bh[500010],k,kk,ans=0,son[500010],ma[500010],p,jian[500010],f[500010];
bool v[500010],vv[500010];
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
int find(int x)
{
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
void dfs(int x,int s)
{
	if(bh[x]!=0)
	{
		k=x;
		kk=s-bh[x];
		return;
	}
	bh[x]=s;
	dfs(fa[x],s+1);
}
void doit(int x)
{
	while(1)
	{
		if(v[fa[x]])
		{
			ma[fa[x]]=max(ma[fa[x]],ma[x]+w[x]);
			p=fa[x];
			break;
		}
		if(ma[fa[x]]<ma[x]+w[x])
		{
		    ma[fa[x]]=ma[x]+w[x];
		    x=fa[x];
		}else
		{
			break;
		}
	}
}
void ph(int x,int ff)
{
	dfs(x,1);
	int sum=0;
	while(kk--)
	{
		//cout<<k<< " ";
		v[k]=1;
		jian[fa[k]]=w[k];
		sum+=w[k];
		k=fa[k];
	}
	ans=max(ans,sum);
	//cout<<"sum : "<<sum<<endl;
	for(int i=1;i<=n;i++)
	{
		if(!rd[i]&&f[i]==ff)
		{
			doit(i);
			int qw=0;
			//cout<<i<<" "<<ma[p]<<"\n";
			qw=sum+ma[p]-jian[p];
			ans=max(ans,qw);
		}
	}
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>fa[i];
		cin>>w[i];
		son[fa[i]]=i;
		rd[fa[i]]++;
		int a=i,b=fa[i];
		f[find(a)]=find(f[b]);
	}
	for(int i=1;i<=n;i++)
	{
		if(!vv[f[i]])
		{
			vv[f[i]]=1;
			ph(i,f[i]);
		}
	}
    cout<<ans;
}

