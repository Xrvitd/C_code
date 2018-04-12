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
int n,m,a[1000001];
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
bool pd(int x)
{
	int k=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i])
		{
			i=i+x-1;
			k++;
			if(k>m)return 0;
		}
	}
	return 1;
}
int just_doit()
{
	int l=0,r=n,mid;
	while(l<r)
	{
		mid=(l+r)>>1;
		if(pd(mid))
		{
			r=mid;
		}else
		{
			l=mid+1;
		}
	}
	return l;
}
int main()
{
	int k=0;
	while(cin>>n>>m)
	{
		k++;
		string s;
		cin>>s;
	for(int i=1;i<=n;i++)
	{
		a[i]=s[i-1]-'0';
	} 
	if(m==0||n==0)
		{
			cout<<"Case "<<k<<": "<<0<<"\n"; 
			continue;
		}
	cout<<"Case "<<k<<": "<<just_doit()<<"\n"; 
	}
    
}

