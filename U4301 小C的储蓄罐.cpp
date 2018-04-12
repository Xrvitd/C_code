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
int main()
{
	double q,w;
	cin>>q;
	for(int i=1;i<=12;i++)
	{
		cin>>w;
		q-=w;
		if(q<0)
		{
			cout<<-1;
			return 0;
		}
		q+=q/5;
	}
	if(q<0)
		{
			cout<<-1;
			return 0;
		}
	if(q==0)cout<<0;
	else
	printf("%.2lf",q);
	

}

