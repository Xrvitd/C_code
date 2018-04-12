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
int n,m,cx,cy;
int a[1001][1001]; 
char s[10001];
bool v=0;
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
void dfs(int x,int y)
{
	if(v)return;
	if(x==n+1)
	{
		cout<<"Yes\n";
		for(int i=1;i<=n;i++)
		{
			cout<<s[i];
		}
		v=1;
		return;
	}
	if(y>=2&&!a[x+1][y-1])
	{
		s[x]='L';
		dfs(x+1,y-1);
	}
	if(!a[x+1][y])
	{
		s[x]='N';
		dfs(x+1,y);
	}
	if(y<m&&!a[x+1][y+1])
	{
		s[x]='R';
		dfs(x+1,y+1);
	}
}
int main()
{
    cin>>n>>m;
    cx=n+1;
    cin>>cy;
    for(int i=1;i<=n+1;i++)
    {
    	for(int j=1;j<=m;j++)
    	{
    		char c;
    		cin>>c;
    		if(c=='*')
    		{
    			a[i][j]=1;
    		}
    	}
    }
    string ss;
    dfs(1,cy);
    if(!v)
    {
    	cout<<"No";
    }
}

