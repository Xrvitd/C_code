#include<iostream>
using namespace std;
long long n,m;
int main()
{
	while(cin>>n>>m)
	{
		if(m<=0) 
		{
				cout<<"NO\n"; continue;
		}
		long long k=(1<<m);
	    if(n>=k)
	    {
	    	n%=k;
	    }
	    if(n>=(1<<(m-1)))
	    {
	    	cout<<"YES\n";
	    }else
	    {
	    	cout<<"NO\n";
	    }
	}
	
} 
