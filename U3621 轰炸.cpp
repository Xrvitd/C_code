#include<iostream>
using namespace std;
int x1,x2,y1,y2,ans=0;
struct re
{
	int x,y;
} a[1000001];
int f(int x)
{
	int y;
	bool vv=0;
	double k=(double) (y2-y1)*(x-x1)/(x2-x1);
	if((k-(int)k)!=0)
	{
		return -2147483647;
	}
	y=y1+(int) k;
	return y;
} 
int main()
{
	cin>>x1>>y1>>x2>>y2;
	if(x1==x2)
	{
		int n1,m1;
	if(y1>y2)
	{
		m1=y1;n1=y2;
	}else{
		m1=y2,n1=y1;
	}
	    cout<<m1-n1-1<<"\n";
	    for(int i=n1+1;i<m1;i++)
	    {
	    	cout<<x1<<" "<<i<<"\n";
	    }
	    return 0;
	}
	if(y1==y2)
	{
		int n2,m2;
	if(x1>x2)
	{
		m2=x1;n2=x2;
	}else{
		m2=x2,n2=x1;
	}
	    cout<<m2-n2-1<<"\n";
	    for(int i=n2+1;i<m2;i++)
	    {
	    	cout<<i<<" "<<y1<<"\n";
	    }
	    return 0;
	}
	int n,m;
	if(x1>x2)
	{
		m=x1;n=x2;
	}else{
		m=x2,n=x1;
	}
	for(int i=n+1;i<m;i++)
	{
		int l=f(i);
		if(l!=-2147483647)
		{
			ans++;
			a[ans].x=i;
			a[ans].y=l;
			//cout<<i<<" "<<l<<"\n";
		}
	}
	cout<<ans<<"\n";
	for(int i=1;i<=ans;i++)
	{
		cout<<a[i].x<<" "<<a[i].y<<"\n";
	}
} 
