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
struct zqm
{
	string s;
	int k;
}q[101];
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
int js(string s)
{
	int len=s.size(),f[511][511];
	memset(f,0,sizeof(f));
	string ss;
	for(int i=0;i<len;i++)
	{
		ss[len-i-1]=s[i];
	}
	for(int i=1;i<=len;i++)
	{
		for(int j=1;j<=len;j++)
		{
			if(s[i-1]==ss[j-1])
			{
				f[i][j]=f[i-1][j-1]+1;
			}else
			{
				f[i][j]=max(f[i-1][j],f[i][j-1]);
			}
		}
	}
	return f[len][len];
}
bool cmp(zqm a,zqm b)
{
	if(a.k==b.k)
	{
		return a.s<b.s;
	}
	return a.k>b.k;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>q[i].s;
		q[i].k=js(q[i].s);
	}
	sort(q+1,q+1+n,cmp);
    for(int i=1;i<=n;i++)
    {
    	cout<<q[i].s<<endl;
    }
}

