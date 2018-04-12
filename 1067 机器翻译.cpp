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
int a[10001],tot=0,d=1,ans=0;
bool v[10001],kk;
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
	cin>>m>>n;
	for(int i=1;i<=n;i++)
	{
		int q;
		cin>>q;
		if(!v[q])
		{
			ans++;
			if(kk)
			{
				tot++;
				a[tot]=q;
				v[a[d]]=0;
				d++;
				v[q]=1;
			}
			else
			{
				tot++;
				if(tot==m)
				kk=1;
				a[tot]=q;
				v[q]=1;
			}
		}
	}
	for(int i=1;i<=tot;i++)
	{
		cout<<a[i]<<" ";
	}cout<<endl;
	cout<<ans;
}

