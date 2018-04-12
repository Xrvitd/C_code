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
int n,m,f[1000010],a[100101];
inline int get_num()
{
int num = 0;
char c;
bool flag = false;
while ((c = getchar()) == ' ' || c == '\n' || c == '\r');
if (c == '-') flag = true;
else num = c - '0';
while (isdigit(c = getchar()))
num = num * 10 + c - '0';
return (flag ? -1 : 1) * num;
}
int sum(int x)
{
	int ans=0;
	if(x!=1)
	ans+=f[1];
	ans+=f[x]-1;
	for(int i=2;i<=sqrt(x);i++)
	{
		if(x%i==0&&i*i!=x)
		{
			ans+=f[i];
			ans+=f[x/i]; 
		}else
		if(i*i==x)
		{
			ans+=f[i];
		}
	}
	return ans;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i!=1)
		{
			f[a[i]]++;
		}
	}
	for(int i=1;i<=n;i++)
	cout<<f[i]<<" ";
	cout<<endl;
	for(int i=1;i<=n;i++)
	{
		if(i==1)
		{
			cout<<sum(a[i])+1<<endl;
		}else
		cout<<sum(a[i])<<endl;
	}
}

