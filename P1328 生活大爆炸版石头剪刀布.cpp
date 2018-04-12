#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,x,y,s1=0,s2=0;
int a[5][5];
int b[201],c[201];
int main()
{

    a[0][2]=1,a[0][3]=1,a[1][0]=1,a[1][3]=1,a[2][1]=1,a[2][4]=1;
    a[3][2]=1,a[3][4]=1,a[4][0]=1,a[4][1]=1;
    cin>>n>>x>>y;
    for(int i=1;i<=x;i++)
    {
        cin>>b[i];
    }
    for(int i=1;i<=y;i++)
    {
        cin>>c[i];
    }
    for(int k=1,i=1,j=1;k<=n;i++,j++,k++)
    {
        s1+=a[b[i]][c[j]];
        s2+=a[c[j]][b[i]];
        if(i==x)i=0;
        if(j==y)j=0;
    }
    cout<<s1<<" "<<s2;
}

