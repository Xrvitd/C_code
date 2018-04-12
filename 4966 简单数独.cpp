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
#define searchnext(x,y) y==4? dfs(x+1,1):dfs(x,y+1)
using namespace std;
int n=4,m,a[10][10],score=0,ans=-1,b[10][10];
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
	int ll=(x-1)/2*2+(y-1)/2+1;
	if(g[ll][k])return 0;
	h[x][k]=1;
	l[y][k]=1;
	g[ll][k]=1;
	b[x][y]=k;
	return 1;
}
void del(int x,int y,int k)
{
	h[x][k]=0;
	l[y][k]=0;
	g[(x-1)/2*2+(y-1)/2+1][k]=0;
	b[x][y]=0;
}
bool vv=0;
void dfs(int x,int y)
{
	if(vv)return;
	//if(clock()>1000)return;
	if(x==5&&y==1)
	{
		for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout<<b[i][j]<< " ";
		}cout<<endl;
	}
		vv=1;
		return;
	}
	if(b[x][y])
	{
		searchnext(x,y);
	}else
	{
		for(int i=1;i<=4;i++)
		{
			if(add(x,y,i))
			{
				searchnext(x,y);
				del(x,y,i);
			}
			
		}
	}
}
int main()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			if(a[i][j])
			{
				add(i,j,a[i][j]);
			}
		}
	}
	dfs(1,1);

}
