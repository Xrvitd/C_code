#include<ctime>
#include<cstdlib>
#include<cstdio>
#include<iostream>
#define RAND_MAX 327688888
using namespace std;
int a,b;
int main()
{
  	srand(unsigned(time(NULL)));
  	cin>>a>>b;
  	bool v=1;
  	while(v)
  	{
  		int k=rand();
  		if(k>=a&&k<=b)
  		{
  			cout<<k;
  			v=0;
  		}
  	
  	}
  	 // printf("%d",rand()%10+1); 
  	return 0;
}
