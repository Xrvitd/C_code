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
long long n,m,a[300010],t[300010],ans=0;
struct re
{
	long long x,v;
}q[500001];
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
bool cmp(re a,re b)
{
	if(a.x==b.x)
	{
		return a.v>b.v;
	}
	return a.x<b.x;
}
void sorrt(long long l,long long r)
{
	if(l>=r)
	return;
	long long mid=(l+r)>>1;
	sorrt(l,mid);sorrt(mid+1,r);
	long long k=0,ll=l,rr=mid+1;
	while(k<=r-l+1)
	{
		k++;
		if(a[ll]<=a[rr]&&ll<=mid)
		{
			t[k]=a[ll];
			ll++;
		}else
		{
			if(rr<=r)
			{
				t[k]=a[rr];
			    rr++;
			    ans+=mid-ll+1;
			}else
			{
				t[k]=a[ll];ll++;
			}
		}
	}
	for(long long i=l;i<=r;i++)
	{
		a[i]=t[i-l+1];
	}
}
int main()
{
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>q[i].x>>q[i].v;
	}
	sort(q+1,q+1+n,cmp);
	for(long long i=1;i<=n;i++)
	{
		a[i]=q[i].v;
	}
	sorrt(1,n);
	cout<<ans;
}

