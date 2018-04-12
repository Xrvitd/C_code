#include<iostream>
#include<cstdio>
using namespace std;
int c[100010];
int n;
int lowbit(int d)
{
	return d&(-d);
}
int sum(int d)
{
	int ans=0;
	
	while(d>0)
	{
		ans+=c[d];
		d-=lowbit(d);
	}
	return ans;
	
}
int main()
{
	int q,w;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>q;
		int x=i;
	     while(x<=n)
    	{
		c[x]+=q;
		x+=lowbit(x);
    	}
	}
	int m;
/*for(int i=1;i<=n;i++)
	{
		cout<<c[i]<<" ";
	}*/ 
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		int sign,q,w;
		cin>>sign>>q>>w;
		if(sign==1)
		{
			int x=q;
	     while(x<=n)
    	{
		c[x]+=w;
		x+=lowbit(x);
    	}
		}
		else
		{
			cout<<sum(w)-sum(q-1)<<endl;
		}
	}
	return 0;
}
