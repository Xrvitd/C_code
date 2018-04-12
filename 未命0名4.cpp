#include<iostream>  
#include<algorithm>  
#include<cstring>  
using namespace std;  
long long n,m,q,z=0;  
 long long  a[21][21][21]={0};  
 long long  n1[21],m1[21],q1[21],z1[21];  
 long long  w( long long  n, long long  m, long long  q)  
{  
    if(a[n][m][q]!=0)  
    {  
        return a[n][m][q];  
    }else  
    {  
    if(n<=0||m<=0||q<=0)  
    {  
        return 1;   
    }else  
    {  
    if(n>20||m>20||q>20)  
    {  
        return w(20,20,20);   
    }else  
    {  
    if(n<m&&m<q)  
    {  
      
        a[n][m][q]=w(n,m,q-1)+w(n,m-1,q-1)-w(n,m-1,q);  
        return a[n][m][q];  
    }else  
    {  
        a[n][m][q]=w(n-1,m,q)+w(n-1,m-1,q)+w(n-1,m,q-1)-w(n-1,m-1,q-1);  
        return a[n][m][q];  
    }}}}  
      
 }   
int  main()  
{  
     long long  i=0;  
    while(cin>>n>>m>>q)  
    {  
        i++;  
        if(n==-1&&m==-1&&q==-1)  
        break;  
        else  
        {  
            if((n>20&&m>0&&q>0)||(m>20&&n>0&&q>0)||(q>20&&m>0&&n>0))  
            {  
                z=w(20,20,20);  
            }else  
            {  
            memset(a,0, sizeof(a));  
           z=w(n,m,q);  
            }  
      
         }   
         n1[i]=n;  
         m1[i]=m;  
         q1[i]=q;  
         z1[i]=z;  
          
    }  
      
    for( long long  j=1;j<i;j++)  
    {  
         cout<<"w("<<n1[j]<<", "<<m1[j]<<", "<<q1[j]<<")"<<" = "<<z1[j]<<endl;  
    }  
    return 0;  
 }
