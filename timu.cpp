#include<stdio.h>
int a[5],i,j,k,q,w;
char c[5][5]; 
int main()
{
	for(i=1;i<=4;i++)
	{
		scanf("%d",&a[i]);//读入4个数 存入数组a 

			for(j=1;j<=4;j++)// 将这4个数转化成4个字符串 
			{
				if(a[i]==0)  //如果这个数为0了，就把0加到字符串上 
				{
					c[i][5-j]='0';
					continue; //加上之后就不需要后面两句话了，所以continue一下 
				}
				c[i][5-j]=a[i]%10+'0'; //取a[i]的末位，加到字符串里的5-j的位置上 
				a[i]/=10;  // a[i] 自己除10 
			}
		
	}
	for (i = 1; i <= 4; i++)  //冒泡排序 
    {  
         
        for (j = 4; j > i; j--)  //这里面原本是如果a[j]<a[j-1] 则交换他们两个的值 
        {  
            q= (c[j][2]-'0')*10 +c[j][3]-'0';
            w= (c[j-1][2]-'0')*10 +c[j-1][3]-'0';//定义q w为这个数字的中间两个数 
            if(q<w)
            {
            	for(k=1;k<=4;k++)  //这三个for 实现字符串之间的swap 
            	c[0][k]=c[j][k];
            	for(k=1;k<=4;k++)
            	c[j][k]=c[j-1][k];
            	for(k=1;k<=4;k++)
            	c[j-1][k]=c[0][k];
            }
            if(q==w)//如果相等去判断后三个数 
            {
            	q=q*10+c[j][4]-'0';
            	w=w*10+c[j-1][4]-'0';
            	if(q<w)
            	{
            		for(k=1;k<=4;k++)
            	    c[0][k]=c[j][k];
                	for(k=1;k<=4;k++)
                	c[j][k]=c[j-1][k];
                	for(k=1;k<=4;k++)
                	c[j-1][k]=c[0][k];
            	}
            	if(q==w)//如果还相等就去判断4个数 
            	{
            		q+= (c[j][1]-'0')*1000; 
            		w+= (c[j-1][1]-'0')*1000; 
            		if(q<w)
            		{
            			for(k=1;k<=4;k++)
            	        c[0][k]=c[j][k];
                    	for(k=1;k<=4;k++)
                    	c[j][k]=c[j-1][k];
                    	for(k=1;k<=4;k++)
                    	c[j-1][k]=c[0][k];
            	  	}
            	}
            }
        }  
    }  
	for(i=1;i<=4;i++)
	{
		for(j=1;j<=4;j++)
		{
			printf("%c",c[i][j]);//输出 
		}
		printf(" ");
	}
} 

