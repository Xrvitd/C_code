#include<iostream>
#include<cstdio>
using namespace std;
int a[100001]={0};
int n,m;
struct re
{
	int l,r,s;
 } ;
 struct re t[270000];
void build(int x,int l,int r)
{
  	int mid;
  	if(l==r)
  	{
  		t[x].s=a[l];
  		return ;
	  }
	  mid=(l+r)>>1;
	  t[2*x].l=l;
	  t[x*2].r=mid;
	  t[2*x+1].l=mid+1;
	  t[x*2+1].r=r;
	  build(x*2,l,mid);
	  build(2*x+1,mid+1,r);
	  t[x].s=t[2*x].s+t[2*x+1].s;
}
int find(int x,int l,int r)
{
	int mid;
	int q=t[x].l,w=t[x].r;
	if(q==l&&w==r)
	{
		return t[x].s;
	}
	mid=(q+w)>>1;
	if(mid<l) return (find(x*2+1,l,r));
	if(mid>=r) return (find(2*x,l,r));
	return (find(2*x,l,mid)+find(x*2+1,mid+1,r));
}
void chenge (int x,int d,int p)
{
	int mid;
	int q=t[x].l,w=t[x].r;
	if(q==w)
	{
		t[x].s+=d;
		return ;
	}else
	{
		mid=(q+w)>>1;
		if(p>mid) chenge(2*x+1,d,p);
		if(mid>=p) chenge(x*2,d,p);
	}
	t[x].s+=d;
	return ;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	t[1].l=1;t[1].r=n;
	build(1,1,n);
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		int q,w,e;
		cin>>e>>q>>w;
		if(e==1)
		{
			chenge(1,w,q);
		}
		else
		{
			cout<<find(1,q,w)<<endl;
		}
	}
}
