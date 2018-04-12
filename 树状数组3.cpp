#include<iostream> 
using namespace std;
long long n,m,a[1000001]={0},c[1000001]={0},d[1000001]={0},b[1000001]={0};
long long lowbit(long long a)
{
	return a&-a;
}
long long sum(long long x)
{
	long long   ans=0;
	while(x>0)
	{
		ans+=c[x];
		x-=lowbit(x);
	}
	return ans;
}
long long sum1(long long x)
{
	long long ans=0;
	while(x>0)
	{
		ans+=b[x];
		x-=lowbit(x);
	}
	return ans;
}
long long 

h(long long x,long long k,long long o[])
{
	while(x<=n)
	    {
		o[x]+=k;
		x+=lowbit(x);
	    }
}
int main()
{
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		d[i]=a[i]-a[i-1];
	}
	for(long long i=1;i<=n;i++)
	{
	    ch(i,d[i],c);
	    ch(i,i*d[i],b);
	}
	cin>>m;
	for(long long i=1;i<=m;i++)
	{
		long long q,w;
		cin>>q;
		if(q==1)
		{
			long long e,r,t;
			cin>>e>>r>>t;
			d[e]+=t;
			d[r+1]-=t;
		    ch(e,t,c);
		    ch(r+1,-t,c);
		    ch(e,e*t,b);
		    ch(r+1,-(1+r)*t,b);
		}else
		{
			long long e,r,ll=0;
			cin>>e>>r;
			ll=((r+1)*sum(r)-sum1(r))-((e)*sum(e-1)-sum1(e-1));
			cout<<ll<<endl;
		}
	}
 } 
