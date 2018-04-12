#include<iostream>
#include<algorithm>
#include<functional>
#include<vector>
#include<cstdio>
using namespace std;
int n,m;
inline int get_num()
{
	int num=0;
	bool flag=0;
	char c;
	while((c=getchar())==' '||c=='\n'||c=='\r');
	if(c=='-')
	flag=1;
	else
	num=c-'0';
	while(isdigit(c=getchar()))
	{
		num=num*10+c-'0';
	}
	return (flag ? -1:1)*num;
}
int main()
{
	n=get_num();
	cout<<n;
}
