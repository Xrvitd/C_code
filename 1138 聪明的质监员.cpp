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
long long  n,m,S,W,an=1e18+7,s[200010],d[200010];
struct zqm
{
	long long  w,v;
}q[200010];
struct re
{
	long long  li,ri;
}p[200010];
inline long long  get_num()
{
long long  num = 0;
char c;
bool flag = false;
while ((c = getchar()) == ' ' || c == '\n' || c == '\r');
if (c == '-') flag = true;
else num = c - '0';
while (isdigit(c = getchar()))
num = num * 10 + c - '0';
return (flag ? -1 : 1) * num;
}
long long min(long long a,long long b)
{
	if(a>b)
	return b;
	return a;
}
long long  pd(long long  x)
{
	long long  sum=0,ss=0,ans=0;
	for(int i=1;i<=n;i++)
	{
		if(q[i].w>=x)
		{
			s[i]=s[i-1]+q[i].v;
			d[i]=d[i-1]+1;
		}else
		{
			s[i]=s[i-1];
			d[i]=d[i-1];
		}
	}
	for(long long  i=1;i<=m;i++)
	{
		sum=d[p[i].ri]-d[p[i].li-1];
		ss=s[p[i].ri]-s[p[i].li-1];
		ans+=sum*ss;
	}
	return S-ans;
}
void just_doit()
{
	long long  l=1,r=100001;
	long long  mid;
	while(l<r)
	{
		mid=(l+r)>>1;
		long long  k=pd(mid);
		if(k>0)
		{
			an=min(an,k);
		}else
		{
			an=min(an,-k);
		}
		
		if(k>0)
		{
			r=mid;
		}else
		{
			l=mid+1;
		}
	}
}
int main()
{
	n=get_num();m=get_num();S=get_num();
	for(long long  i=1;i<=n;i++)
	{
		q[i].w=get_num();q[i].v=get_num();
	}
	for(long long  i=1;i<=m;i++)
	{
		p[i].li=get_num();p[i].ri=get_num();
	}
	just_doit();
	cout<<an<<endl;
	//cout<<pd(4);

}

