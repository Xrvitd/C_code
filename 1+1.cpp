#include<stdio.h>
int main()
{
	int n;
    int v=0,c=0,i,j;
	scanf("%d",&n);
	for(i=1;i<n;i++)
	{
		v=1;
		if(i==1||i==2) v=1;
		else
		for(j=2;j<i;j++)
		{
			if(i%j==0) {
				v=0;
				break;
			}
		}
		if(v)
		{
			c=1;
			if((n-i)==1||(n-i)==2) c=1;
			else
			for(j=2;j<n-i;j++)
		    {
			if((n-i)%j==0) {
				c=0;
				break;
			}
		    }
		    if(c)
		    {
		    	printf("%d %d",i,n-i);
		    	break;
		    }
		}
	}
} 
 
