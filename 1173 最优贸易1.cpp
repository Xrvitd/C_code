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
int n,m,c[1000001],z[1000001],h[1000001],ans=0,zz[1000001];
bool f[1000001],vv[1000001];
struct zqm
{
	int v,next,w;
}q[1000001];

int p=0;
struct re
{
	int x,y,e;
}b[1000001];
void add(int a,int b)
{
	p++;
	q[p].v=b;
	q[p].next=h[a];
	h[a]=p;
}
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
void spfa()
{
	int ha=0,ti=1;
	int qu[100001];
	qu[1]=1;
	f[1]=1;
	z[1]=c[1];
	vv[1]=1;
	while(ha<=ti)
	{
		
		ha++;
		//cout<<qu[ha]<< " :"; 
		int i=qu[ha];
		f[i]=0;
		p=h[qu[ha]];
		while(p)
		{
		    int x=q[p].v;
		    //cout<<x<< " ";
		    
		    	if(z[x]>z[i]||z[x]>c[x])
		    	{
		    		z[x]=min(z[i],c[x]);
		    		if(!f[x])
		    		{
		    			ti++;
		    		f[x]=1;
		    		qu[ti]=x;
		    		}
		    		
		    	}
			p=q[p].next;
		}
		//cout<<endl;
	}	
}
void spfaa()
{
	int ha=0,ti=1;
	int qu[100001];
	qu[1]=n;
	f[n]=1;
	zz[n]=c[n];
	vv[n]=1;
	while(ha<=ti)
	{
		
		ha++;
		int i=qu[ha];
		f[i]=0;
		p=h[qu[ha]];
		while(p)
		{
		    int x=q[p].v;
		    //cout<<x<< " ";
		    
		    	if(zz[x]<zz[i]||zz[x]<c[x])
		    	{
		    		zz[x]=max(zz[i],c[x]);
		    		if(!f[x])
		    		{
		    			ti++;
		    			f[x]=1;
		    			qu[ti]=x;
		    		}
		    	}
			p=q[p].next;
		}
		//cout<<endl;
	}	
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		//z[i]=c[i];
		//zz[i]=c[i];
	}
	memset(z,127,sizeof(z));
	int kkk=0;
	for(int i=1;i<=m;i++)
	{
		cin>>b[i].x>>b[i].y>>b[i].e;
		if(b[i].e==1)
		{
			kkk++;
			add(b[i].x,b[i].y);
		}else
		{
			kkk++;
			kkk++;
			add(b[i].x,b[i].y);
			add(b[i].y,b[i].x);
		}
	}
	
	spfa();
	
    memset(q,0,sizeof(q));
    memset(f,0,sizeof(f));
    memset(vv,0,sizeof(vv));
    memset(h,0,sizeof(h));
    for(int i=1;i<=m;i++)
	{
		if(b[i].e==1)
		{
			add(b[i].y,b[i].x);
		}else
		{
			add(b[i].x,b[i].y);
			add(b[i].y,b[i].x);
		}
	}
	spfaa();
	for(int i=1;i<=n;i++)
	{
		cout<<z[i]<<" ";
	}cout<<endl;
	for(int i=1;i<=n;i++)
	{
		cout<<zz[i]<<" ";
	}cout<<endl;
	for(int i=1;i<=n;i++)
	{
		ans=max(ans,zz[i]-z[i]);
	}
	cout<<ans;
}
