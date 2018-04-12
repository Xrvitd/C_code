#include<iostream>
#include <algorithm>
using namespace std;
void set_array(int* a,const int size,int n)
{
	for(int i=0;i<size;i++)
	{
		a[i]=n;
	}
}

int* cat(int a[], int b[],int *c, const int size1,const int size2)
{
	int i;
	for(i=0;i<size1;i++)
	{
		c[i]=a[i];
	}
	for(i+1;i<size1+size2;i++)
	{
		c[i]=b[i];
	}
	return c;
	
}

int* find_spot(int a[],int size,int n)
{
	int i,cont;
	int b[1000];
	bool t=0;
	for(i=0;i<size;i++)
	{
		if(a[i]==n)
		{
			t=1;
			b[cont]=i;
			cont++;	
		}
	}
	if(t)
		return b;
	else
	{
		cout<<"cant find!";
		return NULL;
	}
}

int delete_array(int* a,int n,int size,int* newa)
{
	int len=1;
	for(int i=0;i<size;i++)
	{
		if(a[i]!=n)
		{
			newa[len-1]=a[i];
			len++;
		}
	}
	return len;
}

void print_array(int a[],int size)
{
	for(int i=0;i<size;i++)
	{
		cout<<a[i]<<' ';
	}
}

void sort_array(int* a,int size)
{
	sort(a,a+size);
}
int main()
{
	
}



