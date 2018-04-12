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
int h[N],p,next[N],w[N],v[N];
bool f[1001][1001],vv[1001][1001],ans=1; 
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
struct zqm
{
	int x,y;
}q[100001];
void add(int a,int b)
{
	p++;
	v[p]=b;
	next[p]=h[a];
	h[a]=p;
}
void dfs(int a,int b)
{
	//cout<<"::"<<a<<" "<<b<<endl;
	if(!ans)return;
	p=h[b];
	int k=v[p];
	while(p)
	{
		k=v[p];
		if(k==a)
		{
			p=next[p];
			continue;
		}
		if(!f[a][k])
		{
			ans=0;
			return;
		}else
		{
			if(!vv[b][k])
		    {
			    vv[b][k]=1;
			    dfs(b,k);
		    }
		}
		p=next[p];
	}
	return;
}
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		ans=1;
		p=0;
		memset(h,0,sizeof(h));
		memset(v,0,sizeof(v));
		memset(next,0,sizeof(next));
		memset(q,0,sizeof(q));
		memset(vv,0,sizeof(vv));
		memset(f,0,sizeof(f));
		cin>>n>>m;
		for(int i=1;i<=m;i++)
		{
			int qq,w;
			cin>>qq>>w;
			q[i].x=qq;
			q[i].y=w;
			f[qq][w]=1;
			add(qq,w);
		}
		for(int i=1;i<=m;i++)
	    {
	    	int tx=q[i].x,ty=q[i].y;
	    	if(!vv[tx][ty])
	    	{
	    		vv[tx][ty]=1;
	    		dfs(tx,ty);
	    		if(!ans)
	    		{
	    			break;
	    		}
	    	}
	    }
		if(!ans)
	    {
	    	cout<<"No\n";
	   	} else
	   	{
	   		cout<<"Yes\n";
	   	}
	}

}
