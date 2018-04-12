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
int n,m,ans=0;
int a[10001];
bool v[10001];
int l=0;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
    {
    	int k;
    	cin>>k;
    	if(!v[k])
    	{
    		ans++;
    		l++;
    		if(l>n)
    		{
    			l-=n;
    			v[a[l]]=0;
    			a[l]=k;
    			v[k]=1;
    		}
    		else
    		{
    			v[a[l]]=0;
    			a[l]=k;
    			v[k]=1;
    		}
    	}
    }
    cout<<ans;
}
