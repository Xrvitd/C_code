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
int n,m,k,a[100001];
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
    cin>>k;
    while(k--)
    {
    	cin>>n>>m;
    	for(int i=1;i<=n;i++)
    	{
    		int q;
    		q=get_num();
    		a[i]=a[i-1]+q;
    	}
    	for(int i=1;i<=m;i++)
    	{
    		int q,w;
    		q=get_num();w=get_num();
    		cout<<a[w]-a[q-1]<<"\n";
    	}
    }
}

