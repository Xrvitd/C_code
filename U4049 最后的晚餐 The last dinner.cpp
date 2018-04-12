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
int spoon[105],chopsticks[105],swap1[105],f[105][2]; 
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>spoon[i]>>chopsticks[i]>>swap1[i];
	}
	f[0][1]=0;
	f[0][0]=swap1[1];
	for(int i=1;i<=n;i++)
	{
		f[i][0]=f[i-1][0]+spoon[i];
		f[i][1]=f[i-1][1]+chopsticks[i];
		f[i][0]=min(f[i][0],f[i][1]+swap1[i+1]);
		f[i][1]=min(f[i][1],f[i][0]+swap1[i+1]);
	}
	cout<<min(f[n][0],f[n][1])<<endl;
}
