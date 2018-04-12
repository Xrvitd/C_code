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
int n,m,k,x;
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
    cin>>n>>m>>k>>x;
    int first=x,l=0;
    while(1)
    {
    	x=(x+m)%n;
    	if(x==0) x=n;
    	l++;
    	if(x==first)
    	{
    		break;
    	}
    }
    cout<<l<<" ";
    if(k>=6)
    l=1000000%l;
    else
    {
    	int s=1;
    	for(int i=1;i<=k;i++)
    	{
    		s*=10;
    	}
    	l=s%l;
    }
    for(int i=1;i<=l;i++)
    {
    	x=(x+m)%n;
    	if(x==0) x=n;
    }
    cout<<x;
}

