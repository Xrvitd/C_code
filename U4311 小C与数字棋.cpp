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
int n,m,d;
int a[1001][1001];
int f[1001][1001]; 
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
	for(int i=1;i<=n;i++) f[i][1]=f[i-1][1]+a[i][1];
	for(int i=1;i<=m;i++) f[1][i]=f[1][i-1]+a[1][i];
	for(int i=2;i<=n;i++)
	{
		for(int j=2;j<=m;j++)
		{
			f[i][j]=f[i-1][j]+f[i][j-1]-f[i-1][j-1]+a[i][j];
		}
	}

	cin>>d;
	for(int i=1;i<=d;i++)
	{
		int q,w,e,r;
		cin>>q>>w>>e>>r;
		cout<<f[e][r]-f[q-1][w]-f[q][w-1]+f[q-1][w-1]<<endl;
	}
	

}

