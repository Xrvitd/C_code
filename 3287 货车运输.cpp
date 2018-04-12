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
#define N 50005
#define P 1000000007
#define debug(x) cerr<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
int n,m,s,ti,c;
int h[N],v[N],next[N],p=0,d[N],f[N];
map <string , int > vv;
struct re
{
	int x,y,bh,qz;
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
	return f[x]==x ? x:f[x]=find(f[x]);
}
void add(int a,int b,int c)
{
	p++;
	q[p].x=a;
	q[p].y=b;
	q[p].bh=p;
	q[p].qz=c;
}
bool cmp(const struct re a,const struct re b)
{
	return a.qz>b.qz;
}
string z(int l)
{
	
}
int main()
{
	
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int qqq,w,e;
		cin>>qqq>>w>>e;
		add(qqq,w,e);
		add(w,qqq,e);
	}
	sort(q+1,q+p+1,cmp);
	/*for(int i=1;i<=m*2;i++)
	{
		cout<<q[i].qz<<" ";
	}*/
	cin>>c;
	for(int i=1;i<=c;i++)
	{
		int qq,w,ans=2147483647;
		bool vv=0;
		cin>>qq>>w;
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
				cout<<q[j].qz<<"\n";
				
				vv=1;
				break;
			}
		}
		if(!vv)
		{
			cout<<-1<<"\n";
		}
	}
	return 0;
} 
