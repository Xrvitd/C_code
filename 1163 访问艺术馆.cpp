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
int n,m,k=1,a[1001],f[1001][1001],l[1001],r[1001],d[1001],b[1001][1001];
int s;
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
	int w,e,rr,t;
	cin>>w>>e;
	k++;
	if(e==0)
	{
		l[x]=k;
		d[k]=d[x]+w;
		b[x][k]=w;
		dfs(k);
	} else
	{
		l[x]=k;
		d[k]=d[x]+w;
		b[x][k]=w;
		a[k]=e;
	}
	cin>>rr>>t;
	k++;
	if(t==0)
	{
		d[k]=d[x]+rr;
		b[x][k]=rr;
		r[x]=k;
		dfs(k);
	}else
	{
		r[x]=k;
		d[k]=d[x]+rr;
		b[x][k]=rr;
		a[k]=t;
	}
}
void tree_dp(int x)
{
	if(d[x]>s)
	{
		return;
	}
	if(x==0) return;
	if(l[x]==0)
	{
		for(int j=1;j<=s-2*d[x]-a[x]*5;j++)
		{
			f[x][j]=a[x];
		}
		return; 
	}
	tree_dp(l[x]);
	tree_dp(r[x]);
	for(int j=1;j<=s-2*d[x];j++)
	{
		if(j>=0)
		f[x][j]=max(f[l[x]][j-2*b[x][l[x]]],f[r[x]][j-2*b[x][r[x]]]);
	}
}
int main()
{
	cin>>s;
	cin>>n>>m;
	if(m!=0)
	{
		if(n<=s)
		{
			cout<<m;
			return 0;
		}else
		{
			cout<<0;
			return 0;
		}
	}
	l[0]=1;
	d[1]=n;
	dfs(1);
	tree_dp(1);
	/*for(int i=1;i<=k;i++)
	{
		cout<<d[i]<<" ";
	}cout<<endl;
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=s;j++)
		{
			cout<<f[i][j];
		}
		cout<<endl;
	}
	cout<<endl;*/
	int ans=0;
	for(int i=0;i<=s-2*n;i++)
	{
		ans=max(ans,f[1][i]);
	}
	cout<<ans;
}

