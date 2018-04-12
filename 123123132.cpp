#include<stdio.h>
#include<iostream>
using namespace std;

bool run(int i)
{
		if((i%4==0&&i%100!=0)||(i%400==0)) 
		{
			return 1;
		}else
		{
			return 0;
		}
}
int main()
{
	int m;
	scanf("%d",&m);
	cout<<run(m);
}
