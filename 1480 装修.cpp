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
int n,m,f[12][12]={0};
int main()
{
	f[1][2]=1;
	f[2][1]=1;
	for(int i=1;i<=11;i++)
	{
		for(int j=1;j<=11;j++)
		{
			if(i-1>0&&j-2>0)f[i][j]+=f[i-1][j-2];
			if(i-2>0&&j-1>0)f[i][j]+=f[i-2][j-1];
		}
	} 
	while(cin>>n>>m)
	{
		cout<<f[n][m]<<"\n";
	}

}

