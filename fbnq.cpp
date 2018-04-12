#include<iostream>
using namespace std;
int n;
int main()
{
	cin>>n;
	long long l1=0,l2=1,x;
	for(int i=3;i<=n;i++)
	{
		x=l1+l2;
		l1=l2;
		l2=x;
		cout<<x<<endl;
	} 
	
} 
