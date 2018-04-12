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
int n,m,k,t[1001],l[1001],qq[1001],tim[1001],ss[10001],ans=0,g[1001],down[1001],s,j,p[1001],i;
struct zqm
{
	int ti,x,y;
}q[10001];
struct re
{
	int s,x;
}qz[1001],qw[1001];
bool v[1001];
int main()
{
	n=get_num();
    m=get_num();
    k=get_num();
	for(int i=1;i<n;i++)
	t[i]=get_num();
	for(int i=1;i<=m;i++)
	{
		q[i].ti=get_num();
		q[i].x=get_num();
		q[i].y=get_num();
		l[q[i].x]=max(l[q[i].x],q[i].ti);
		down[q[i].y]++;
	}
	while(k>0)
	{
		memset(p,0,sizeof(p));
		for(int iq=2;iq<=n;iq++)
	    {
	    	tim[iq]=max(tim[iq-1],l[iq-1])+t[iq-1];
	    }
	    i=1;
	    s=0;
	    while(i<=n-1)
	    {
	    	if(t[i]>0)
	    	{
	    		j=i;
	    		p[j]=down[i+1];
	    		while(tim[i+1]>l[i+1])
	    		{
	    			i++;
	    			p[j]=p[j]+down[i+1];
	    		}
	    		if(p[j]>p[s])
	    		{
	    			s=j;
	    		}
	    	}
	    	i++;
	    }
	    if(p[s]==0)
	    {
	    	k=0;
	    	break;
	    }
	   /* for(int i=1;i<n;i++)
	    {
	    	if(p[i]==p[s]&&k>0)
	    	{
	    		t[i]--;
	    		k--;
	    	}
	    }*/ 
	    t[s]--;k--;
	}
     for(int i=1;i<=n-1;i++)
     {
     	tim[i+1]=max(tim[i],l[i])+t[i];
     }
     int sumt=0;
     for(int i=1;i<=m;i++)
     {
     	sumt=sumt+tim[q[i].y]-q[i].ti;
     }
     cout<<sumt;
}

