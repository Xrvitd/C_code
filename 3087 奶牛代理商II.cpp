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
	int x,y;
}a[10001];
bool amp(struct zqm aa,struct zqm bb)
{
	if(bb.y==aa.y)
	{
		return aa.x<bb.x;
	}
	return aa.y>bb.y;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].y;
		a[i].x=i;
	}
	sort(a+1,a+1+n,amp);
	int l=0,ll;
	for(int i=1;i<=n;i++)
     
     {
     	if(a[i].y==l)
     	{
     		cout<<ll<< " "<<l<<"\n";
     		continue;
     	}
     	cout<<i<< " "<<a[i].y<<"\n"; 
     	l=a[i].y;
     	ll=i;
     }

}

