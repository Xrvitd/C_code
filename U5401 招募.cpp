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
int n,m;
struct zqm
{
	int s[1000001];
}ans;
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
void debug()
{
	for(int i=10;i>=1;i--)
	{
		cout<<ans.s[i];
	}
	cout<<endl;
}
void ch(int x)
{
	for(int i=1;i<=1000001;i++)
	{
		if(ans.s[i]==0)
		{
			break;
		}
		ans.s[i]*=x;
	}
	for(int i=1;i<=1000001;i++)
	{
		while(ans.s[i]>9999)
		{
			ans.s[i+1]+=ans.s[i]/10000;
			ans.s[i]%=10000;
		}
	}
}
int main()
{
    cin>>n;
    ans.s[1]=1;
    for(int i=2;i<=n;i++)
    {
    	ch(i);
    //	debug();
    }
    for(int i=1000001;i>=1;i--)
    {
    	if(ans.s[i]!=0)
        {
        	m=i;
        	break;
        }
    }
    cout<<ans.s[m];
    for(int i=m-1;i>=1;i--)
    {
    	if(ans.s[i]<1000)
    	{
    		cout<<0;
    	}
    	if(ans.s[i]<100)
    	{
    		cout<<0;
    	}
    	if(ans.s[i]<10)
    	{
    		cout<<0;
    	}
    	cout<<ans.s[i];
    }
}

