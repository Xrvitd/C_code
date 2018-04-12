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
int n,m,a[50][50],s=0;
bool v[51][51];
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
int dfs(int x,int y)
{
	if(y<0)return 0;
	if(x>n)x%=n;
	if(x<=0)x+=n;
	if(!v[x][y])
	{
		a[x][y]=dfs((x+1)%n,y-1)+dfs((x-1+n)%n,y-1);
		v[x][y]=1;
	}
	return a[x][y];
}
int main()
{
	cin>>n>>m;
	a[n][0]=1; 
	v[n][0]=1;
    a[n][m]=dfs(n-1,m-1)+dfs(1,m-1);
    cout<<a[n][m];
}

