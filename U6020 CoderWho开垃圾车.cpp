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
int n,m,k;
int a[1001][1001],f[1001][1001];
struct zqm
{
	int x,y,s;
}q[1011];
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
bool cp(zqm a,zqm b)
{
	return a.x<b.x;
}
bool ccp(zqm a,zqm b)
{
	return a.y<b.y;
}
int main()
{
    cin>>n>>m>>k;
    for(int i=1;i<=k;i++)
    {
    	cin>>q[i].x>>q[i].y>>q[i].s;
    }
    sort(q+1,q+1+k,cp);
    int l=0,kk=0;
    for(int i=1;i<=k;i++)
    {
    	if(q[i].x==l)
    	{
    		q[i].x=kk;
    	}
    	if(q[i].x>l)
    	{
    		kk++;
    		l=q[i].x;
    		q[i].x=kk;
    	}
    }
    sort(q+1,q+1+k,ccp);
    l=0,kk=0;
    for(int i=1;i<=k;i++)
    {
    	if(q[i].y==l)
    	{
    		q[i].y=kk;
    	}
    	if(q[i].y>l)
    	{
    		kk++;
    		l=q[i].y;
    		q[i].y=kk;
    	}
    }
    for(int i=1;i<=k;i++)
    {
    	a[q[i].x][q[i].y]=q[i].s;
    }
    for(int i=1;i<=k;i++)
    {
    	for(int j=1;j<=k;j++)
    	{
    		f[i][j]=max(f[i-1][j],f[i][j-1])+a[i][j];
    	}
    }
    cout<<f[k][k];
}

