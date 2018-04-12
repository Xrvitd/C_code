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
int n,m,s,ti;
int h[N],v[N],next[N],f[N],q[N],p=0,w[N],d[N];
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
void add(int a,int b,int c)
{
	p++;
	w[p]=c;
	next[p]=h[a];
	h[a]=p;
	v[p]=b;
}
int spfa(int st,int ta)
{
	int ha=0,t=1;
	q[1]=st;
	d[st]=0;
	f[st]=1;
	while(ha<=t)
	{
		ha++;
		int i=q[ha],p=h[i];
		f[i]=0;
		while(p)
		{
			if(d[i]+w[p]<d[v[p]])
			{
				d[v[p]]=d[i]+w[p];
				if(!f[v[p]])
				{
					t++;
					q[t]=v[p];
					f[v[p]]=1; 
				}
			}
			p=next[p];
		}
	}
	return d[ta];
}
int main()
{
	n=get_num();m=get_num();s=get_num();ti=get_num();
	for(int i=1;i<=n;i++) 
    {
    	d[i]=2147000000;
    }
	for(int i=1;i<=m;i++)
	{
		int q,w,e;
		q=get_num();w=get_num();e=get_num();
		add(q,w,e);
		add(w,q,e);
	}
	printf("%d",spfa(s,ti));
} 
