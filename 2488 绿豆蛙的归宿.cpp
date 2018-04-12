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
int n,p,m,h[100011];
double ans;
stack<int>stac;
struct zqm
{
	int v,next,w;
}q[200001];
void add(int a,int b,int c)
{
	p++;
	q[p].v=b;
	q[p].w=c;
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
void dfs(int x,int s,double kk)
{
	if(x==n)
	{
		ans+=(double)s*kk;
		return;
	}
	int pp=h[x],tot=0;
	while(pp)
	{
		tot++;
		pp=q[pp].next;
	}
	pp=h[x];
	while(pp)
	{
		dfs(q[pp].v,s+q[pp].w,kk/(double)tot);
		pp=q[pp].next;
	}
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int q,w,e;
		cin>>q>>w>>e;
		add(q,w,e);
	}
	dfs(1,0,1);
    printf("%.2lf",ans);
}

