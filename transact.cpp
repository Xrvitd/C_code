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
struct zqm
{
	int  t,d;
}q[200010];
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
bool cmp(zqm a ,zqm b )
{
	return a.d<b.d;
}
bool pd(int x)
{
	int tim=0;
	int ma=0;
	for(int i=1;i<=n;i++)
	{
		tim+=q[i].t;
		ma=max(ma,tim-q[i].d);
		if(ma>x)
		return 0;
	}
	return 1;
	
}
void just_doit()
{
	int l=1,r=1000000009;
	int mid;
	while(l<r)
	{
		mid=(l+r)>>1;
		
		if(pd(mid))
		{
			r=mid;
		}else
		{
			l=mid+1;
		}
	}
	cout<<l;
}
int main()
{
	freopen("transact.in","r",stdin);
	freopen("transact.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>q[i].t;
	} 
    for(int i=1;i<=n;i++)
	{
		cin>>q[i].d;
	} 
	sort(q+1,q+1+n,cmp);
	just_doit();
	for(int i=1;i<=n;i++)
	{
	//	cout<<q[i].t<<" ";
	} 
}

