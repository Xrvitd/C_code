#include<iostream> 
using namespace std;
int n,m,a[1000000]={0},c[1000001]={0},d[1000001]={0};
int lowbit(int a)
{
	return a&-a;
}
int sum(int x)
{
	int ans=0;
	while(x>0)
	{
		ans+=c[x];
		x-=lowbit(x);
	}
	return ans;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		d[i]=a[i]-a[i-1];
	}
	
	for(int i=1;i<=n;i++)
	{
		int x=i;
		while(x<=n)
		{
			c[x]+=d[i];
			x+=lowbit(x);
		}
	}
	
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		int q,w;
		cin>>q;
		if(q==1)
		{
			int e,r,t;
			cin>>e>>r>>t;
			d[e]+=t;
			d[r+1]-=t;
			int x=e;	
		    while(x<=n)
		{
			c[x]+=t;
			x+=lowbit(x);
		}
			int xx=r+1;
		while(xx<=n)
		{
			c[xx]-=t;
			xx+=lowbit(xx);
		}
		}else
		{
			
			int e,r=0;
			cin>>e;
			for(int i=1;i<=e;i++)
			{
				r+=d[i];
			}
			cout<<r<<endl;
		}
	}
 } 
