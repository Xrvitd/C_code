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
#define MP(x,y) make_pair(x,y)
using namespace std;
long long n,m,k,a,b;
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
		cin>>n>>a>>b;
		m=0;int q=a*b;
		if(n<=q)
		{
			for(int i=min(a,b);i<n;i++)
		{
			m+=abs(i%a-i%b);
		}
		}else
		{
			int w=0;
			for(int i=0;i<=q;i++)
		    {
		    	if(i==q)
		    	{
		    		w=m;
		    		//cout<<w;
		    	}
			m+=abs(i%a-i%b);
	    	}
	        m=(n/q)*w;
	        for(int i=q*(n/q);i<n;i++)
	        {
	        	m+=abs(i%a-i%b);
	        }	
		}
		cout<<m<<'\n';
	}
}

