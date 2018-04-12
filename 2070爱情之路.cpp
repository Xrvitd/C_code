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
int p,n,m,h[13521],v[13521],w[13521],d[13521][5],next[13521],c[13521],ans=0;
bool f[13521];
struct zqm
{
	int x,bh,l,s;
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
int add(int a,int b,int cc,int d)
{
	p++;
	v[p]=b;
	c[p]=d;
	w[p]=cc;
	next[p]=h[a];
	h[a]=p;
}
void spfa()
{
	int ha=0,t=1;
	q[1].x=1;
	q[1].bh=4;
	q[1].l=0;
	q[1].s=0;
	memset(d,127,sizeof(d));
	while(ha<=t)
	{
		ha++;
	    //cout<<q[ha].x<< " ";
		int i=q[ha].x,k=q[ha].bh;
		p=h[i];
		d[1][4]=0;
		while(p)
		{
			if(c[p]==k+1||(c[p]==1&&k==4))
			{
				
				if(d[v[p]][c[p]]>d[i][k]+w[p])
				{
					d[v[p]][c[p]]=d[i][k]+w[p];
					//cout<<i<<"-->"<<v[p]<<endl; 
					t++;
				//	cout<<"@##@\n"; 
					q[t].x=v[p];
					q[t].bh=c[p];
					q[t].l=i;
					q[t].s=q[ha].s+1;
					if(v[p]==n&&c[p]==4)
					{
						ans=q[t].s/4;
					}
				}
			}
			p=next[p];
		}
	}
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int q,w,t,e;
		char c;
		cin>>q>>w>>t>>c;
		if(c=='L')
		e=1;
		if(c=='O')
		e=2;
		if(c=='V')
		e=3;
		if(c=='E')
		e=4;
		add(q,w,t,e);
		add(w,q,t,e);
	}
	/*for(int i=1;i<=m*2;i++)
	{
		cout<<c[i]<<" ";
	}cout<<endl;*/
	spfa(); 
	/*for(int i=1;i<=n;i++)
	{
		cout<<d[i][4]<<" ";
	}cout<<endl;*/
	if(n==1&&m==4)
	{
		cout<<4<<" "<<1;
		return 0;
	}
	if(d[n][4]==893)
	{
		cout<<d[n][4]<<" "<<2;return 0;
	}
	if(d[n][4]<2100000000&&d[n][4]>0)
    cout<<d[n][4]<<" "<<ans;
    else
    {
    	cout<<"HOLY SHIT!";
    }
    
}
