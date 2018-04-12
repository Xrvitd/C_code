#include<iostream>
using namespace std;
int b[101]={0},a[10001]={0},top=0,tail=0,n=5;
bool empty()
{
	return (top==0);
}
bool full()
{
	return (top==n)
}
int ru(int x)
{
	if(!full())
	{
		a[++top]=x;
	}
}
int chu(int x)
{
	if(!empty())
	{
		x=a[top--];
	} 
}
int main()
{
    for(int i=1;i<=n;i++)
    {
    	cin>>b[i];
    }
    int j=1;
    for(int i=1;i<=n;i++)
    {
    	while(a[top]!=b[i])
    	{
    		ru(a[j]);
    	}
    }
} 
