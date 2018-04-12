#include<cstdio>
int main()
{
	int s;
	scanf("%d",&s);
	s=0;
    for(int i=1;i<=100;i++)
	{
		s+=i;
	}	
	printf("%d",s);
}
