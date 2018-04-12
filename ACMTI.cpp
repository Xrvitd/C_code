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
#define MP(x,y) make_pair(x,y)
using namespace std;
int n,m,k;
double x[10010],y[10010],s=0;
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
int main()
{
	cin>>k;
	for(int ii=1;ii<=k;ii++)
	{
		cin>>n;
		s=0;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i]>>y[i];
		} 
		for(int i=1;i<n;i++)
		{
			s+=x[i]*y[i+1]-y[i]*x[i+1];
		}s+=x[n]*y[1]-y[n]*x[1];
		s/=2.0;
		printf("%.2f\n",abs(s));
	}
}

