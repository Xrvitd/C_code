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
double f[1501][1501]; 
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
int main()
{
	cin>>n;
	f[2][0]=1;
	f[0][2]=1;
	f[1][1]=0;
	for(int i=2;i<=n/2;i++)
	{
		f[0][i]=f[i][0]=1;
	}
	for(int i=1;i<=n/2;i++)
	{
		for(int j=1;j<=n/2;j++)
		{
			f[i][j]=(f[i-1][j]+f[i][j-1])*0.5;
		}
	}
    printf("%.4lf",f[n/2][n/2]);
}

