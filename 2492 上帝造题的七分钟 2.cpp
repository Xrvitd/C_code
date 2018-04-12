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
long long a[1000010];
long long c[1000010];
long long f[1000010];
long long find(long long x)
{
	if(f[x]==x) return x;
	else
	f[x]=find(f[x]);
	return f[x];
}
long long lowbit(long long x)
{
	return x&-x;
} 
void add(long long x,long long k)
{
	while(x<=n)
    {
        c[x]+=k;
        x+=lowbit(x);
    }
}
long long sum(long long x)
{
    long long su=0;
	while(x)
	{
		su+=c[x];
		x-=lowbit(x);
	}	
	return su;
} 
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
    	a[i]=get_num();
    	add(i,a[i]);
    }
    cin>>m;
    for(long long i=1;i<=n;i++)
    {
    	f[i]=i;
    }
    for(long long i=1;i<=m;i++)
    {
    	long long q,w,e;
    	q=get_num();w=get_num();e=get_num();
    	if(w>e)
    	{
    		long long kkk=w;
    		w=e;
    		e=kkk;
    	}
    	if(q==0)
    	{
    		long long x=w;
    		while(x<=e)
			{
				long long qw=a[x];
				a[x]=sqrt(a[x]);
				add(x,a[x]-qw);
				if(a[x]==1)
				{
					f[find(x)]=find(f[x+1]);
				}
				x=f[x+1];
				if(f[x]==0)
				{
					break;
				}
			} 
    	}else
    	{
    		cout<<sum(e)-sum(w-1)<<"\n";
    	}
    }
}
