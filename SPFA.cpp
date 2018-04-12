#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int n,m,open,clos,p,s,t,x,y,z,i,j,k,ha,ti,w[100001],d[100001],q[100001],v[100001],next[100001],h[100001];
bool f[100001];
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
void add(int a,int b,int c)
{
	p++;
	v[p]=b;
    w[p]=c;
    next[p]=h[a];
    h[a]=p;
}
void spfa()
{
	int i;
	p=0;
	for(int i=0;i<=n;i++) 
    {
    	d[i]=2147000000;
    }
	ha=0;ti=1;
	q[1]=0;
	d[0]=0;
	f[0]=1;
	while(ha<=ti)
	{
		ha++;
		i=q[ha];
		p=h[i];
		f[i]=0;
		while(p>0)
		{
			if(w[p]+d[i]<d[v[p]])
			{
				d[v[p]]=w[p]+d[i];
				if(!f[v[p]])
				{
					ti++;
					q[ti]=v[p];
					f[v[p]]=1;
				}
			}
			p=next[p];
		}
	}
}
int main()
{
	n=get_num();m=get_num();
	for(i=1;i<=m;i++)
	{
		x=get_num();y=get_num();z=get_num();
		if(x==y)
		{
			add(0,x,z);
		} 
		add(x,y,z);
	}
	spfa();
	int ans=0;
	for(int i=1;i<=n;i++)
    {
    	ans=max(ans,d[i]);
    }
	printf("%d",ans);
	
}
