#include<stdio.h>
#define maxn 10010
int n,m,ans=0;
int map[maxn][maxn];
int count[maxn]={0};
void topsort()
{
	int i,t;
	int stack[maxn],top=-1;
	for(i=1;i<=n;i++)
	    if(count[i]==0)
	    stack[++top]=i;
    while(top>-1)                       //栈非空进入循环
    {
    	t=stack[top--];
    	ans++;
    	for(i=1;i<=n;i++)
    	    if(map[t][i]&&--count[i]==0)//更新该点后继入度，若为0则入栈
    	    {
    	    	stack[++top]=i;
    	    }
    }
}

int main()
{
	scanf("%d%d",&n,&m);
	int i,a,b;
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&a,&b);
		map[a][b]=1;    
		count[b]++;	//求点的入度
	}
	topsort();
	if(ans<n)printf("T_T\n%d",n-ans);
	else printf("o(∩_∩)o");
	return 0;
}
