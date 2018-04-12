#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
long long  n,m,p=0,ans=0;
long long  f[100001]={0};
struct zqm
{
	long long  x,y,s;
}a[100001];
long long  find(long long  x)
  {
  	long long  i,j,r;
  	r=x;
  	while (r!=f[r])
  	  r=f[r];
  	i=x;
  	while (i!=r)
  	  {
  	  	j=f[i];
  	  	f[i]=r;
  	  	i=j;
	  }
	return r;
  }
bool cmp(struct zqm q,struct zqm w)
{
	return q.s<w.s;
}
int  main()
{
	cin>>n>>m;
	for(long long  i=1;i<=m;i++)
	{
		cin>>a[i].x>>a[i].y>>a[i].s; 
	}
	sort(a+1,a+m+1,cmp);
	for(long long  i=1;i<=n;i++) 
	f[i]=i;
	for(long long  i=1;i<=m;i++)
	{
		long long  z=a[i].x,c=a[i].y;
		if(find(z)!=find(c))
		{
			p++;
			f[f[z]]=f[c];
			ans+=a[i].s;
		}
		if(p==n-1) break;
	}
    cout<<ans;return 0;
}

