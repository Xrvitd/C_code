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
int n,m,k;
string s1,s2,s;
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
    cin>>m;
	while(m--) 
	{
		cin>>n;cin>>s1;
		for(int i=2;i<=n;i++)
		{
			s2=s1;
			cin>>s1;
			if(s1.compare(s2)<0)
			{
				s=s1;
			}else
			{
				s=s2;
	    	}
		}
		cout<<s<<"\n";
	}
	
}

