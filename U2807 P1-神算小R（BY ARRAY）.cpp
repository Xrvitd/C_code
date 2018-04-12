#include<iostream>
using namespace std;
long long n,m,s=1;
int main()

{
	cin>>n;
	if(n==0)
	{
		cout<<0;
		return 0; 
	} 
	if(n==63)
	{
		cout<<"9223372036854775808";
		return 0; 
	} 
	for(int i=1;i<=n;i++)
	{
		s*=2;
	}
	cout<<s;
 } 
