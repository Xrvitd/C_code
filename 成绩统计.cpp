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
struct re
{
	int x,p,yc;
}a[100001];
bool cam(re q,re w)
{
	return q.x>w.x;
}
bool cm(re q,re w)
{
	return q.yc<w.yc;
}
int main()
{
    freopen("ycj.txt","r",stdin);
    freopen("pm.txt","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
    	a[i].x=get_num();
    	a[i].yc=i;
    }
    sort(a+1,a+1+n,cam);
    m=1;
    a[1].p=1;
    for(int i=2;i<=n;i++)
    {
    	if(a[i].x==a[i-1].x)
    	{
    		a[i].p=m;
    	}else
    	{
    		m++;
    		a[i].p=m;
    	}
    }
    sort(a+1,a+1+n,cm);
    for(int i=1;i<=n;i++)
    {
    	cout<<a[i].p<<"\n";
    }
}

