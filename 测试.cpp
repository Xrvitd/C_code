#include<iostream>
using namespace std;
int n,m,mm,nn;
int main()
{
	cin>>nn>>mm;
	for(int m=1;m<=mm;m++)
	{
		n=nn;
		int k=(1<<m);
	    if(n>=k)
	    {
	    	n%=k;
	    }
	    if(n>=(1<<(m-1)))
	    {
	    	cout<<"1";
	    }else
	    {
	    	cout<<"0";
	    }
	}
	
} 
