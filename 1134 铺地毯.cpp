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
int n,m,ans=-1;
int xx,yy;
struct zqm
{
	int x,y,s,k;
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
int main()
{
    n=get_num();
	for(int i=1;i<=n;i++)
	{
		a[i].x=get_num();a[i].y=get_num();
		a[i].s=get_num();a[i].k=get_num();
	}
    cin>>xx>>yy;
    for(int i=n;i>=1;i--)
    {
    	if(a[i].x<=xx&&a[i].y<=yy&&(a[i].s+a[i].x-1)>=xx&&(a[i].k+a[i].y-1)>=yy)
    	{
    		cout<<i;
			return 0; 
    	}
    }
    cout<<-1;
}

