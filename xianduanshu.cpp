#include<cstdio>
#include<cstring>
using namespace std;
const int N=550000;
struct node
{
	int l,r;
	long long v;
}t[N];
int f[N];
long long d[N];
int n,q,c,a,b;
long long x;
void pushdown(int i)
{
	if(d[i]!=0)
	{
		t[i<<1].v+=d[i]*(t[i<<1].r-t[i<<1].l+1);
		d[i<<1]+=d[i];
		t[(i<<1)+1].v+=d[i]*(t[(i<<1)+1].r-t[(i<<1)+1].l+1);
		d[(i<<1)+1]+=d[i];
		d[i]=0;
	}
}
void build_tree(int i,int l,int r)
{
	t[i].l=l;
	t[i].r=r;
	t[i].v=0;
	if(l==r)
	{
		f[l]=i;
		return;
	}
	int mid=(l+r)>>1;
	build_tree(i<<1,l,mid);
	build_tree((i<<1)+1,mid+1,r);
}
void updata(int i)
{
	while(i>0)
	{
		//pushdown(i);
		t[i].v=t[i<<1].v+t[(i<<1)+1].v;
		i>>=1; 
	}
}
long long query(int i,int l,int r)
{
	if(l<=t[i].l&&t[i].r<=r)
		return t[i].v;
	pushdown(i);
	long long ans=0;
	i<<=1;
	if(l<=t[i].r)
		ans+=query(i,l,r);
	i++;
	if(r>=t[i].l)
		ans+=query(i,l,r);
	return ans;
}
void change(int i,int l,int r)
{
	if(l<=t[i].l&&t[i].r<=r)
	{
		d[i]+=x;
		t[i].v+=(t[i].r-t[i].l+1)*x;
		updata(i>>1);
		return;
	}
	pushdown(i);
	i<<=1;
	if(l<=t[i].r)
		change(i,l,r);
	i++;
	if(r>=t[i].l)
		change(i,l,r);
}
int main()
{
	scanf("%d",&n);
	build_tree(1,1,n);
	for(int i=1;i<=n;i++)
		scanf("%d",&t[f[i]].v);
	for(int i=1;i<=n;i++)
		updata(f[i]>>1);
	memset(d,0,sizeof(d));
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d%d",&c,&a,&b);
		if(c==2)
		{
			printf("%lld\n",query(1,a,b));
		}
		else
		{
			scanf("%lld",&x);
			change(1,a,b);
		}
	}
	return 0;
}
