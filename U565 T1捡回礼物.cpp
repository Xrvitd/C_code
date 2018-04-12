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
int n,m=0,a[101][101],b[100001],g[100001]={0},q;
int fx[5]={0,0,0,1,-1},fy[5]={0,1,-1,0,0};
bool v[101][101]={0};
int dfs(int x,int y,int k,int s)
{
	for(int i=1;i<=4;i++)
	{
		int tx=x+fx[i],ty=y+fy[i];
		if(tx>0&&ty>0&&tx<=n&&ty<=n&&a[tx][ty]==k&&!v[tx][ty])
		{
			s++;
			v[tx][ty]=1;
			s+=dfs(tx,ty,k,s);
			
		}
	}
	return s;
}
int main()

{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
    for(int i=1;i<=n;i++)
    {
    	for(int j=1;j<=n;j++)
    	{
    		if(m<dfs(i,j,a[i][j],0))
    		{
    			m=dfs(i,j,a[i][j],0);
    			q=a[i][j];
    		}
    	}
    }
    cout<<m<<endl<<q;
}

