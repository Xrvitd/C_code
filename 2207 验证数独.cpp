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
#include<ctime>
#define INF 1000000000
#define fi first
#define se second
#define N 100005
#define P 1000000007
#define debug(x) cerr<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
#define searchnext(x,y) y==9? dfs(x+1,1):dfs(x,y+1)
using namespace std;
int n=9,m,a[10][10],score=0,ans=-1,b[10][10];
bool h[10][10],l[10][10],g[10][10];
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
bool add(int x,int y ,int k)
{
	if(h[x][k])return 0;
	if(l[y][k])return 0;
	int ll=(x-1)/3*3+(y-1)/3+1;
	if(g[ll][k])return 0;
	h[x][k]=1;
	l[y][k]=1;
	g[ll][k]=1;
	b[x][y]=k;
	return 1;
}
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		memset(h,0,sizeof(h));
		memset(l,0,sizeof(l));
		memset(g,0,sizeof(g));
		bool vv=0;
		for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			if(a[i][j])
			{
				if(!add(i,j,a[i][j]))
				{
					vv=1;
				}
			}
		}
	}
	if(!vv)
	    cout<<"Right\n";
	    else
	    cout<<"Wrong\n";
	}
}
