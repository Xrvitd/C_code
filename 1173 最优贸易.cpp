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
int n,m,c[2000001],z[2000001],h[5000001],ans=0,zz[5000001];
bool f[2000001];
struct zqm
{
	int v,next,w;
}q[2000001];

int p=0;
struct re
{
	int x,y,e;
}b[2000001];
int qu[1000001];
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
	z[1]=c[1];
	qu[1]=1;
	f[1]=1;
	
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
		    
		    
		    	if(z[x]>z[i]||z[x]>c[i])
		    	{
		    		z[x]=min(z[i],c[i]);
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
	qu[1]=n;
	zz[n]=c[n];
	f[n]=1;

	while(ha<=ti)
	{
		
		ha++;
		int i=qu[ha];
		f[i]=0;
		p=h[qu[ha]];
		while(p)
		{
		    int x=q[p].v;  
		    	if(zz[x]<zz[i]||z[x]<c[i])
		    	{
		    		zz[x]=max(zz[i],c[i]);
		    		ans=max(ans,zz[x]-z[x]);
		    		if(!f[x])
		    		{
		    			ti++;
		    		f[x]=1;
		    		
		    		qu[ti]=x;
		    		
		    		}
		    	}
		    
			p=q[p].next;
		}
	}	
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		c[i]=get_num();
	}
	memset(z,127,sizeof(z));
	int kkk=0;
	for(int i=1;i<=m;i++)
	{
	    b[i].x=get_num();b[i].y=get_num();b[i].e=get_num();
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
   // memset(q,0,sizeof(q));
    memset(f,0,sizeof(f));
    memset(h,0,sizeof(h));
    memset(qu,0,sizeof(qu));
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
	/*for(int i=1;i<=n;i++)
	{
		cout<<z[i]<<" ";
	}cout<<endl;
	for(int i=1;i<=n;i++)
	{
		cout<<zz[i]<<" ";
	}cout<<endl;*/
	for(int i=1;i<=n;i++)
	{
		//cout<<vv[i]<<" ";
	}
	if(ans<0)
	{
		cout<<0;
		return 0;
	}
	cout<<ans;
}

