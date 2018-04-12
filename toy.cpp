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
struct zqm
{
	int f;
	string s;
}q[100001];
int main()
{
	freopen("toy.in","r",stdin);
	freopen("toy.out","w",stdout);
	cin>>n>>m; 
    for(int i=1;i<=n;i++)
    {
    	cin>>q[i].f>>q[i].s;
    }
    int l=1;
    for(int i=1;i<=m;i++)
    {
    	int w,e;
    	cin>>w>>e;
    	if((q[l].f==0&&w==0)||(q[l].f==1&&w==1))
    	{
    		l=l+n-e;
    		l%=n;
    		if(l==0) l=n;
    	}else
    	{
    		l=l+e;
    		l%=n;
    		if(l==0) l=n;
    	}
    }cout<<q[l].s;
}

