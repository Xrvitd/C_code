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
int n,m,a[101][101],f[102][102];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=i;j++)
	{
		cin>>a[i][j];
	}
	for(int i=n;i>=1;i--)
	{
		for(int j=1;j<=i;j++)
		{
			f[i][j]=max(f[i+1][j],f[i+1][j+1])+a[i][j];
		}
	}
	cout<<f[1][1];

}

