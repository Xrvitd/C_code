#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>

using namespace std;
int n,m,open,clos,p,s,t,x,y,z,i,j,k,ha,ti,p1=0,w[200001],w1[200001],qi[200001],d[200001],q[200001],v[200001],v1[200001],next[200001],next1[200001],h[200001],h1[200001],r[200001],nex[200001];
bool vv[200001]={0},fl[200001]={0},f[200001];

inline int get_nm()
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
/*void add1(int a,int b,int c)
{
	p1++;
	qi[p1]=a;
	v1[p1]=b;
    w1[p1]=c;
    next1[p1]=h[a];
    h1[a]=p1;
    nex[b]=p1;
    r[b]=p1;
}*/
void spfa()
{
	int i;
	p=0;
	memset(f,0,sizeof(f));
	memset(d,127,sizeof(d));
	ha=0;ti=1;
	q[1]=t;
	d[t]=0;
	f[t]=1;
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
				vv[v[p]]=1;
				d[v[p]]=w[p]+d[i];
				//cout<<"d "<<v[p]<<"="<<d[v[p]]<<endl;
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
void spfa1()
{
	int i;
	p=0;
	memset(f,0,sizeof(f));
	memset(d,127,sizeof(d));
	ha=0;ti=1;
	q[1]=t;
	d[t]=0;
	f[t]=1;
	while(ha<=ti)
	{
		ha++;
		i=q[ha];
		p=h[i];
		f[i]=0;
		while(p>0)
		{
			if(!fl[v[p]]&&w[p]+d[i]<d[v[p]])
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
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int q,ww;
		q=get_nm();
		ww=get_nm();
		add(ww,q,1); 
		//add1(q,w,1);
	}
	cin>>s>>t;
	spfa();
	vv[t]=1;
	/*for(int i=1;i<=n;i++)
	{
		cout<<vv[i]<<" ";
	}cout<<endl;*/
	for(int i=1;i<=n;i++)
	{
		if(!vv[i])
		{
		    p=h[i];
		    while(p)
		    {
		    	fl[v[p]]=1;
		    	p=next[p];
			}
		}
	}
	spfa1();
	/*for(int i=1;i<=n;i++)
	{
		cout<<d[i]<<" ";
	}cout<<endl;*/
    if(d[s]<=2000000000)
	cout<<d[s];
	else
	{
		cout<<-1;
	}
}
