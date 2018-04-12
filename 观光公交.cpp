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
int n,m,k,t[1001],l[1001],qq[1001],tim[1001],ss[10001],ans=0,g[1001];
struct zqm
{
	int ti,x,y;
}q[10001];
struct re
{
	int s,x;
}qz[1001];
bool v[1001];
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
bool cmp(re a , re b)
{
	return a.s>b.s;
}
int main()
{
	cin>>n>>m>>k;
	for(int i=1;i<n;i++)
	cin>>t[i];
	for(int i=1;i<=m;i++)
	{
		cin>>q[i].ti>>q[i].x>>q[i].y;
		l[q[i].x]=max(l[q[i].x],q[i].ti);
		qq[q[i].x]++;
		qq[q[i].y+1]--;
	}
	for(int iq=1;iq<=n;iq++)
	{
		tim[iq]=max(tim[iq-1],l[iq-1])+t[iq-1];
	}
	//cout<<endl;
	for(int i=1;i<=n+1;i++)
	{
		qz[i].s=qz[i-1].s+qq[i];
		qz[i].x=i;
		cout<<qz[i].s<<" "; 
	}
	sort(qz+1,qz+1+n,cmp);
	int i=1;
	
	while(k)
	{
	g[n]=n;
	g[n-1]=n;
	for(int ii=n-2;ii>0;ii--)
	{
		if(tim[ii+1]>l[ii+1])
		{
			g[ii]=g[ii+1];
		}else
		{
			g[ii]=ii+1;
		}
	}
		if(tim[qz[i].x]+t[qz[i].x]>l[qz[i].x+1]&&t[qz[i].x]>0)
		{
			k--;
			for(int ii=qz[i].x+1;ii<=g[qz[i].x];ii++)
			{
				tim[ii]--;
			}
			t[qz[i].x]--;
			for(int iq=1;iq<=n;iq++)
	{
		tim[iq]=max(tim[iq-1],l[iq-1])+t[iq-1];
	}
		}
		else
		{
			i++;
		}
	}
	
	for(int i=1;i<=m;i++)
	{
		ss[i]=tim[q[i].y]-q[i].ti;
		ans+=ss[i];
	}
	for(int i=1;i<=n;i++)
	{
	//	cout<<tim//[i]<<" ";
	}
    cout<<ans;
}

