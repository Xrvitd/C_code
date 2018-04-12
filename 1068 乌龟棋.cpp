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
int n,m,ma=0;
int a[1001],b[5],d[41][41][41][41]; 
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=m;i++)
	{
		cin>>b[0];
		b[b[0]]++;
	}
	for(int i=0;i<=b[1];i++)
	{
		for(int j=0;j<=b[2];j++)
		{
			for(int k=0;k<=b[3];k++)
			{
				for(int l=0;l<=b[4];l++)
				{
					ma=0;
					if(i) ma=ma>d[i-1][j][k][l]? ma:d[i-1][j][k][l];
					if(j) ma=ma>d[i][j-1][k][l]? ma:d[i][j-1][k][l];
					if(k) ma=ma>d[i][j][k-1][l]? ma:d[i][j][k-1][l];
					if(l) ma=ma>d[i][j][k][l-1]? ma:d[i][j][k][l-1];
					d[i][j][k][l]=ma+a[i+j*2+k*3+l*4+1];
				}
			}
		}
	}
	cout<<d[b[1]][b[2]][b[3]][b[4]];

}

