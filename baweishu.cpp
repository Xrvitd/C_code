#include<iostream>
using namespace std;
int n,r=10000000;
int main()
{
    cin>>n;
    for(int i=1;i<=8;i++)
    {
    	int m;
    	m=n/r;
    	n=n%r;
    	r=r/10;
    	cout<<m<<",";
    }
}

