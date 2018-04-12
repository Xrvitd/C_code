#include <stdio.h>
#include <stdlib.h>
int number[100];
char c[100];
int i=0,j=0,x=0,y=0;
int tempnumber[100];
char tempchar[100];
void pushn(int a)//存入数字
{
    number[i]=a;i++;
}
void pushc(char z)//改成字符
{
    c[j]=z;j++;
}
void popchar()//转出字符 使用栈
{
    empchar[y]=c[j-1];
	y++;j--;
}
void popnumber()//转出数字
{
    tempnumber[x] = number[i-1];
	i--;x++;
}
int main()
{
    int lenth=0;
	int k;
	for(k=0;k<100;k++)
    {
        number[k]=-1000;tempnumber[k]=-1000;c[k]='@';tempchar[k]='@';
    }
    int sum=0,b;
	for(b=0;b<b+1;b++)
    {
        char temp = getchar();
		if(temp<='9'&&temp>='0')
        {
		    sum=(temp-'0')+sum*10;
		}
        else
		{
			if(temp=='\n')   
			{
			    pushn(sum);
	    		break;
			}
        	else
      	    {
			pushc(temp);
			lenth++;
			pushn(sum);
			sum = 0;
			}
		}
	}
    int t;
    popnumber();
    int lenth2 = 0;
    for(t=lenth;t>0;t--)
    {
	    int m,n;
        popchar();
        if(tempchar[y-1]=='*'||tempchar[y-1]=='/')
        {
            m=number[i-1];n=tempnumber[x-1];
            if(tempchar[y-1]=='*')
            {
                tempnumber[x-1]=m*n;
                i--;
                tempchar[y-1] = '@';
                y--;
            }
            else
            {
			    tempnumber[x-1]=m/n;i--;
                tempchar[y-1] = '@';y--;
			}
        }
        else
        {
		    popnumber();lenth2++;
        }
    }
    sum = 0;
    for(t = 0;t<lenth2;t++)
    {
        if(tempchar[t]=='+')
        {
	    	sum= sum+tempnumber[t];
		}
        else
        {
	    	sum = sum-tempnumber[t];
		}
    }
    sum = sum+tempnumber[t];
    printf("=%d",sum);
    return 0;
}

