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
int a[100010],b[100010],c[100010]; 
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
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		b[i]=1;
		c[i]=1;
	}
	for(int i=1;i<=n;i++)
	{
		int ma=0;
		for(int j=1;j<i;j++)
		{
			if(a[j]<a[i]&&b[j]>ma)
			{
				ma=b[j];
			}
		}
		b[i]=ma+1;
	}
	for(int i=n;i>=1;i--)
	{
		int ma=0;
		for(int j=n;j>i;j--)
		{
			if(a[j]<a[i]&&c[j]>ma)
			{
				ma=c[j];
			}
		}
		c[i]=ma+1;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		cout<<b[i]<< " "<<c[i]<<endl;
		ans=max(ans,b[i]+c[i]-1);
	}
	cout<<ans;

}

