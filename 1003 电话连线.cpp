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
int n,m,a[1001][1001],p=0;
int f[101];
struct zqm
{
	int x,y,s;
}q[10001];
bool cmp(zqm a,zqm b)
{
	return a.s>b.s;
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
int find(int x)
{
	return f[x]==x ? x: f[x]=find(f[x]);
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			if(a[i][j]==0)
			{
				f[find(i)]=find(f[j]);
				continue;
			}
			p++;
			q[p].x=i;
			q[p].y=j;
			q[p].s=a[i][j];
		}
	}
    sort(q+1,q+1+n,cmp);
    for(int i=1;i<=n;i++)  f[i]=i;
    for(int i=1;i<=n*n;i++)
    {
    	cout<<q[i].s<<" ";
    }
}

