#include<iostream>
using namespace std;
long long n,m,f,l=100;
struct zqm
{
	long long a[3][3];
}q[10001],p;
zqm c(zqm x,zqm y)
{
	zqm s;
	s.a[1][1]=x.a[1][1]*y.a[1][1]%l+x.a[1][2]*y.a[2][1]%l;
	s.a[1][2]=x.a[1][1]*y.a[1][2]%l+x.a[1][2]*y.a[2][2]%l;
	s.a[2][1]=x.a[2][1]*y.a[1][1]%l+x.a[2][2]*y.a[2][1]%l;
	s.a[2][2]=x.a[2][1]*y.a[1][2]%l+x.a[2][2]*y.a[2][2]%l;
	s.a[1][1]%=l;
	s.a[1][2]%=l;
	s.a[2][1]%=l;
	s.a[2][2]%=l;
	return s;
}
void debug(zqm x)
{
	for(long long i=1;i<=2;i++)
	{
		for(long long j=1;j<=2;j++)
		{
			cout<<x.a[i][j]<<" ";
		}cout<<endl;
	}
	cout<<endl;
}
zqm ksm(zqm x,long long m)
{
	zqm ans=p;
	for(;m;m>>=1,x=c(x,x))
	{
		if(m&1)
		{
			ans=c(ans,x);
		}
	}
	return ans;
}
int  main()
{
	cin>>n;
	if(n==1)
	{
		cout<<1;
		return 0;
	 } if(n==2)
	{
		cout<<2;
		return 0;
	 } 
	p.a[1][1]=1;
	p.a[1][2]=1;
	p.a[2][2]=0;
	p.a[2][1]=1;
	zqm q;
	q=p;
	/*for(long long i=1;i<=10;i++)
	{
		q=c(q,p);
		debug(q);
	}*/
	 
	zqm zq=ksm(p,n-2);
	f=zq.a[1][1]+zq.a[1][2];
	cout<<f%10;
} 
