#include<iostream>
#include<cstdio>
using namespace std;
int ans,n,a[100001],f[100001];
int main()
{
	while(cin>>n)
	{
	for(int i=1;i<=n;i++)
	 cin>>a[i];
	f[1]=a[1]; f[0]=0;  ans=1;
	for(int i=2;i<=n;i++)
	  if(a[i]>f[ans]) { ans++; f[ans]=a[i];	  }
	  else
	  for(int j=ans;j>=1;j--)
	  if(f[j]>=a[i]&&f[j-1]<a[i])
	    f[j]=a[i];
	   cout<<ans<<endl;
    }  
}

