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
string s;
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
bool pd(string s)
{
	if((s[1]>=48&&s[1]<=57)||(s[1]>=65&&s[1]<=90)||(s[1]>=97&&s[1]<=122)||s[1]=='_')
	{
		int k=0,l=0;
		for(int i=1;i<s.size();i++)
		{
			if(!k&&s[i]=='@')
			{
				k=i;
				continue;
			}
			if(k&&s[i]=='@')
			{
				return 0;
			}
		}
	
		if(!k) return 0;
		if((s[k+1]>=48&&s[k+1]<=57)||(s[k+1]>=65&&s[k+1]<=90)||(s[k+1]>=97&&s[k+1]<=122)||s[k+1]=='_')
		{
			for(int i=k+1;i<s.size();i++)
		    {
			if(!l&&s[i]=='.')
			{
				l=i;continue;
			}
			if(l&&s[i]=='.')
			{
				return 0;
			}
		    }if(!l) return 0;
		if((s[l+1]>=48&&s[l+1]<=57)||(s[l+1]>=65&&s[l+1]<=90)||(s[l+1]>=97&&s[l+1]<=122)||s[l+1]=='_')
		{
			for(int i=0;i<s.size();i++)
			{
				if(i==k||i==l)
				continue;
				if((s[l+1]>=48&&s[l+1]<=57)||(s[l+1]>=65&&s[l+1]<=90)||(s[l+1]>=97&&s[l+1]<=122)||s[l+1]=='_')
				continue;
				else
				return 0;
			}
		}else
	return 0;
		}else
	return 0;
	}else
	return 0;
	return 1;
}
int main()
{
	cin>>s;
	if(pd(s))
	{
		cout<<"yes";
	}else
	{
		cout<<"no";
	}

}

