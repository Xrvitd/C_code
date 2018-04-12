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
int n,m,f[50000001]={0},t,k,e1=0,e2=0;
struct re
{
	int x,y;
} a[10000001],b[10000001];
int find(int x) {
if (f[x] == x) return f[x];
f[x] = find(f[x]);
return f[x];
}
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
int hash(int x)
{
	return x%9999997;
}
int init()
{
	for(int i=1;i<=10000001;i++)
	{
		f[i]=i;
	}
}
int main()
{
	cin>>t;
	for(int ii=1;ii<=t;ii++)
	{
		cin>>n;
		init();
		e1=0;e2=0;
		for(int i=1;i<=n;i++)
		{
			int q,w,e;
			q=get_num();
			w=get_num();
			e=get_num();
		//	scanf("%d%d%d",&q,&w,&e);
			q=hash(q);
			w=hash(w);
			e=hash(e);
			if(e)
			{
				e1++;
				f[find(q)]=find(w);
			}else
			{
				e2++;
				b[e2].x=q;
				b[e2].y=w;
			}
		}
		bool v=1;
		for(int i=1;i<=e2;i++)
		{
			if(find(b[i].x)==find(b[i].y))
			{
				v=0;
			}
		}
		if(!v)
		{
			cout<<"NO\n";
		}else
		{
			cout<<"YES\n";
		}
		
	}
}
