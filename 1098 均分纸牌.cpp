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
int a[10001],ans=0;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		m+=a[i];
	}
	m=m/n;
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=m)
		{
			int k=m-a[i];
			a[i+1]-=k;
			ans++;
		}
	}
	cout<<ans;

}

