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
int n,m,a[101],b[1000001],ans=0;
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
	int sum=a[n]*x;
	for(int i=n-1;i>=1;i--)
	{
		sum+=a[i];
		sum*=x;
	}
	sum+=a[0];
	if(sum==0) return 1;
	return 0;
}
int main()
{
	cin>>n>>m;
	string s;
	for(int i=0;i<=n;i++)
	{
		cin>>s;int k=s.size();
		if(s[0]=='-')
		{
		if(s.size()>=9)
		{
			
			for(int j=k-8;j<=k-1;j++)
			{
				a[i]*=10;
				a[i]+=s[j]-'0';
			}
		}else
		{
			
			for(int j=1;j<k;j++)
			{
				a[i]*=10;
				a[i]+=s[j]-'0';
			}
		}
		a[i]=-a[i];
		
		continue;
		}
		if(s.size()>=9)
		{
			
			for(int j=k-10;j<=k-1;j++)
			{
				a[i]*=10;
				a[i]+=s[j]-'0';
			}
		}else
		{
			
			for(int j=0;j<k;j++)
			{
				a[i]*=10;
				a[i]+=s[j]-'0';
			}
		}
		
	}
    for(int i=1;i<=m;i++)
    {
    	if(pd(i))
    	{
    		ans++;
    		b[ans]=i;
    	}
    }
    cout<<ans<<"\n";
    for(int i=1;i<=ans;i++)
    {
    	cout<<b[i]<<"\n";
    }
}

