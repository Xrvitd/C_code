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
int n,a[11];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		a[i]=i;
	}
	do{
		for(int i=1;i<=n;i++)
	{
		cout<<a[i]<< " ";
	}
	cout<<"\n";
	}
	while(next_permutation(a+1,a+1+n));
}
