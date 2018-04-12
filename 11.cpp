#include<stdio.h>
char chuan[17],shang,shang1[3];
int i,j,k,sum=1; 
int main()
{
	for(i=1;i<=16;i++)
	{
		chuan[i]=getchar();
		getchar();
	}
	shang=chuan[1];
	printf("%c",chuan[1]);
	for(i=2;i<=16;i++)
	{
		if(chuan[i]!=shang)
		{
			if(sum!=1)
			printf("%d",sum);
			sum=0;
			shang=chuan[i];
			printf("%c",chuan[i]);
		}
		if(chuan[i]==shang)
		{
			sum++;
		}
	}
	if(sum>1) printf("%d",sum); 
	printf(" ");
	shang1[1]=chuan[1];
	shang1[2]=chuan[2];
	sum=1;
	printf("%c%c",chuan[1],chuan[2]);
	for(i=3;i<=15;i+=2)
	{
		if(chuan[i]!=shang1[1]||chuan[i+1]!=shang1[2])
		{
			if(sum!=1)
			printf("%d",sum);
			sum=0;
			shang1[1]=chuan[i];shang1[2]=chuan[i+1];
			printf("%c%c",chuan[i],chuan[i+1]);
		}
		if(chuan[i]==shang1[1]&&chuan[i+1]==shang1[2])
		{
			sum++;
		}
	}
	if(sum>1) printf("%d",sum);
}

