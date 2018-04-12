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
int n,m,f[101],q[10][10],a[1010];
bool v[10];
long long  sum[10];
long long  ans=1;

long long  dfs(long long  x)
{
	long long  ansm=1;
	for(long long  i=0;i<=9;i++)
	{
		if(!v[i]&&q[x][i])
		{
			v[i]=1;
			ansm+=dfs(i);
		}
	}
	return ansm;
} 
int main()
{
	char c;
	long long  k=0;
	string s;
	cin>>s;k=s.size();
	for(long long  i=0;i<k;i++)
	{
		sum[s[i]-'0']++;
		a[1+i]=s[i]-'0';
	}
	cin>>n;
	for(long long  i=1;i<=n;i++)
	{
		long long  w,e;
		cin>>w>>e;
		q[w][e]=1;
	}
	for(long long  i=1;i<=k;i++)
	{
		memset(v,0,sizeof(v));
		v[a[i]]=1;
		ans*=dfs(a[i]);
	}
	cout<<ans;
}

