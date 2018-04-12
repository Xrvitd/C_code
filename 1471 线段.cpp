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
int a[50001],d[50010];
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
	for(int i=1;i<=n;i++)
	{
		int q,w;
		cin>>q>>w;
		d[q]++;
		d[w+1]--;
	}
	a[0]=d[0];
	for(int i=1;i<=50001;i++)
	{
		a[i]=a[i-1]+d[i];
	}
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		int q;
		cin>>q;
		cout<<a[q]<<endl;
	}

}

