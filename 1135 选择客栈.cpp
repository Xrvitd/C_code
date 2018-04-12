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
int n,m,p,k,c[200001],w[200001],q[200011],ans=0;
struct zqm
{
	int num[200001];
	int h;
}z[51];
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
	n=get_num();
	k=get_num();
	p=get_num();
	for(int i=1;i<=n;i++)
	{
		c[i]=get_num();w[i]=get_num();
		if(w[i]<=p)
		{
			q[i]=q[i-1]+1;
		}else
		{
			q[i]=q[i-1];
		}
		
		z[c[i]].h++;
		z[c[i]].num[z[c[i]].h]=i;
	}
	
	q[n+1]=q[n];
	for(int i=0;i<k;i++)
	{
		for(int j=1;j<=z[i].h;j++)
		{
			for(int k=j+1;k<=z[i].h;k++)
			{
				//cout<<z[i].num[j]<<" "<<z[i].num[k]<<endl;
				if(q[z[i].num[k]]-q[z[i].num[j]-1])
				{
					ans+=z[i].h-k+1;
					break;
				}
			}
		}
	}
    cout<<ans;
}

