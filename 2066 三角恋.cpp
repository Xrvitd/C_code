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
using namespace std;
int n,m,h[10000001],v[10000001],next[10000001],p,ans[4];
bool a[5001][5001],f[5000001],vl=0,vv[50001];
int add(int x,int y)
{
	p++;
	v[p]=y;
	next[p]=h[x];
	h[x]=p;
}
void df(int x,int l)
{
	if(vl)return ;
	p=h[x];
	while(p)
	{
		if(a[v[p]][l])
		{
			vl=1;
			ans[1]=l;
			ans[2]=x;
			ans[3]=v[p];
			return;
		}
		p=next[p];
	}
	
}
void dfs(int x)
{
	if(vl) return ;
	p=h[x];
	
	while(p)
	{
		if(!vv[v[p]])
		{
			df(v[p],x);
			vv[v[p]]=1;
		}
		
		p=next[p];
		if(vl) return ;
	}
	
	return ;
}

int main()
{
	int ll;
	cin>>ll;
	for(int ii=1;ii<=ll;ii++)
	{
		vl=0;
		memset(ans,0,sizeof(ans));
		memset(h,0,sizeof(h));
		memset(v,0,sizeof(v));memset(vv,0,sizeof(vv));
		memset(next,0,sizeof(next));
		cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			char c;
			cin>>c;
			a[i][j]=c-'0';
			if(a[i][j]==1)
			{
				add(i,j);
				f[i]=1;
			}
		}
	}
	/*for(int i=1;i<=n;i++)
	{
		cout<<h[i]<<" ";
	}cout<<endl;*/
	for(int i=1;i<=n;i++)
	{
		if(f[i]&&!vl)
		{
			dfs(i);
			vv[i]=1;
		}
	}
	if(vl)cout<<"Yes\n";
	else cout<<"No\n";
	
	}
}

