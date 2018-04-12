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
int n,m,ans=2147483647;
char s[510];
int f[501][501];
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
int lcs(int x)
{
	memset(f,0,sizeof(f));
	for(int i=1;i<=n;i++)
	{
		f[0][i]=f[i][0]=0;
	}
	for(int i=1;i<x;i++)
	{
		for(int j=1;j<=n-x+1;j++)
		{
			if(s[i]==s[j+x-1])
			{
				f[i][j]=f[i-1][j-1]+1;
			}else
			{
				f[i][j]=max(f[i-1][j],f[i][j-1]);
			}
		}
	}
	return f[x-1][n-x+1];
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
    for(int i=2;i<=n;i++)
    {
    	ans=min(ans,n-lcs(i)*2);
    }
    cout<<ans;
}

