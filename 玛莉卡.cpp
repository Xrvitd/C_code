#include<iostream>
#include<cstring>
using namespace std;
int ha,ti,next[1000001],st[1000001],h[1000001],la[1000001]={0},n,m,p,s,t,x,y,z,k,w[1000001],
d[1000001],q[10000001],v[10000001],nm=0,ans[10000001]={0};
bool f[1000001]={0},vv[1000001]={0};
void add(int a,int b,int c)
{
	p++;
	v[p]=b;
	st[p]=a;
	w[p]=c;
	next[p]=h[a];
	h[a]=p;
}
void spfa()
{
	int i;
	p=0;
	memset(f,0,sizeof(f));
	memset(d,127,sizeof(d));
	ha=0;ti=1;
	q[1]=1;d[1]=0;f[1]=1;
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
				la[v[p]]=p;
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
void spfa1(int qq)
{
	int i;
	p=0;
	memset(f,0,sizeof(f));
	memset(d,127,sizeof(d));
	ha=0;ti=1;
	q[1]=1;d[1]=0;f[1]=1;
	while(ha<=ti)
	{
		ha++;
		i=q[ha];
		p=h[i];
		f[i]=0;
		while(p>0)
		{
			if(w[p]+d[i]<d[v[p]]&&p!=qq&&p!=qq+1)
			{
				la[v[p]]=p;
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
	int kkk=s;
	while(kkk>1)
	{
		vv[la[kkk]]=1;
		kkk=st[la[kkk]];
	}
}
int main()
{
	cin>>n>>m;
	s=n;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y>>z;
		add(x,y,z);
		add(y,x,z);
	}
	spfa();
	//cout<<d[s];
	nm++;
	ans[nm]=d[s];
	int kkk=s;
	while(kkk>1)
	{
		vv[la[kkk]]=1;
		kkk=st[la[kkk]];
	}
	/*for(int i=1;i<=m*2;i++)
	{
		if(vv[i])
		{
			cout<<v[i]<<" ";
		}
	}*/
	for(int i=1;i<=m;i++)
	{
		//cout<<v[i*2-1]<<" ";
		if(vv[i*2-1]||vv[i*2])
		{
			spfa1(i*2-1);
		    nm++;
	        ans[nm]=d[s];
		} 
	}
	int anan=0;
	for(int i=1;i<=nm;i++)
	{
		//cout<<ans[i]<<" ";
		anan=max(anan,ans[i]);
	}
	cout<<anan;
}
