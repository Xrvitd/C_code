#include<iostream>

#include<cmath>
using namespace std;
int a[10001]={0},n,m,f[10001][21];  //youcuo
void RMQ_ycl()
{
	for(int i=1;i<=n;i++)
	{
		f[i][0]=a[i];
	}
	for(int j=1;j<=20;j++)
	{
		for(int i=1;i<=n;i++)
		{
			if(i+(1<<j)-1<=n)
			{
				f[i][j]=max(f[i][j-1],f[i+(1<<j)][j-1]);

			}
		}
	} 
} 
int find_RMQ(int i,int j)
{
	int k=log(j-i+1)/log(2);
	return max(f[i][k],f[j-(1<<k)+1][k]);
} 
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	RMQ_ycl();
	cin>>m;
	int x,y;
	for(int i=1;i<=m;i++)
    {
    	cin>>x>>y;
    	cout<<find_RMQ(x,y)<<endl;
	} 
}
