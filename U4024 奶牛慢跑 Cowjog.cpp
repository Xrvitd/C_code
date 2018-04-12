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
int n,m,ans=0;
struct re
{
	int x,v;
}a[100001];
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
bool cam(re x,re y)
{
	return x.x<y.x;
}
int main()
{
	n=get_num();
	for(int i=1;i<=n;i++)
	{
		a[i].x=get_num();
		a[i].v=get_num();
	}
	sort(a+1,a+1+n,cam);
	m=2147483647;
	for(int i=1;i<=n;i++)
	{
		if(m>=a[i].v)
		{
			ans++;
			m=a[i].v;
		}
	}
	cout<<ans;

}

