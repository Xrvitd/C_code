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
int n,m,x,y;
int a[81][81],f[81][81]; 
int main()
{
	cin>>n>>m>>x>>y;
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			f[i][j]=1;
		}
	}
	f[x][y]=0;
	if(x+1<=n&&y+2<=m) f[x+1][y+2]=0;
	if(x+2<=n&&y+1<=m) f[x+2][y+1]=0;
	if(x-1>=0&&y+2<=m) f[x-1][y+2]=0;
	if(x+1<=n&&y-2>=0) f[x+1][y-2]=0;
	if(x-1>=0&&y-2>=0) f[x-1][y-2]=0;
	if(x-2>=0&&y+1<=m) f[x-2][y+1]=0;
	if(x-2>=0&&y-1>=0) f[x-2][y-1]=0;
	if(x+2<=n&&y-1>=0) f[x+2][y-1]=0;
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			if(i==0&&j==0)
			{
				continue;
			}
			if(!f[i][j])
			{
				continue;
			}
			if(i==0)
			{
				f[i][j]=f[i][j-1];
				continue;
			}
			if(j==0)
			{
				f[i][j]=f[i-1][j];
				continue;
			}
			f[i][j]=f[i-1][j]+f[i][j-1];
		}
	}
   cout<<f[n][m];
}

