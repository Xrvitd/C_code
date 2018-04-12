#include<stdio.h>
int n,m,a[10001],i,ans=0;
void dfs(int x,int sum)
{
	//printf("%d ",sum);
	if(x==4&&sum==m)
	{
		ans=1;
		return;
	}
	if(x==4) return;
	int j;
	for(j=1;j<=n;j++)
	{
		dfs(x+1,sum+a[j]);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	} 
	dfs(0,0);
	if(ans==1)
	{
		printf("yes");
	}else
	{
		printf("no");
	}
} 
