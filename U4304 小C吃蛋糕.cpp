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
long long n,m,ans=0,a[100];
void dfs(long long k)
{
	if(k>n) return;
	if(k==n)
	{
		ans++;return;
	}
	if(!a[k+1])
	{
		long long l=ans;
		dfs(k+1);
		l=ans-l;
		a[k+1]=l;
	}else ans+=a[k+1];
	if(!a[k+2])
	{
		long long l=ans;
		dfs(k+2);
		l=ans-l;
		a[k+2]=l;
	}else ans+=a[k+2];
	if(!a[k+3])
	{
		long long l=ans;
		dfs(k+3);
		l=ans-l;
		a[k+3]=l;
	}else ans+=a[k+3];
}
int main()
{
	cin>>n; 
	dfs(0);
    cout<<ans;
}

