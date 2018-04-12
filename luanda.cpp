#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<queue>
#include<algorithm>
#include<map>
using namespace std;
long long n,m;
inline long long get_num()
{
	char c;
	bool flag=0;
	long long sum=0;
	while((c=getchar())==' '||c=='\n'||c=='\r');
	if(c=='-') flag=1;
	else sum=c-'0';
	while(isdigit(c=getchar()))
	sum=sum*10+c-'0';
	return (flag? -1:1) * sum;
} 
int main()
{
	n=get_num();
	cout<<n;
	
}
