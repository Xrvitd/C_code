#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdlib>
using namespace std;
int j,o,js,os;

int main()
{
    for(int i=1;i<=100;i++)
    {
    	if(i%2==1)
    	{
    		j++;
    		js+=i;
    	}else
    	{
    		o++;
    		os+=i;
    	}
    }
    cout<<"����������"<<j<<" �ͣ� "<<js<<endl; 
    cout<<"ż��������"<<o<<" �ͣ� "<<os<<endl; 
}

