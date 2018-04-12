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
void dfs(int x,int l,int ll)
{
	if(x==n)
	{
		m++;
		return;
	}
	if(l==ll)
	{
		if(ll==1)
		{
			dfs(x+1,2,1);
			return;
		}
		if(ll==2)
		{
			dfs(x+1,1,2);
			return;
		}
	}
	dfs(x+1,1,l);
	dfs(x+1,2,l);
}
int main()
{
	cin>>n;
	dfs(0,0,0); 
    cout<<m;
}

