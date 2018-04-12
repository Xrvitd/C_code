#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int x,y,rev; 
long long n,m,ans=0,p=1000000007;
void extend_Euclid(int a, int b)  
{  
    if(b==0)  
    {  
        x = 1;  
        y = 0;  
        return;  
    }  
    extend_Euclid(b, a%b);  
    int t = x;  
    x = y;  
    y = t - a/b*y;  
}  
int ny(int b)
{
	extend_Euclid(b,p);  
	return (x%p+p)%p;
}
long long pow(long long a,long long b)
{
	long long ans=1;
	for(;b;b>>=1,a=a*a,a%=p)
	{
		if(b&1)
		{
			ans=ans*a;
			ans%=p;
		}
	}
	return ans%p;
} 
int main()
{
	cin>>n>>m;
	ans+=m;
	for(long long i=2;i<=n;i++)
	{
		ans+=(pow(i,m+1)-i)*ny(i-1)%p;
	}
	cout<<ans%p;

}

