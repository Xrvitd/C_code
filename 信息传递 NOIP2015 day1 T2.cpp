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
int n,m;
int fa[200001],f[200001],a[200001],ans=2147483647; 
bool v[200001];
int find(int x)
{
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
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
void dfs(int x,int s)
{
	if(a[x]>0)
	{
		ans=min(ans,s-a[x]);
		return;
	}
	a[x]=s;
	dfs(fa[x],s+1);
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	f[i]=i;
	for(int i=1;i<=n;i++)
	{
		int q;
		cin>>q;
		fa[i]=q;
		f[find(i)]=find(f[q]);
	}
	for(int i=1;i<=n;i++)
	{
		int k=find(i);
		if(!v[k])
		{
			v[k]=1;
			dfs(k,1);
		}
	}
	cout<<ans;

}

