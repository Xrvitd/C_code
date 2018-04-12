#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,a[1000001];
bool vv=0;
struct zqm
{
	int l,r,s,m;
}t[25000000];
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
void build(int x,int l,int r)
{
	t[x].l=l;
	t[x].r=r;
	if(l==r)
	{
		t[x].s=a[l];
		return ;
	}
	int m=(l+r)>>1;
	build(2*x,l,m);
	build(x*2+1,m+1,r);
	t[x].s=min(t[x*2].s,t[x*2+1].s);
}
void bg(int x,int l,int r,int k)
{
	int q=t[x].l,w=t[x].r;
	if(q==l&&w==r)
	{
		t[x].m+=k;
		if(t[x].m>t[x].s)
		{
			vv=1;
		}
		return;
	}
	int m=(q+w)>>1;
	if(l>m)
	{
		bg(x*2+1,l,r,k);
	}else
	if(r<=m)
	{
		bg(2*x,l,r,k);
	}else
	{
		bg(2*x,l,m,k);
		bg(2*x+1,m+1,r,k);
	}
	t[x].s=min(t[x*2].s-t[x*2].m,t[2*x+1].s-t[2*x+1].m);
	if(t[x].s<0)vv=1;
	return;
	
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		a[i]=get_num();
	}
	t[1].l=1;
	t[1].r=n;
	build(1,1,n);
	//for(int i=1;i<=n*n;i++)
//	{
//		cout<<t[i].s<<endl;
//	}
	for(int i=1;i<=m;i++)
	{
		int q,w,e;
		q=get_num();
		w=get_num();
		e=get_num();
		bg(1,w,e,q);
		if(vv)
		{
			cout<<-1<<endl<<i;
			return 0;
		}
	}
	if(!vv)
	cout<<0;
 } 
