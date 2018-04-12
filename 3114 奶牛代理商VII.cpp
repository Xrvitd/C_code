#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cstdlib>
#include<string>
#include<bitset>
#include<iomanip>
#include<deque>
#define INF 1000000000
#define fi first
#define se second
#define N 100005
#define P 1000000007
#define debug(x) cerr<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
int n,m;
int main()
{
	string s;
	cin>>s;
	if(s=="BI,YU")
	{
		cout<<"XING,XIANG,SHENG,DONG";
	}
	if(s=="NI,REN")
	{
		cout<<"SHENG,DONG,XING,XIANG";
	}
	if(s=="PAI,BI")
	{
		cout<<"YOU,QI,SHI";
	}
	if(s=="KUA,ZHANG")
	{
		cout<<"TU,CHU,BEN,ZHI";
	}
	if(s=="FAN,WEN")
	{
		cout<<"JIA,QIANG,YU,QI";
	}
	if(s=="FAN,YU")
	{
		cout<<"ZENG,JIA,FENG,CI";
	}
	if(s=="FAN,FU")
	{
		cout<<"TU,CHU,QIANG,DIAO";
	}
	

}

