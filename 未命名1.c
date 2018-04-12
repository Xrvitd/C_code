#include <stdio.h>  
int main()  
{  
    int     a[100000];  
    int     i, j,n; 
	
    scanf("%d",&n); 
    
    for (i = 1; i <= n; i++)  
    {  
        scanf("%d",&a[i]);
    }  

    int temp;  
        for(i=1;i<=n;i++)  
        {  
            for(j=n;j>i;j--)  
            {  
                if(a[j-1]>a[j])  
                {  
                    temp=a[j];  
                    a[j]=a[j-1];  
                    a[j-1]=temp;  
                    
                }  
            }  
            
        }  
    
    for (i = 1; i <=n; i++)  
        printf("%d ", a[i]);  
    return    0;  
}  
