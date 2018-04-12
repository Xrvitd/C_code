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
int n,m[111],k,ans,s;
int a[111][111];
int b[111][111];
int d[111111],dd=0; 
bool v[111];
struct re
{
	int x,c;
}q[111111];
int now[111];

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
bool cmp(re w,re e)
{
	return w.x<e.x;
}
void dfs(int x,int ss,int o)
{
	if(o==n)
	{
		ans++;
		d[ans]=ss+s;
	}
	for(int i=x+1;i<=dd;i++)
	{
		if(!v[q[i].c])
		{
			v[q[i].c]=1;
			dfs(i,ss+q[i].x,o+1);
			v[q[i].c]=0;
		}
	}
}
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>m[i];
		for(int j=1;j<=m[i];j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m[i];j++)
		{
			dd++;
			b[i][j]=a[i][j]-a[i][1];
			q[dd].x=b[i][j];
			q[dd].c=i;
		}
	}
	sort(q+1,dd+1+q,cmp);
	for(int i=1;i<=n;i++)
	{
		s+=a[i][1];
	}
	int ma=0;
	dfs(0,0,0);
	sort(d+1,d+1+ans);
	for(int i=1;i<=k;i++)
	{
		cout<<d[i]<<" ";
	}
}

