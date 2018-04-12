#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int f[5001]={0},n,m,q,z,k=0;
bool v=0;
struct re
{
	int l;
	int s,t;
};
struct re d[5001];
struct rre
{
	double l;
	int s,t;
};
struct rre ans;
bool camp(struct re a,struct re b)
{
	if(a.l>b.l) return 1;
	if(a.l<b.l) return 0;
	if(a.l==b.l) 
	{
		if(a.s>b.s) return 1;
	}
	return 0;
}
int find(int x){
	if(f[x]==x)
		return x;
		f[x]=find(f[x]);
		return f[x];
}
int gcd(int a,int b)
{
     return b==0?a:gcd(b,a%b);
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>d[i].s>>d[i].t>>d[i].l;
	}
	cin>>q>>z;
	sort(d+1,d+m+1,camp);
	for(int i=1;i<=n;i++)
	{
		f[i]=i;
	}
	ans.l=2147483647;
	for(int i=1;i<=m;i++)
	{
		f[find(d[i].s)]=find(f[d[i].t]);
		if(find(q)==find(z))
		{
			v=1;
			ans.l=1;break; 
		}
		for(int j=i+1;j<=m;j++)
		{
			if(	f[find(d[j].s)]!=find(f[d[j].t]))
				f[find(d[j].s)]=find(f[d[j].t]);
				
			if(find(q)==find(z))
			{
				v=1;
				k++;
				int qw=d[i].l/d[j].l;
				if(d[i].l%d[j].l==0)
				{
				//if(qw<1) qw=1+(1-qw);
				ans.l=min(ans.l,(double)qw);
				}
				else
				{
					double ss;
					ss=(double) d[i].l/(double) d[j].l;
					if(ss<ans.l)
					{
						ans.l=ss;
						ans.s=d[i].l/gcd(d[i].l,d[j].l);
						ans.t=d[j].l/gcd(d[i].l,d[j].l);
					}
				}
				break;
			}
		
		}
		for(int i=1;i<=n;i++)
	    {
		f[i]=i;
	    }
	}
	if(v==0)
	{
		cout<<"IMPOSSIBLE";
	}else
	{if(ans.l-(int)ans.l==0)
		cout<<ans.l;
		else
		{
			cout<<ans.s<<"/"<<ans.t;
		}
	}
}
 
