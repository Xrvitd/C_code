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
int n,m,s,ti,c;
int h[N],v[N],next[N],p=0,d[N],f[N];
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
struct re
{
	int x,y,qz;
} q[N];
void mem()
{
	for(int i=1;i<=n;i++)
	{
		f[i]=i;
	}
}
int find(int x)
{
	return f[x]=f[x]==x ? x:find(f[x]);
}
void add(int a,int b,int c)
{
	p++;
	q[p].x=a;
	q[p].y=b;
	q[p].qz=c;
}
bool cmp(const struct re a,const struct re b)
{
	return a.qz>b.qz;
}
int main()
{
	freopen("truck13.in","r",stdin);
	freopen("truck13.txt","w",stdout);
	n=get_num();
	m=get_num();
	for(int i=1;i<=m;i++)
	{
		int qqq,w,e;
		qqq=get_num();w=get_num();e=get_num();
		add(qqq,w,e);
		//add(w,qqq,e);
	}
	sort(q+1,q+p+1,cmp);
	/*for(int i=1;i<=m*2;i++)
	{
		cout<<q[i].qz<<" ";
	}*/
    c=	get_num();
	for(int i=1;i<=c;i++)
	{
		int qq,w,ans=2147483647;
		bool vv=0;
		qq=get_num();w=get_num();
		mem();
		for(int j=1;j<=p;j++)
		{
			if(find(q[j].x)!=find(q[j].y))
			{
				f[f[q[j].x]]=f[q[j].y];
				//ans=min(ans,q[j].qz);
			}
			if(find(qq)==find(w))
			{
				printf("%d\n",q[j].qz);
				vv=1;
				break;
			}
		}
		if(!vv)
		{
			printf("-1\n");
		}
	}
	return 0;
}
