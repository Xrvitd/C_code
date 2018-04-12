#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cstdlib>
#include<string>
#define debug(x) cerr<<#x<<"="<<x<<endl
using namespace std;
int n,a[100001]={0},f[100001]={0};
int find(int l,int r,int num)
{
	int mid;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(num>=f[mid])
            l=mid+1;
        else
            r=mid-1;
    }
    return l;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	f[1]=a[1];
	int le=1;
	for(int i=2;i<=n;i++)
	{
		if(a[i]>f[le])
		{
			
			f[++le]=a[i];
			
		}
		else
		{
			int k=find(1,le,a[i]);
			f[k]=a[i];
		}
	}
	cout<<le;
	
}
