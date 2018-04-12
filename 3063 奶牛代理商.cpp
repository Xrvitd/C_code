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
	double y,s,c;
}a[11];
double z=0;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].y;
	}
for(int i=1;i<=n;i++)
	{
		cin>>a[i].s;
		a[i].c=a[i].s-a[i].y;
		z+=a[i].c;
	}
	cout<<z/n;
	

}

