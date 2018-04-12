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
int n,m,b[10001],i=0;
int main()
{
	cin>>n;
	while(n)
	{
		n/=2;
		m+=n;
		i++;
		b[i]=n;
	}
	cout<<m;
	cout<<endl;
	for(int k=1;k<i;k++)
	{
		cout<<b[k]<<" ";
	}
}
