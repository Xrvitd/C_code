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
long long n,m;
long long a[500010],c[500011],d[500011],b[500011];
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
long long lowbit(long long x)
{
	return x&-x;
}
void make(long long b[],long long x,long long k)
{
	while(x<=n)
	{
		b[x]+=k;
		x+=lowbit(x);
	}
}
long long sum(long long b[],long long x)
{
	long long su=0;
	while(x)
	{
		su+=b[x];
		x-=lowbit(x);
	}
	return su;
}
int main()
{
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=a[i]-a[i-1];
	}
	for(long long i=1;i<=n;i++)
	{
		make(c,i,b[i]);
		make(d,i,i*b[i]);
	}
    for(long long i=1;i<=m;i++)
    {
    	char ch;
    	cin>>ch;
    	if(ch=='C')
    	{
    		long long q,w,e;
    		cin>>q>>w>>e;
    		b[q]+=e;
    		b[w+1]-=e;
    		make(c,q,e);
    		make(d,q,q*e);
    		make(c,w+1,-e);
    		make(d,w+1,-(w+1)*e);
    	}
    	else
    	{
    		long long q,w;
    		cin>>q>>w;
    		long long ans=0;
    		ans=((w+1)*sum(c,w)-sum(d,w))-((q)*sum(c,q-1)-sum(d,q-1));
    		cout<<ans<<endl;
    	}
    }
}

