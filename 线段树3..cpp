#include<iostream>
#include<cstdio>
using namespace std;
long long   a[300001]={0};
long long   n,m;
struct re 
{
	long long    s,l,r,m;
};
struct re t[1000001];
void down(long long   x)
{
	t[x*2].m+=t[x].m;
	t[x*2+1].m+=t[x].m;
	t[x].m=0;
}
void build(long long   x,long long   l,long long   r)
{
	long long   mid;
	t[x].l=l;
	t[x].r=r;
	if(l==r)
	{
		t[x].s=a[l];
		return;
	}
	mid=(l+r)>>1;
	build(2*x,l,mid);
	build(x*2+1,mid+1,r);
	t[x].s=t[x*2].s+t[x*2+1].s;
} 
long long     sum(long long   x)
{
	long long    ans;
	ans=t[x*2].s+t[x*2].m*(t[x*2].r-t[x*2].l+1)
	    +t[x*2+1].s+t[x*2+1].m*(t[x*2+1].r-t[x*2+1].l+1);
	    
	return ans;
}
long long   find(long long   x,long long   l,long long   r)
{
	long long   mid;
	long long   q=t[x].l,w=t[x].r;
	if(q==l&&w==r)
    {
    	return t[x].s+t[x].m*(t[x].r-t[x].l+1);
    }
    down(x);
    t[x].s=sum(x);
    mid=(t[x].l+t[x].r)>>1;
    if(mid<l) return (find(2*x+1,l,r));
    if(mid>=r) return (find(2*x,l,r));
    return (find(2*x,l,mid)+find(2*x+1,mid+1,r));
}


void chenge(long long   x,long long   m,long long   l,long long   r)
{
	long long   mid;
	long long   q=t[x].l,w=t[x].r;
	if(q==l&&w==r)
	{
		t[x].m+=m;
		return ;
	}
	else
	{
		//down(x);
		mid=(q+w)>>1;
		if(l>mid)
		{
			chenge(2*x+1,m,l,r);
		} else
		if(mid>=r) 
		chenge(2*x,m,l,r);
		else
		{
		chenge(2*x,m,l,mid);
		chenge(2*x+1,m,mid+1,r);
		}
		t[x].s=sum(x);
	}
	return ;
	
}
int    main()
{
	cin>>n;
	for(long long   i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	t[1].l=1;t[1].r=n;
	build(1,1,n);
	/*for(long long   i=1;i<=n*4;i++)
	{
		cout<<t[i].s<<" "; 
	}*/
	cin>>m;
	for(long long   i=1;i<=m;i++)
	{
		long long   q,w,e,r;
		cin>>e;
		if(e==1)
		{
			cin>>q>>r>>w;
			chenge(1,w,q,r);
		}
		else
		{
			cin>>q>>w;
			cout<<find(1,q,w)<<endl;
		}
	}
}
