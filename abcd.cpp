#include<iostream>
using namespace std;
int main()
{
	int i=0,sum=0;

char man=' ';

for(i=0;i<=3;i++)

{

man='A'+i;

sum=(man!='A')+(man=='C')+(man=='D')+(man!='D');

if(sum==3)

{

cout<<man;

}

}
}
