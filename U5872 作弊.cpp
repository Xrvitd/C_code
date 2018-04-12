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
int n,m,a[2001][2001],p,h[2001],t[2001],zz[2001],k=0;
struct zqm
{
	int v,next,w;
}q[40001];
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
void dfs(int x,int ti)
{
	if(ti>=t[x])
	return;
	t[x]=ti;
	int pp=h[x];
	while(pp)
	{
		int k=q[pp].v;
		dfs(k,ti+q[pp].w);
		pp=q[pp].next;
	}
}
int main()
{
	memset(t,127,sizeof(t));
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
    	int q,w,e;
    	cin>>q>>w>>e;
    	if(q==w) 
    	{
    		t[q]=e;
    		zz[++k]=q;
    	}
    	else
    	{
    		add(q,w,e);
    	}
    }
    
    for(int i=1;i<=k;i++)
    {
    	int kk=t[zz[i]];
    	t[zz[i]]=2147483647;
    	dfs(zz[i],kk);
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
    	cout<<t[i]<<" ";
    }
    cout<<ans;
}

