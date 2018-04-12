#include <stdio.h>
int w[105], val[105],i,j;
int dp[1005];
int max(int x,int y)
{
	if(y>x) return y;
	return x;
}
int main()
{
    int t, m, res=-1;
    scanf("%d%d",&t,&m);
    for( i=1; i<=m; i++)
    {
        scanf("%d%d",&w[i],&val[i]);
    }
    for(i=1; i<=m; i++) 
        for(j=t; j>=0; j--) 
        {
            if(j >= w[i])
                dp[j] = max(dp[j-w[i]]+val[i], dp[j]);
        }
    printf("%d",dp[t]);
    return 0;
}
