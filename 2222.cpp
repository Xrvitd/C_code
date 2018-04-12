#include<stdio.h>
char c[1001];
int a[40]={0}; 
int i,j,k,l=3; 
int main()
{
	a['h'-'a'+1]=-1;a['e'-'a'+1]=1;a['l'-'a'+1]=2;a['o'-'a'+1]=3;
    scanf("%[^\n]", &c);
    for(i=0;c[i]!='\0';i++)
    {
    	if(c[i]==' ')
    	{
    		printf(" ");
    		continue;
    	}
    	k=(int) (c[i]-'a'+1);
    	if(a[k]==0)
    	{
    		l++;
    		a[k]=l;
    	}
    	if(a[k]==-1)
    	{
    		printf("%d",0);
    		continue;
    	}
    	printf("%d",a[k]);
    }
    printf("\n%s",c);
} 
