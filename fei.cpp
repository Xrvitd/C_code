#include<stdio.h>
#include<string.h>
char s[101],c[101];
int i,j,v=0;
int main()
{
    gets(s);gets(c);
    for(i =System.out.println() 0 ; i<strlen(s) ; i++)
    {
    	v=0;
    	for(j=0;j<strlen(c);j++)
    	{
    		if(s[i+j]!=c[j])
    		{
    			v=1;
    			break;
    		}
    	}
    	if(! v)
    	{
    		printf("%d",i+1);
    		break;
    	}
    }
} 
