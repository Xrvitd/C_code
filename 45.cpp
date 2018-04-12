#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n+1];
    for(int i=1;i<=n;i++)
    cin>>a[i];
    int k,m=0;
    while(1)
    {
          for(int i=1;i<=n;i++)
if(a[i]>a[i-1]&&a[i-1]==0)
m++;
for(int i=1;i<=n;i++)
{
     if(a[i]!=0)
a[i]--;
else
continue;
}
for(int i=1;i<=n;i++)
{
if(a[i]!=0)
{k=0;break;}
else k=1;
}
if(k!=0)
break;
        }
cout<<m;
return 0;
}

