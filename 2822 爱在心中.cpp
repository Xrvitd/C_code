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
int n,mm,p=0,h[100001],d[100011],l[100001],z[100001],top,k,ans=0,a[100001],color=0,cd[100001],tcd[100001],angle[100001];
bool m[1001][1001]={0};
bool f[100001];
struct zqm
{
	int v,next;
}q[100001];
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
int add(int a,int b)
{
	p++;
	q[p].v=b;
	q[p].next=h[a];
	h[a]=p;
}
void tarjan(int x)
{
	k++;
	d[x]=l[x]=k;
	p=h[x];
	top++;
	z[top]=x;
	f[x]=1;
	while(p)
	{
		int j=q[p].v;
		if(!d[q[p].v])
		{
			tarjan(q[p].v);
			if(l[x]>l[j]) l[x]=l[j];
		}
		else
		{
			if(f[j]&&d[j]<l[x])
			{
				l[x]=d[j];
			}
		}
		p=q[p].next;
	}
	if(d[x]==l[x])
	{
		int len=0;
		while(z[top+1]!=x)
		{
			f[z[top]]=0;
			top--;
			len++; 
		}
		if(len>1)
		{
			ans++;
			color++;
			/*for(i=t+1;i<=t+length;i++)//对栈进行违规操作 
			{		
			    v=stack[i];
                            for(j=t+1;j<=t+length;j++)//菜鸟我不会缩点，直接统计天使内某点的出度
                                if(map[v][stack[j]])chu[v]--;
                            angel_chu[color]+=chu[v];    //将统计后的天使内各点出度相加得到天使出度
			    is_angel[v]=color;        //将这个天使内各点染成同一种颜色
			}	*/
			for(int i=top+1;i<=top+len;i++)
			{
				int vv=z[i];
				for(int j=top+1;j<=top+len;j++)
				{
					if(m[vv][z[j]])cd[vv]--;
				}
				tcd[color]+=cd[vv];
				angle[vv]=color;
			}
		}
		
	}
	
}
int main()
{
	cin>>n>>mm;
	for(int i=1;i<=mm;i++)
	{
		int q,w;
		cin>>q>>w;
		m[q][w]=1;
		add(q,w);
		cd[q]++;
	} 
	for(int i=1;i<=n;i++)
	{
		if(!d[i])	tarjan(i);
	}
	int spea=0;
	for(int i=1;i<=ans;i++)
	{
		if(tcd[i]==0)
		{
			if(!spea)
			
			{
				spea=i;
			}
			else
			{
				spea=-1;
				break;
			}
		}
	}
	cout<<ans<<"\n";
	if(spea)
	{
		for(int i=1;i<=n;i++)
		{
			if(angle[i]==spea)
			{
				cout<<i<<" ";
			}
		}
	}else
	{
		cout<<-1;
	}


}

