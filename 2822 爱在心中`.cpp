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
int n,m,p=0,h[100010],clock=0,low[100010],dfn[100010],scc_num=0,scc[100010],zh[100010],top=0,col[100010],tcd[100010],ren;
struct zqm
{
	int v,next;
}q[100010];
bool ifr[100010];
void add(int a,int b)
{
	p++;
	q[p].v=b;
	q[p].next=h[a];
	h[a]=p;
}
bool f[100010];
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
void init()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
    	int q,w;
    	cin>>q>>w;
    	add(q,w);
    }
}
void dfs(int x)
{
	clock++;
	low[x]=dfn[x]=clock;
	top++;
	zh[top]=x;
	int wp=h[x];
	while(wp)
	{
		int y=q[wp].v;
		if(!dfn[y])
		{
			dfs(y);
			low[x]=min(low[x],low[y]);
		}else
		{
			if(!f[y])
			low[x]=min(low[x],dfn[y]);
		}
		wp=q[wp].next;
	}
	if(low[x]==dfn[x])
	{
		scc_num++;
		int l=top;
		while(1)
		{
			int k=zh[top];
			f[k]=1;
			top--;
			col[k]=scc_num;
			scc[scc_num]++;
			if(x==k)break;
		}
		if(scc[scc_num]==1)
		{
			ren++;
			ifr[scc_num]=1;
		}
		bool vv=1;
		while(vv)
		{
			int k=zh[l];
			int qq=h[k];
			while(qq)
			{
				if(col[q[qq].v]!=scc_num)
				{
					tcd[scc_num]=1;
					vv=0;
					break;
				}
				qq=q[qq].next;
			}
		    l--;
		    if(x==k)break;
		}
	}
}
void just_doit()
{
	for(int i=1;i<=n;i++)
	{
		if(!dfn[i])
		dfs(i);
	}
}
int main()
{
	init(); 
    just_doit();
    bool pp=0;
    int ans=-1;
    for(int i=1;i<=scc_num;i++)
    {
    	if(tcd[i]==0&&!pp&&!ifr[i])
    	{
    		ans=i;
    		pp=1;
    		continue;
    	}
    	if(tcd[i]==0&&pp&&!ifr[i])
    	{
    		ans=-1;
    		break;
    	}
    }
    cout<<scc_num-ren<<endl;
    if(ans==-1)
    {
    	cout<<ans;
    	return 0;
    }else
    {
    	for(int i=1;i<=n;i++)
    	{
    		if(col[i]==ans)
    		{
    			cout<<i<<" ";
			}
    	}
    }
}

