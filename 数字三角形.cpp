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
int n,m,p;
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
int a[1001][1001];
int f(int x,int y)
{
	if(x>n) return 0;
	return a[x][y]+max(f(x+1,y),f(x+1,y+1));
}
int main()
{
    cin>>m>>p;
	
	long long f[1001];
	f[1]=1;f[2]=1;
	
	for(int i=3;i<=m;i++)
	{
		f[i]=(f[i-1]+f[i-2])%p;
		cout<<f[i]<<" ";
	}
	
}

