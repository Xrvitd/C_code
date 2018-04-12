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
int n,m,l[200010],r[200010],f[200010],ans=0;
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
void dfs(int x)
{
	if(x==0)return;
	dfs(l[x]);
	dfs(r[x]);
	f[x]=max(f[l[x]],f[r[x]])+1;
	if(l[x]==r[x]&&l[x]==0)f[x]=0;
	if(l[x]==0||r[x]==0)
	{
		ans=max(ans,f[l[x]]+f[r[x]]+1); 
	}else
	ans=max(ans,f[l[x]]+f[r[x]]+2); 
}
int main()
{ 
    cin>>n;
    for(int i=1;i<=n;i++)
    {
    	cin>>l[i]>>r[i];
    }
    dfs(1);
    cout<<ans;
}

