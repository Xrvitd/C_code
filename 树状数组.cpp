#include<iostream> 
using namespace std;
int n,m,a[1000000]={0},c[1000001]={0};
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
	}
	for(int i=1;i<=n;i++)
	{
		int x=i;
		while(x<=n)
		{
			c[x]+=a[i];
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
			int e,r;
			cin>>e>>r;
			int x=e;
		while(x<=n)
		{
			c[x]+=r;
			x+=lowbit(x);
		}
		}else
		{
			int e,r;
			cin>>e>>r;
			cout<<sum(r)-sum(e-1)<<endl;
		}
	}   
 } 
