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
long long a[101][101];
int x1,x2,y11,y2;
int main()
{
	cin>>n>>m;
	cin>>x1>>y11>>x2>>y2;
	a[x1][y11]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			//if(i+1<=n&&j+2<=m) a[i][j]+=a[i+1][j+2];
	        //if(i+2<=n&&j+1<=m) a[i][j]+=a[i+2][j+1];
          	if(i-1>=0&&j+2<=m) a[i][j]+=a[i-1][j+2];
	        //if(i+1<=n&&j-2>=0) a[i][j]+=a[i+1][j-2];
        	if(i-1>=0&&j-2>=0) a[i][j]+=a[i-1][j-2];
        	if(i-2>=0&&j+1<=m) a[i][j]+=a[i-2][j+1];
        	if(i-2>=0&&j-1>=0) a[i][j]+=a[i-2][j-1];
        //	if(i+2<=n&&j-1>=0) a[i][j]+=a[i+2][j-1];
		}
	}
	cout<<a[x2][y2];

}

