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
int a[10001],b[10001];
int f[10001];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
	    b[i]=a[i]-a[i-1];
	}
	for(int i=1;i<=n-3;i++)
	{
		f[i]=max(max(b[i+1],b[i+2]),b[i+3]);
	}
	m=f[1];
	for(int i=1;i<=n-3;i++)
	{
		m=min(m,f[i]);
	}
cout<<m;
}

