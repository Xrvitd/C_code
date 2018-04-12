#include<iostream>
using namespace std;
long long  n,m,p,ans=1; 
long long  a[3][8]={0};
long long  ksm(long long  n,long long  m)
{
	long long  ans=1;
	for(;m;n=(n*n)%p,m>>=1)
	{
		if(m & 1)
		{
			ans=(ans*n)%p;
		}
	}
	return ans;
}
int main()
{
	cin>>n>>m;
	p=46640;
	cout<<ksm(n,m);
	
}
