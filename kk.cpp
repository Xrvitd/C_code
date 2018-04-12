#include<iostream>
#include<cstdio>
#include<stdlib.h>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
int n2,n,r,s[1000000],i,k,h[10]={'A','B','C','D','E','F','G','H','I','J'};
int main()
{
  cin>>n>>r;
  n2=n;
  k=1;
  while(n!=0)
  { s[k]=n%r;
    n=n/r;
    if(s[k]<0){s[k]=s[k]-r;n++;} 
    k++;
  }
  cout<<n2<<'=';
  for(i=k-1;i>=1;i--){if(s[i]>=10)putchar(h[s[i]-10]);
                      else cout<<s[i];
                     }
  cout<<"(base"<<r<<')';
  return 0;
}
