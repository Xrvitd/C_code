#include<stdio.h>
#include<math.h> 
int dp[501][501],a[501],i,j,n,m,ans;
int max(int x,int y)
{
	if(y>x) return y;
	return x;
}
int main()
{
	scanf("%d%d",&m,&n);
	for (i=1;i<=n;i++) scanf("%d",&a[i]);
	dp[0][0]=1;
	for (i=1;i<=n;i++){
		for (j=0;j<=m;j++){
			dp[i][j]=dp[i-1][j];
			if (j-a[i]>=0) dp[i][j]=max(dp[i][j],dp[i-1][j-a[i]]);
		}
	}
	for (i=m;i>=0;i--){
		if (dp[n][i]==1) break;
	}
	printf("%d\n",m-i);
	return 0;
}
