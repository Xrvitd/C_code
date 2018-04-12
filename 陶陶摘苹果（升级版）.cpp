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
int n,m,a,s,b;
int x[5001];
int y[5001];
int num;
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
    cin>>n>>s;
    cin>>a>>b;
    for(int i=1;i<=n;i++)
    cin>>x[i]>>y[i];
    for(int i=1;i<=n;i++)
    {
    	if(s<0)
    	break;
		if(a+b>=x[i])
		{
			num++;
			s-=y[i];
		}
    }
    cout<<num;
    return 0;
}

