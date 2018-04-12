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
int n,m,a[15][15],h=0,t=1,ans=2147483647,xx,yy;
bool v[15][15];
int fx[5]={0,1,-1,0,0};
int fy[5]={0,0,0,1,-1};
struct zqm
{
	int x,y,s,l;
}q[100001];
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
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
		}
    }
    cin>>q[1].x>>q[1].y>>xx>>yy;
    q[1].x+=1;
    q[1].y+=1;
    xx+=1;
    yy+=1;
    v[q[1].x][q[1].y]=1;
    q[1].s=0;
    q[1].l=0;
    while(h<=t)
    {
    	h++;
    	//cout<<q[h].x<<" "<<q[h].y<<endl;
    	if(q[h].x==xx&&q[h].y==yy)
    	{
    		ans=min(ans,q[h].s);
    	}
    	if(q[h].l>n+m-2)
    	{
    		continue;
    	}
    	for(int i=1;i<=4;i++)
    	{
    		int tx=q[h].x+fx[i],ty=q[h].y+fy[i];
    	    if(tx>0&&tx<=n&&ty>0&&ty<=m)
    	    {
    	    	if(!a[tx][ty])
    	    	{
    	    		if(!v[tx][ty])
    	    		{
    	    			v[tx][ty]=1;
    	    			t++;
    	    			q[t].x=tx;
    	    			q[t].y=ty;
    	    			q[t].s=q[h].s;
    	    			q[t].l=q[h].l+1;
    	    		}
    	    	}else
    	    	{
    	    		if(!v[tx][ty])
    	    		{
    	    			v[tx][ty]=1;
    	    			t++;
    	    			q[t].x=tx;
    	    			q[t].y=ty;
    	    			q[t].s=q[h].s+1;
    	    			q[t].l=q[h].l+1;
    	    		}
    	    	}
    	    }
    	}
    }
    cout<<ans;
}

