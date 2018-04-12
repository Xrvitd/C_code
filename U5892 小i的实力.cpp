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
int n,m,a,w,x[10001],xi,ma=0;
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
	cin>>xi>>n>>w;
	ma=xi;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i];
		ma=max(ma,x[i]);
	}
	int z;
	cin>>z;
	for(int i=1;i<=z;i++)
	{
		int q;
		cin>>q;
		if(q==1)
		{
			char c;
			int e,r,t;
			cin>>c;
			if(c=='i')
			{
				cin>>e>>r;
				xi+=e;
				ma=max(ma,xi);
			}else
			{
				cin>>e>>r;
				int kk=c-'0';
				x[kk]+=e;
				ma=max(ma,x[kk]);
			}
		}else
		{
			char c;
		    int e;
		    cin>>c>>e;
		    if(ma==xi)
		    {
		    	cout<<"Yes\n";
		    }
		    else
		    {
		    	cout<<"No\n";
		    }
		}
	}
	if(ma==xi)
		    {
		    	cout<<"Yes\n";
		    }
		    else
		    {
		    	cout<<"No\n";
		    }

}

