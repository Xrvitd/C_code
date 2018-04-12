#include<iostream>
using namespace std;
string s;
int a[401];
int main()
{
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
	    int k=s[i];
	    a[k]++;
	}
	for(int i=1;i<=400;i++)
	{
		if(a[i]%2==0)a[i]=-1;
	}
	for(int i=0;i<s.size();i++)
	{
		int k=s[i];
		if(a[k]>0&&a[k]!=1)
		{
			a[k]--;
		}
		if(a[k]==1)
		{
			cout<<s[i];
		}
	}
}
