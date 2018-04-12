#include<iostream>
using namespace std;
int n,m,k;
int main()
{
    cin>>n;
    for(int i=1;i<=n-1;i++)
    {
    	for(int j=1;j<=n-i;j++)
        {
        	cout<<" "; 
        }
        for(int j=1;j<=i*2-1;j++)
        {
        	cout<<"*";
        }
        cout<<"\n";
    }
    for(int i=1;i<=n*2-1;i++) cout<<"*";
    cout<<"\n";
    for(int i=1;i<=n-1;i++)
    {
    	for(int j=1;j<=i;j++)
        {
        	cout<<" "; 
        }
        for(int j=1;j<=(n-i)*2-1;j++)
        {
        	cout<<"*";
        }
        cout<<"\n";
    }
}

