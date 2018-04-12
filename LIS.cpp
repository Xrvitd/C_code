#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include<cstdio>
using namespace std;
#define MAX 40000
int a[MAX+5];
int dp[MAX+5];
int n;
int search(int num,int l,int r)
{
    int mid;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(num>=dp[mid])
            l=mid+1;
        else
            r=mid-1;
    }
    return l;
}
int main()
{
    int cas=0;
    int x,y;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);

        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);

        }
        memset(dp,0,sizeof(dp));
        dp[1]=a[1];
        int len=1;
        for(int i=2;i<=n;i++)
        {
            if(a[i]>=dp[len])
                dp[++len]=a[i];
            else
            {
                int pos=search(a[i],1,len);
                dp[pos]=a[i];
            }
        }
        printf("%d\n",len);
    }
    return 0;
}
