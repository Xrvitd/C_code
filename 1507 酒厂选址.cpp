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
int n,m,k;
long long z[30001],d[30001],c[30001];
inline long long get_num()
{
long long num = 0;
char c;
bool flag = false;
while ((c = getchar()) == ' ' || c == '\n' || c == '\r');
if (c == '-') flag = true;
else num = c - '0';
while (isdigit(c = getchar()))
num = num * 10 + c - '0';
return (flag ? -1 : 1) * num;
}
int main()
{
	cin>>n; 
    for(long long i=1;i<=n;i++)
    {
    	long long q,w;
    	cin>>z[i]>>d[i];
    }
    for(long long i=1;i<=n;i++)
    {
    	z[i+n]=z[i];
    	d[n+i]=d[i];
    	k+=d[i];
    }
    long long ans=1147483647000000000;
    for(long long i=1;i<=n;i++)
	{
		long long l=d[i],s=0;
		for(long long j=i+1;j<=i+n-1;j++)
		{
			if(l<=k-l)
			{
				s+=l*z[j];
			l+=d[j];
			}else
			{
				s+=(k-l)*z[j];
			l+=d[j];
			}
		}
		ans=min(ans,s);
	} 
    cout<<ans;
}

