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
int n,m,k;
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
int pri[11000001];
bool vis[1100001];
int cnt=0;
int main()
{
	int n,m;n=get_num();m=get_num();
	for(int i=2;i<=n;i++){
		if(!vis[i]) pri[++cnt]=i;
		for(int j=1;j<=cnt&&pri[j]*i<=n;j++){
			vis[i*pri[j]]=1;
			if(i%pri[j]==0) break;
		}
	}
	vis[1]=1;
	for(int i=1;i<=m;i++){
		if(vis[get_num()]) cout<<"No\n";
		else cout<<"Yes\n";
	}
	return 0;
}

