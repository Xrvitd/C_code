#include <iostream>
using namespace std;
void memset1(int* a,int b,int c)
{
	for(int i=0;i<c/4;i++)
	{
		a[i]=b;
	}
} 

void hebing(int* a,int sa,int* b,int sb,int *c)
{
	int k=0;
	for(int i=0;i<sa/4;i++,k++)
	{
		c[k]=a[i];
	}
	for(int i=0;i<sb/4;i++,k++)
	{
		c[k]=b[i];
	}
}

int find(int* a,int c,int b)
{
	for(int i=0;i<c/4;i++)
	{
		if(a[i]==b)
		{
			return i;
		}
	}
	return -1;
}

void delete1(int* a,int c,int b)
{
	for(int i=0;i<c/4;i++)
	{
		while(a[i]==b)
		{
			for(int j=i;j<(c/4)-1;j++)
			{
				a[j]=a[j+1];
			}
			a[(c/4)-1]=-1;
		}
	}
}

void print(int* a,int c)
{
	for(int i=0;i<c/4;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<'\n';
}
