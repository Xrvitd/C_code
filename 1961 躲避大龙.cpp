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
int n,m,ha=0,t=1,h[7010],p;
bool f[7010][61];
struct zqm
{
	int v,next,w;
}q[20001];
struct re
{
	int x,t;
}qw[100001];
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
	q[p].v=b;
	q[p].w=c;
	q[p].next=h[a];
	h[a]=p;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int q,w,e;
		cin>>q>>w>>e;
		add(q,w,e);
		add(w,q,e);
	} 
    qw[1].x=1;
    qw[1].t=0;
    while(ha<=t)
    {
    	ha++;
    	p=h[qw[ha].x];
    	while(p)
    	{
    		int k=(qw[ha].t+q[p].w);
    		while(k<0)
    		{
    			k+=60000000;
    		}
    		if(!f[q[p].v][k%60])
    		{
    			f[q[p].v][k%60]=1;
    			t++;
    			qw[t].x=q[p].v;
    			qw[t].t=(qw[ha].t+q[p].w)%60;
    		}
    		p=q[p].next;
    	}
    }
    f[2][60]=1;
    for(int i=0;i<=60;i++)
	{
		if(f[2][i])
		{
			if(i<=9)
			cout<<0;
			cout<<i;
			return 0;
		}
	} 
}

