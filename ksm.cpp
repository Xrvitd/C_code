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
long long n,m,p;
long long ksm(long long a,long long b)
{
	long long ans=1;
	for(;b;a=(a*a)%p,b>>=1)
	{
		if(b & 1)
		{
			ans=ans*(a%p);
			ans%=p;
		}
	}
	return ans%p;
}
int main()
{
    cin>>n>>m>>p;
    cout<<ksm(n,m);
}

