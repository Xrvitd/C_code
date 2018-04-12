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
long long  n,m,aa,b,k,p=10007;
int   a[1001][1001];
void just_doit()
{
	a[0][0]=1;
	for(int   i=1;i<=k;i++) a[i][0]=1;
	for(int   i=1;i<=k;i++)
	{
		for(int   j=1;j<=i;j++)
		{
			a[i][j]=a[i-1][j-1]%p+a[i-1][j]%p;
			a[i][j]%=p;
		}
	}
}
int   ksm(int   a,int   b)
{
	int   ans=1;
	for(;b;a=(a*a)%p,b>>=1)
	{
		if(b&1)
		{
			ans=(ans*a)%p; 
		}
	}
	return ans%p;
}
int main()
{
	cin>>aa>>b>>k>>n>>m;
	aa%=p;
	b%=p;
	just_doit();
	int   ans=1;
	ans=(ksm(aa,n)*ksm(b,m))%p;
	ans=ans*a[k][n];
	ans%=p;
	cout<<ans;
    
}

