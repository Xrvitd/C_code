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
int n,m,ans;
struct zqm
{
	int d,h;
}q[100010];
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
bool cmp(zqm a,zqm b)
{
	return a.d<b.d;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>q[i].d>>q[i].h;
		ans=max(ans,q[i].h);
	}
	sort(q+1,q+1+m,cmp);
	ans=max(ans,q[1].h+q[1].d-1);
	for(int i=2;i<=m;i++)
	{
		if(abs(q[i].h-q[i-1].h)>q[i].d-q[i-1].d)
		{
			cout<<"IMPOSSIBLE";
			return 0;
		}
		int z=q[i].d-q[i-1].d-1;
		if(z)
		{
			if(q[i].h==q[i-1].h)
			{
				ans=max(ans,q[i].h+(z+1)/2);
			}
			if(q[i].h<q[i-1].h)
			{
				z-=q[i-1].h-q[i].h;
				if(z<=0)continue;
				ans=max(ans,q[i].h+(z+1)/2);
			}else
			{
				z-=q[i].h-q[i-1].h;
				if(z<=0)continue;
				ans=max(ans,q[i].h+(z+1)/2);
			}
		}
	}
    cout<<ans;
}

