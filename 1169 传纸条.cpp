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
int n,m,a[100][100];
int d[101][101][101][101];
int maxx(int q,int w,int e,int r)
{
	if(w>q) q=w;
	if(e>q) q=e;
	if(r>q) q=r;
	return q;
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
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			for(int x=1;x<=n;x++)
			{
				int y=i+j-x;
				d[i][j][x][y]=maxx(d[i-1][j][x-1][y],d[i-1][j][x][y-1],d[i][j-1][x-1][y],d[i][j-1][x][y-1])+a[i][j]+a[x][y];
				if(i==x&&j==y) d[i][j][x][y]-=a[i][j];
			}
		}
	}
	cout<<d[n][m][n][m];

}

