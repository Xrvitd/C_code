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
int n,m;
struct zqm
{
	int vv,next;
}q[1000001];
bool v[100001];
int h[100001],p,ans,mc[100001];
void add(int a,int b)
{
	p++;
	q[p].vv=b;
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
bool dfs(int x)
{
	int pp=h[x];
	while(pp)
	{
		int k=q[pp].vv;
		if(!v[k])
		{
		v[k]=1;
		if(!mc[k]||dfs(mc[k]))
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
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
    	int k;
    	while(cin>>k)
    	{
    		if(k==0)break;
    		add(i,n+k);
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
    cout<<ans;
     
}

