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
int n,m,cs=0,h=0,t=1,a[51][51]={0},co[51][4]={0},ans=2147483647;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
	    {
	    	char c;
	    	cin>>c;
	    	
	    	if(c=='W') {a[i][j]=1;co[i][1]++;
	    	}
	    	if(c=='B') {a[i][j]=2;co[i][2]++;
	    	}
	    	if(c=='R') {a[i][j]=3;co[i][3]++;
			} 
	    }
	}
	for(int k=2;k<n;k++)
	{
		for(int l=1;l<n-1;l++)
		{
			int sum=0;
			for(int i=1;i<k;i++)
			{
				sum+=m-co[i][1];
			}
			for(int i=k;i<k+l;i++)
			{
				sum+=m-co[i][2];
			}
			for(int i=k+l;i<=n;i++)
			{
				sum+=m-co[i][3];
			}
			//cout<<k<<" "<<k+l<<" ";
		//	cout<<sum<<" \n";
			ans=min(ans,sum);
		}
	}
	cout<<ans;

}

