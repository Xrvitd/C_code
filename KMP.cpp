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
#define N 1000010
#define P 1000000007
#define debug(x) cerr<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
int n,m,a[1000010],b[N],ne[N];
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
void make_ne()
{
	int q,k;
	ne[0]=0;
	for(q=1,k=0;q<=m;q++)
	{
		while(k>0&&b[q]!=b[k])
		{
			k=ne[k-1];
		}
		if(b[q]==b[k]) k++;
		ne[q]=k;
	}
}
int kmp()
{
	int q=0;
	make_ne();
	for(int i=0,q=0;i<n;i++)
	{
		 while(q > 0 && b[q] != a[i])
		{
			q=ne[q-1];
		}
		if(a[i]==b[q])
		{
			q++;
		}
		if(q==m)
		{
			return i-m+1;
		}
	}
	return -2;
}
int main()
{
	int ll;
	ll=get_num();
	while(ll--)
	{
		n=get_num();
		m=get_num();
		for(int i=0;i<n;i++)
		{
			a[i]=get_num();
		}
		for(int i=0;i<m;i++)
		{
			b[i]=get_num();
		}
		cout<<kmp()+1<<endl;
		
	}

}

