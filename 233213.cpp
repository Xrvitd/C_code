#include <stdio.h>
#include <stdlib.h>
int a[4],d[4],f[4],i,j,b,c,e;
void swap()
{
	e=a[i];a[i]=a[i+1];a[i+1]=e;
    e=d[i];d[i]=d[i+1];d[i+1]=e;
	e=f[i];f[i]=f[i+1];f[i+1]=e;
} 
int main()
{
    scanf("%d%d%d%d",&a[0],&a[1],&a[2],&a[3]);
    for(i=0;i<=3;i++)
    {
        b=a[i]/1000;
        c=a[i]-b*1000;
        d[i]=c/10;
        f[i]=c;
    }

    for(j=0;j<3;j++)
    {

      for(i=0;i<3-j;i++)
      {
        if(d[i]>d[i+1])
        {
            swap();
        }
        if(d[i]==d[i+1])
        {
            if(f[i]>f[i+1])
            {
                swap();
            }else 
            if(a[i]>a[i+1])
            {
                swap();
            }
        }

      }

    }
    for(i=0;i<=3;i++)
        printf("%d ",a[i]);
    return 0;
}

