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
int n,m,a[10001],b[100001];
string s;
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
int dfs(int x,int y)
{
	if(x==y)
	{
		if(a[x]==0)
		{
			cout<<"B";
			return 1;
		}
		
		if(a[x]==1)
		{
			cout<<"I";
			return 2;
		}
		
	}else
	{
		int mid=(x+y)>>1,i,j;
		i=dfs(x,mid);
		j=dfs(mid+1,y);
		if(i==j&&i==1)
		{
			cout<<"B";
			return 1;
		}
		if(i==j&&i==2)
		{
			
			cout<<"I";
			return 2;
		}
		if((i==j&&i==3)||i!=j)
		{
			cout<<"F";
			return 3;
		}
	}
}
int main()
{
	cin>>n;
	cin>>s;
	int k=s.size();
	for(int i=0;i<k;i++)
	{
		a[i+1]=s[i]-'0';
	}
	dfs(1,k);

}

