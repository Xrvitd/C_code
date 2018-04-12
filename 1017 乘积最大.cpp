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
string s;
int f[101][101],a[101][101],l[101][101];
int main()
{
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			a[i][j]=a[i][j-1]*10+s[j-1]-'0';
		}
	}
	for(int i=1;i<=n;i++)
	{	
		f[i][0]=a[1][i];
	//	cout<<f[i][0]<< " ";
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<i;j++)
		{
			for(int k=1;k<i;k++)
			{
				f[i][j]=max(f[i][j],f[k][j-1]*a[k+1][i]);
			}
		}
	}
	//cout<<" ====================\n";
	cout<<f[n][m];

}

