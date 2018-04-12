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
int n,m,mc[101],h[1001],p=0,ma[101][101],b=0,dian[101][101];
bool v[1001];
int fx[5]={0,1,-1,0,0};
int fy[5]={0,0,0,1,-1};
struct zqm
{
	int to,fr,next;
}q[10001];
struct re
{
	int x,y;
}bian[100001];
void add(int a,int b)
{
	p++;
	q[p].to=b;
	q[p].fr=a;
	q[p].next=h[a];
	h[a]=p;
}
bool dfs(int x)
{
	if(x==0)return 0;
    int pp=h[x];
	while(pp)
    {
    	int k=q[pp].to;
    	if(!v[k])
    	{
    		v[k]=1;
    		if(mc[k]==0||dfs(k))
    		{
    			mc[k]=x;
    			mc[x]=k;
    			return 1;
    		}
    	}
    	pp=q[pp].next;
    }
    return 0;
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
int main()
{
	cin>>n>>m;
	int k;
	cin>>k;
	for(int i=1;i<=k;i++)
	{
		int q,w;
		cin>>q>>w;
		ma[q][w]=1;
		
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			//cout<<ma[i][j]<<" ";
			if(!ma[i][j])
			{
				b++;
				bian[b].x=i;
	        	bian[b].y=j;
	        	dian[i][j]=b;
			}
		}
		//cout<<endl;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(!ma[i][j])
			for(int k=1;k<=4;k++)
			{
				int tx=i+fx[k],ty=j+fy[k];
				if(tx>0&&tx<=n&&ty>0&&ty<=m&&!ma[tx][ty])
				{
					add(dian[i][j],dian[tx][ty]);
				}
			}
		}
	}
	int ans=0;
	for(int i=1;i<=b;i++)
	{
		if(mc[i]==0)
		{
			memset(v,0,sizeof(v));
			if(dfs(i))
			{
				//cout<<i<<" ";
				ans++;
			}
		}
	}
    cout<<ans;
}

