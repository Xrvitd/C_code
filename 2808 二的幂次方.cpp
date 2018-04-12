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
long long a[50];
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
long long c(long long x)
{
	if(a[x])
    return a[x];
    long long sum=1;
    for(long long i=1;i<=x;i++)
    sum*=2;
    return a[x]=sum;
}
void dfs(long long x)
{
	if(x==0)
	{
		cout<<0;
		return;
	}
	for(long long i=49;i>=0;i--)
	{
		if(c(i)<x)
		{
			if(i==1)
			{
				cout<<"2+";
				x-=2;
				continue;
			}
			x-=c(i);
			cout<<"2(";
			dfs(i);
			cout<<")+";
		}
		if(c(i)==x)
		{
			if(i==33)
			{
				cout<<" #$%";
			}
			if(i==1)
			{
				cout<<2;
				x-=2;
				continue;
			}
			x-=c(i);
			cout<<"2(";
			dfs(i);
			cout<<")";
		}
	}
}
int main()
{
	cin>>n;
	dfs(n); 
}

