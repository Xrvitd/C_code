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
int n,m,k,s;

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
bool dfs(int x,int y,bool a,bool b)
{
	if(x==y&&a&&b) return 1;
	if(x==y&&!a) return 0;
	if(x==y&&!b) return 0;
	if(y>x) return 0;
	
	return dfs(x,y+n,1,b)||dfs(x,y+m,a,1);
}
int main()
{
    cin>>k;
    while(k--)
    {
    	cin>>s>>n>>m;
    	if(dfs(s,0,0,0))
    	cout<<"Yes\n";
		else
		cout<<"No\n"; 
    }
}

