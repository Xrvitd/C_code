#include<iostream>
#include<cstring>
using namespace std;
int n,m,b[10001]={0},a[10001]={0};int k=1;
int dp()
{
	for(int i=1;i<k;i++)
	{
		if(a[i]<0)
			continue;
		for(int j=1;j<i;j++)
		{
			if(a[j]<0)
			continue;
			if(a[j]<=a[i])
			b[i]=max(b[i],b[j]+1);
		}
	}
} 
int main()
{
	while(cin>>n)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b)); 
		for(int i=1;i<=n;i++)
		{
			cin>>b[i];
		}
	k=n+1;
	for(int i=1;i<k;i++)
	{
		a[i]=b[k-i];
	}
	for(int i=1;i<k;i++)
	{
	b[i]=1;
	}
	dp();
	int ans=0,kk;
	for(int i=1;i<k;i++)
	{
		int xx=ans;
		ans=max(ans,b[i]);
		if(xx!=ans)
		{
			kk=i;
		}
	}
	int qw=ans+1,we=a[kk]+1;
	for(int i=kk;i>=1;i--)
	{
		if(b[i]==qw-1&&a[i]<we)
		{
			we=a[i];
			a[i]=-1;
			qw-=1;
		}
	}
	int an=1;
    bool v=0;
	while(!v)
	{
		an++;
		for(int i=1;i<k;i++)
	{
		if(a[i]>0)
	     b[i]=1;
	     else
	     b[i]=0;
	}
		dp();
		int ans1=0,kk1;
	   for(int i=1;i<k;i++)
	{
		int xx=ans1;
		ans1=max(ans1,b[i]);
		if(xx!=ans1)
		{
			kk1=i;
		}
	}

	int qw1=ans1+1,we1=a[kk1]+1;
	for(int i=kk1;i>=1;i--)
	{
		if(b[i]==qw1-1&&a[i]<we1)
		{
			we1=a[i];
			a[i]=-1;
			qw1-=1;
		}
	}
	v=1;
	for(int i=1;i<k;i++)
	{
		if(a[i]>0)
		v=0;
	}
	}
	cout<<an;	
	}
}
