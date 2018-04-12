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
int n,m,p,h[100010],fa[1001],ans=0;
struct zqm
{
	int v,next,w;
}q[100010];
void add(int a,int b)
{
	p++;
	q[p].v=b;
	q[p].next=h[a];
	h[a]=p;
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
int dfs(int x)
{
	int k=h[x],sum=1,ma=0;
//	cout<<x<<" ";
	while(k)
	{
		int y=q[k].v;
		q[k].w=dfs(y);
		sum+=q[k].w;
		ma=max(ma,q[k].w);
		k=q[k].next;
	}
	return sum-ma;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int q,w;
		cin>>q>>w;
		fa[w]=q;
		add(q,w);
	}
	
	cout<<dfs(1);


}

