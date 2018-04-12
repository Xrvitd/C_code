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
bool v[50001];
inline int get_num()
{
int num = 0;
char c;
bool flag = false;
while ((c = getchar()) == ' ' || c == '\n' || c == '\r');
if (c == '-') flag = true;
else num = c - '0';
while (isdigit(c = getchar()))
num = num * 10 + c - '0';
return (flag ? -1 : 1) * num;
}
bool cp(int q,int w)
{
	return q>w;
}
bool kk()
{
	for(int i=1;i<=n;i++)
	{
		if(!v[i])return 0;
	}
	return 1;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
    }
    sort(a+1,a+1+n,cp);
    int l=1;
    while(!kk())
    {
    	int k=n;
    	for(int i=l;i<=n;i++)
    	{
    		if(!v[i])
    		{
    			if(k>0)
    			{   k--;
    			    v[i]=1;
    			    k=min(k,a[i]);
    			}else
    			{
    				continue;
    			}
    		}
    	}
    	ans++;
    }
    cout<<ans;
}

