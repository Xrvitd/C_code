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
long long n,m,ans=0;
int f[5151];
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
	cin>>n>>m;
	f[0]=1;
	for(int i=1;i<=n;i++)
	{
		if(i<m)
		{
			f[i]=f[i-1]*2;
		}else
		{
			if(i-m-1==-1)
			{
				f[i]=f[i-1]*2-1;
			}else
			f[i]=f[i-1]*2-f[i-m-1];
		}
	}
    cout<<f[n];
}

