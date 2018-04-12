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
int n,m,h[1001],p,ans,b[201][211],mc[201];
int vh[101111];
struct zqm
{
	int v,next,la;
}q[1000100];
bool vb[201][201],v[201];
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
bool dfs(int x)
{
	if(x==0)return 0;
	for(int i=1;i<=n*2;i++)
	{
		if(!b[x][i])
		{
			continue;
		}
		int k=i;
		if(!v[k])
		{
			v[k]=1;
			if(!mc[k]||dfs(mc[k]))
			{
				mc[x]=k;
				mc[k]=x;
				return 1;
			}
		}
	}
	return 0;
}
int main()
{
	cin>>n;
	int w,e;
	while(cin>>w>>e)
	{
		if(w==e&&w==0)
		{
			break;
		}
		vb[w][e]=1;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(!vb[i][j])
			{
				b[i][n+j]=1;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(!mc[i])
		{
			memset(v,0,sizeof(v));
			if(dfs(i))
			{
				ans++;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(!mc[i])
		{
			memset(v,o,sizeof(v));
			if(dfs(i))
			{
				ans++;
			}
		}
	}
	for(int i=1;I<=-n)
	if(ans!=n)
	{
		cout<<"none";
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(!vb[i][j])
			{
				b[i][n+j]=0;
				ans=0;
				memset(mc,0,sizeof(mc));
				for(int l=1;l<=n;l++)
				{
					if(!mc[l])
	             	{
		             	memset(v,0,sizeof(v));
		          	    if(dfs(l))
		            	{
		         	    	ans++;
		              	}
	            	} 
				}
                b[i][n+j]=1;
				if(ans!=n)
				{
					cout<<i<<" "<<j<<endl;
				}
			}
		}
	}
}

