#include<iostream>
using namespace std;
long long n,m,f;
struct zqm
{
	int a[3][3];
}q[10001],p;
zqm c(zqm x,zqm y)
{
	zqm s;
	s.a[1][1]=x.a[1][1]*y.a[1][1]+x.a[1][2]*y.a[2][1];
	s.a[1][2]=x.a[1][1]*y.a[1][2]+x.a[1][2]*y.a[2][2];
	s.a[2][1]=x.a[2][1]*y.a[1][1]+x.a[2][2]*y.a[2][1];
	s.a[2][2]=x.a[2][1]*y.a[1][2]+x.a[2][2]*y.a[2][2];
	return s;
}
void debug(zqm x)
{
	for(int i=1;i<=2;i++)
	{
		for(int j=1;j<=2;j++)
		{
			cout<<x.a[i][j]<<" ";
		}cout<<endl;
	}
	cout<<endl;
}
zqm ksm(zqm x,int m)
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
int main()
{
	cin>>n;
	p.a[1][1]=1;
	p.a[1][2]=1;
	p.a[2][2]=0;
	p.a[2][1]=1;
	zqm q;
	q=p;
	/*for(int i=1;i<=10;i++)
	{
		q=c(q,p);
		debug(q);
	}*/
	zqm zq=ksm(p,n-3);
	f=zq.a[1][1]+zq.a[1][2];
	cout<<f;
} 
