#include<stdio.h>
unsigned int num;
int sum=0;
int main()
{
	scanf("%u", &num);
	int k=num;
	while(k>0)
	{
		k/=10;
		sum++;
	}
	k=num;
	printf("%d \n",sum);
	for(int i=1;i<=sum;i++)
	{
		int x=1;
		for(int j=1;j<(sum-i+1);j++)
		{
			x*=10;
		}
		printf("%d\n",k/x);
		k=k%x;
	}
	while(num>0)
	{
		printf("%d",num%10);
		num/=10;
	}
	return 0;
} 
