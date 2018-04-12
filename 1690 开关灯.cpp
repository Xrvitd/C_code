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
int t[1000101];
bool lazy[1000010];
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
void down(int x)
{
	if(lazy[x]==1)
	{
		if(lazy[2*x]==1)lazy[2*x]=0;else lazy[2*x]=1;
		if(lazy[2*x+1]==1)lazy[2*x+1]=0;else lazy[2*x+1]=1;
		lazy[x]=0;
	}
}
int sum(int x,int l,int r)
{
	int su=0;
	if(lazy[x]==1)
	{
		return r-l+1;
	}else
	{
		return t[2*x]+t[2*x+1];
	}
}
void add(int x,int l,int r,int q,int w)
{
	if(l==q&&r==w)
	{
		if(lazy[x])
		lazy[x]=0;
		else
		lazy[x]=1;
		return;
	}
	int mid=(l+r)>>1;
	if(mid>=w)
    {
        add(2*x,l,mid,q,w);
    }else
    {
    	if(mid<q)
    	add(2*x+1,mid+1,r,q,w);
    	else
    	{
		add(2*x,l,mid,q,mid);
		add(2*x+1,mid+1,r,mid+1,w);
	    }
    }
    t[x]=sum(x,l,r);
}
int find(int x,int l,int r,int q,int w)
{
	if(l==q&&r==w)
    {
        if(lazy[x])
    	return r-l+1;
    	else
    	return t[x*2]+t[2*x+1];
    }
   //down(x);
    int mid=(l+r)>>1;
    t[x]=sum(x,l,r);
    if(mid>=w)
    {
        return find(2*x,l,mid,q,w);
    }else
    {
    	if(mid<q)
    	return find(2*x+1,mid+1,r,q,w);
    	else
    	{
		return find(2*x,l,mid,q,mid)+find(2*x+1,mid+1,r,mid+1,w);
	    }
    }
    
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int q,w,e;
		cin>>q>>w>>e;
		if(!q)
		{
			add(1,1,n,w,e);
		}
		else
		{
			cout<<find(1,1,n,w,e)<<endl;
		
		}
	}

}

