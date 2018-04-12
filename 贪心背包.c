#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdio.h>
#include<time.h>
int w[2333],v[2333];
double q[2333];
    int num,maxv=0;  
    int n, c, tempw, tempv;  
    int i,j,k,ty,start,finish;
	double t; 
void quicksort()
{
    for(j=0;j<n;j++)
	for(i=0;i<n-j;i++) 
	  if (q[i]>q[i+1]) 
	    {t=q[i];q[i]=q[i+1];q[i+1]=t;
	    ty = w[i];w[i]=w[i+1];w[i+1]=ty;
	    ty= v[i];v[i]=v[i+1];v[i+1]=ty;
		}
}
int main()  
{   
    freopen("out.txt","r",stdin);
    printf("input the number and the volume:");  
    scanf("%d%d",&n,&c);  
   
    printf("input the weights:");  
    for(i=0;i<n;i++)  
        scanf("%d",&w[i]);
  
    printf("input the values:");  
    for(i=0;i<n;i++)  
        scanf("%d",&v[i]);
        start=clock();
    for(i=0;i<n;i++)
    {
    	q[i]= (double)v[i] / (double)w[i];
    }
    
    quicksort(); 

for(i=n;i>0;i--)
{
c-= w[i];
if(c<0) break;
maxv+=v[i];
} 
finish=clock();
printf("%d\n",maxv);
printf("Ê±¼äÎª£º%f\n",time);
} 
