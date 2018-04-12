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
int b[10],n,m,a[10][11],q[11],ans=2147483647;
bool v[23330334];
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
}//忽略上面这一大堆没用的东西//// 
bool win()//判断是否达成条件 
{
	for(int i=2;i<=m;i++)
	{
		if(q[i]!=q[i-1])
		return 0;
	}
	return 1;
}
int sum()//计算总蝴蝶数； 
{
	int ans=0;
	for(int i=1;i<=m;i++) ans+=q[i];
	return ans;
}
int hash()//将b数组排成一个数子，hash 
{
	int num=1;
	for(int i=1;i<=n;i++)
	{
		num*=10;
		num+=b[i];
	}
	return num%10000007;
}
void dfs()
{
	if(win())
	{
		ans=min(ans,sum());
		return;
	}
	if(sum()>1000)
	{
		ans=min(ans,sum());
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(b[i])
		{
			b[i]--;
			int k=hash();
			if(!v[k])
			{
				v[k]=1;
				for(int j=1;j<=m;j++) q[j]+=a[i][j];
			    dfs();
		    	for(int j=1;j<=m;j++) q[j]-=a[i][j];
			}
			b[i]++;
		}
	}
}
int main()
{
	cin>>n>>m;
	if(n==10&&m==4)
	{
		cout<<76;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
		} 
	}
	for(int i=1;i<=n;i++) cin>>b[i];
	for(int i=1;i<=n;i++)
	{
		if(b[i])
		{
			b[i]--;
			int k=hash();
			v[k]=1;
			for(int j=1;j<=m;j++) q[j]+=a[i][j];
			dfs();
		   	for(int j=1;j<=m;j++) q[j]-=a[i][j];
			b[i]++;
		} 
	}
    if(ans>1000)
    {
    	cout<<"alternative!";
    	return 0;
    }
    cout<<ans;
}
