#include<iostream>
#include<cmath>
using namespace std;
int n,m,ans=0;
bool su(int x)
{
	if(x==0) return 0;
	if(x==1) return 0;
	if(x==2) return 1;
	for(int i=2;i<=sqrt(x);i++)
	{
		if(x%i==0)
		return 0;
	}
	return 1;
}
int main()
{
	cin>>n>>m;
	for(int i=n;i<=m;i++)
	{
		if(su(i))
		{
			ans++;
		}
	}
	cout<<ans;
 } 
