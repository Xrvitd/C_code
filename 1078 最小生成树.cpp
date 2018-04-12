#include<iostream>
#include<algorithm>
using namespace std;
int n,m,f[10001]={0};
bool v[1001]={0};
struct re 
{
	int x,y,l;
};
struct re a[1001101];
bool camp(struct re a,struct re b)
{
	if(a.l>=b.l)return 0;
	return 1;
}
int find(int x)
{
	if(f[x]==x) return x;
	f[x]=find(f[x]);
	return f[x];
}
int main()
{
	cin>>n>>m;
	int k=m;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i].x>>a[i].y>>a[i].l; 
	}
	sort(a,a+k+1,camp);
	for(int i=1;i<=n;i++)
	{
		f[i]=i;
	}
	int ans=0,b=0;
	for(int i=1;i<k;i++)
	{
		if(find(a[i].x)!=find(a[i].y))
		{
			f[find(a[i].x)]=find(f[a[i].y]);
			ans+=a[i].l;
			b++;
			//cout<<ans<<" ";
			v[a[i].x]=1;
			v[a[i].y]=1;
			//cout<<a[i].x<<" "<<a[i].y<<endl; 
		}
		if(b>=n-1)
		{
			bool vv=1;
		for(int j=1;j<=n;j++)
		{
			if(!v[j])
			{
				vv=0;
				break;
			}
		}
		if(vv)
		{
			cout<<ans;
			return 0;
		}
		}
		
	}
}
