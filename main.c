#include<stdio.h>
int main()
{
	int i,n,s1=0,s2=0,s3=0,s4=0,s5=0,s6=0,s7=0,s8=0,a[9];
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=n;i++)
	{
		if(a[i]==1)
			s1++;
		else if(a[i]==2)
			s2++;
		else if(a[i]==3)
			s3++;
		else if(a[i]==4)
			s4++;
		else if(a[i]==5)
			s5++;
		else if(a[i]==6)
			s6++;
		else if(a[i]==7)
			s7++;
		else if(a[i]==8)
			s8++;
	}
	if((s7+s8==1||s7+s8==2)&&(s1+s2==1||s1+s2==0)&&(s3+s4==1||s3+s4==0)&&(s5+s6==2||s5+s6==0))
		printf("1\n");
	else
		printf("0\n");
	return 0;
}
