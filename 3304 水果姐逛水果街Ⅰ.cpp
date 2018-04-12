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
int a[200001]; 
struct zqm
{
	int mi,ma,lr,rl;
}t[1000001];
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
void build(int x,int l,int r)
{
	if(l==r)
	{
		t[x].mi=a[l];
		t[x].ma=a[l];
		t[x].lr=0;
		t[x].rl=0;
		return;
	}
	int mid=(l+r)>>1;
	build(2*x,l,mid);
	build(2*x+1,mid+1,r);
	t[x].ma=max(t[2*x].ma,t[2*x+1].ma);
	t[x].mi=min(t[2*x].mi,t[2*x+1].mi);
	t[x].lr=max(t[2*x+1].ma-t[x*2].mi,max(t[2*x].lr,t[2*x+1].lr));
	t[x].rl=max(t[2*x].ma-t[2*x+1].mi,max(t[2*x].rl,t[2*x+1].rl));
}
int findma(int x,int l,int r,int xx,int yy)
{
	int ans=0;
	if(l==xx&&yy==r)
	{
		ans=max(ans,t[x].ma);
		return ans;
	}
	int mid=(l+r)>>1;
	if(mid>=yy)
	{
		ans=max(ans,findma(2*x,l,mid,xx,yy));
	}else
	{
		if(mid<xx)
		{
			ans=max(ans,findma(2*x+1,mid+1,r,xx,yy));
		}else
		{
			ans=max(ans,findma(2*x,l,mid,xx,mid));
			ans=max(ans,findma(2*x+1,mid+1,r,mid+1,yy)); 
		}
	}
	return ans;
}
int findmi(int x,int l,int r,int xx,int yy)
{
	int ans=2147483647;
	if(l==xx&&yy==r)
	{
		ans=min(ans,t[x].mi);
		return ans;
	}
	int mid=(l+r)>>1;
	if(mid>=yy)
	{
		ans=min(ans,findmi(2*x,l,mid,xx,yy));
	}else
	{
		if(mid<xx)
		{
			ans=min(ans,findmi(2*x+1,mid+1,r,xx,yy));
		}else
		{
			ans=min(ans,findmi(2*x,l,mid,xx,mid));
			ans=min(ans,findmi(2*x+1,mid+1,r,mid+1,yy)); 
		}
	}
	return ans;
}
int findlr(int x,int l,int r,int xx,int yy)
{
	int ans=0;
	if(l==xx&&yy==r)
	{
		ans=max(ans,t[x].lr);
		return ans;
	}
	int mid=(l+r)>>1;
	if(mid>=yy)
	{
		ans=max(ans,findlr(2*x,l,mid,xx,yy));
	}else
	{
		if(mid<xx)
		{
			ans=max(ans,findlr(2*x+1,mid+1,r,xx,yy));
		}else
		{
			ans=max(ans,max(findlr(2*x,l,mid,xx,mid),max(findlr(2*x+1,mid+1,r,mid+1,yy),findma(2*x+1,mid+1,r,mid+1,yy)-findmi(2*x,l,mid,xx,mid))));
		}
	}
	return ans;
}
int findrl(int x,int l,int r,int xx,int yy)
{
	int ans=0;
	if(l==xx&&yy==r)
	{
		ans=max(ans,t[x].rl);
		return ans;
	}
	int mid=(l+r)>>1;
	if(mid>=yy)
	{
		ans=max(ans,findrl(2*x,l,mid,xx,yy));
	}else
	{
		if(mid<xx)
		{
			ans=max(ans,findrl(2*x+1,mid+1,r,xx,yy));
		}else
		{
			ans=max(ans,max(findrl(2*x,l,mid,xx,mid),max(findrl(2*x+1,mid+1,r,mid+1,yy),findma(2*x,l,mid,xx,mid)-findmi(2*x+1,mid+1,r,mid+1,yy))));
		}
	}
	return ans;
}
int main()
{
	n=get_num();
	for(int i=1;i<=n;i++)
	{
		a[i]=get_num();
	}
	build(1,1,n);
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		int q,w;
		q=get_num();w=get_num();
		if(q==w){
			cout<<0<<"\n";
			continue;
		}
		if(q<w)
		{
			cout<<findlr(1,1,n,q,w)<<"\n";
		}else
		{
			cout<<findrl(1,1,n,w,q)<<"\n";
		}
	}
	

}

