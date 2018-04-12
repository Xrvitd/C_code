#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;
int n,m,k,s4=0,s7=0,a[100001],js[100001]={0},ans;
int c(int x,int y)
{
	int q=1,w=1;
	for(int i=1;i<=y;i++)
	{
		q*=x-i+1;
	}
	//if(!js[100001])
//	{
		for(int i=1;i<=y;i++)
		{
			w*=i;
		}
//	}
	return (q/w);
}
int main()
{
	freopen("lucky.in","r",stdin);
	 freopen("lucky.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==4) s4++;
		if(a[i]==7) s7++;
	}
	if(k>=4)
	{
		ans=c(n,k)-c(s4,2)*c(n-s4,k-2)-c(s7,2)*c(n-s7,k-2)+c(s4,2)*c(s7,2)*c(n-s4-s7,k-4);
	//cout<<"c(s4,2)*c(s7,2)*c(n-s4-s7,k-4)=="<<c(n,k)<<endl;
	cout<<ans;
	}else
	{
		ans=c(n,k)-c(s4,2)*c(n-s4,k-2)-c(s7,2)*c(n-s7,k-2);
	//cout<<"c(s4,2)*c(s7,2)*c(n-s4-s7,k-4)=="<<c(n,k)<<endl;
	cout<<ans;
	}
	return 0;
	 fclose(stdin);
    fclose(stdout);
}

