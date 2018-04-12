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
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>m;
		if(m==0) continue;
		if(i>1)
		{
			if(m>0)
			cout<<'+';
			else
			cout<<'-';
		}
		if(i==1&&m<0)cout<<'-';
		if(m!=1&&m!=-1)
		cout<<abs(m);
		cout<<"x^"<<n-i+1;
	}
	cin>>m;
	if(m>0)
	{
		cout<<'+';
	cout<<m;
	}
	

}

