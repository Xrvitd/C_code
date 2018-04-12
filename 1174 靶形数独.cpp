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
int getscore(int x,int y,int k)
{
	if(x==y&&x==5)
	{
		return k*10;
	}
	if(x==1||x==n||y==1||y==n)return 6*k;
	if(x==2||x==8||y==2||y==8)return 7*k;
	if(x==3||x==7||y==3||y==7)return 8*k;
	if(x==4||x==6||y==4||y==6)return 9*k;
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
	score+=getscore(x,y,k);
	return 1;
}
void del(int x,int y,int k)
{
	h[x][k]=0;
	l[y][k]=0;
	g[(x-1)/3*3+(y-1)/3+1][k]=0;
	b[x][y]=0;
}
void dfs(int x,int y)
{
	//if(clock()>1000)return;
	if(x==10&&y==1)
	{
		ans=max(ans,score);
		return;
	}
	if(b[x][y])
	{
		searchnext(x,y);
	}else
	{
		for(int i=1;i<=9;i++)
		{
			int t=score;
			if(add(x,y,i))
			{
				searchnext(x,y);
				del(x,y,i);
				score=t;
			}
			
		}
	}
}
int main()
{
	for(int i=n;i>=1;i--)
	{
		for(int j=n;j>=1;j--)
		{
			cin>>a[i][j];
			if(a[i][j])
			{
				add(i,j,a[i][j]);
			}
		}
	}
	dfs(1,1);
    cout<<ans;
}

