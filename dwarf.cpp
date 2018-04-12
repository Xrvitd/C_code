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
long long n,m,p=0,h[100001],c[100001];
struct re
{
	long long v1,v2,next;
}q[100001];
void add(long long a,long long b,long long d)
{
	p++;
	q[p].v1=a;
	q[p].v2=b;
	q[p].next=h[d];
	h[d]=p;
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
long long dfs(long long x)
{
	long long pp=h[x];
	while(pp)
	{
		long long k=dfs(q[pp].v1)+dfs(q[pp].v2);
		c[x]=min(c[x],k);
	}		pp=q[pp].next;

	return c[x];
}
int main()
{
     cin>>n>>m;
	 for(long long i=1;i<=n;i++)
	 cin>>c[i];
	 for(long long i=1;i<=m;i++)
	 {
	 	long long q,w,e;
	 	cin>>q>>w>>e;
	 	add(w,e,q);
	 }
	 cout<<dfs(1);
}

