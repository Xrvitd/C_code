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
int main()
{
	cin>>n;
	char c;
	cin>>c;
	int ans=0;
	m=c-'A'+1;
	for(int i=1;i<=n;i++)
	{
		int q,w;
		cin>>q>>w;
		if(q<=m&&w>=m)
		{
			ans++;
		}
	}
	cout<<ans;

}

