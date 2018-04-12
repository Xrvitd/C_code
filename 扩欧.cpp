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
int x,y;
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
int exgcd(int a,int b)
{
	if(b==0)
	{
		x=1;y=0;return a;
	}else
	{
		int t,d;
		d=exgcd(b,a%b);
		t=x;
		x=y;
		y=t-(a/b)*y;
		return d;
	}
} 
int main()
{
	cin>>n>>m;
	exgcd(n,m);
	cout<<(x+m)%m;

}

