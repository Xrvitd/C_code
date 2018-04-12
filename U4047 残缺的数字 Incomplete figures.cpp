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
int n,m,a[11],x,b[1000001][10];
bool vv=0;
inline int get_num()
{
int num = 0;
char c;
bool flag = false;
while ((c = getchar()) == ' ' || c == '\n' || c == '\r');
if (c == '-') flag = true;
else num = c - '0';
while (isdigit(c = getchar()))
num = num * 10 + c - '0';
return (flag ? -1 : 1) * num;
}
bool ch(int p[])
{
	for(int i=0;i<10;i++)
	{
		if(a[i]!=p[i])return 0;
	}return 1;
}
int main()
{
	for(int i=0;i<10;i++)
	{
		cin>>a[i];
	}
	b[1][1]=1;
	for(int i=2;i<=2000;i++)
	{
		for(int j=0;j<10;j++)
		{
			b[i][j]=b[i-1][j];
		}
		int k=i;
		while(k)
		{
			b[i][k%10]++;
			k/=10;
		}
		/*for(int j=0;j<10;j++)
		{
			cout<<b[i][j]<<" ";
		}cout<<"\n";*/
	}
	for(int i=1;i<=2000;i++)
	{
		
		for(int j=1;j<=i;j++)
		{
			int k[10];
			for(int l=0;l<10;l++)
		    {
			k[l]=b[i][l];
		    }
		    int kd=j;
	 	while(kd)
		{
			k[kd%10]--;
			kd/=10;
		}
		    if(ch(k))
		    {
		    	vv=1;
		    	cout<<i<<" "<<j<<endl;
		    }
		}
	}
	if(!vv)
	cout<<"NO ANSWER";
	

}

