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
int a[101][101];
int d[101][101]; 
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		char q,w;
		cin>>q>>w;
		int e,r,t;
		cin>>t;
		if(q>=90)
		{
			e=q-'a'+1;
		}else e=q-'A'+28;
		if(w>=90)
		{
			r=w-'a'+1;
		}else r=w-'A'+28;
		a[e][r]=t;
		d[e][r]=t;
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
		}
	}
	}
	for(int i=1;i<=100;i++)
	{
		int q,w;
		cout<<d[53][i]<<"\n";
	}
	

}

