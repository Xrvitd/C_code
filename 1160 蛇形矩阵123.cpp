#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n+1][n+1];
	memset(a,0,sizeof(a));
	a[n][n]=n*n;
	int i=n,j=n,b;
	while(a[i][j]!=1)
	{
		while(a[i][j-1]==0&&j!=1)
		{
			b=a[i][j];
			j--;
			a[i][j]=b-1;
		}
		while(a[i-1][j]==0&&i!=1)
		{
			b=a[i][j];
			i--;a[i][j]=b-1;
		}
		while(a[i][j+1]==0&&j!=n)
		{
			b=a[i][j];j++;a[i][j]=b-1;
		}
		while(a[i+1][j]==0&&i!=n)
		{
			b=a[i][j];i++;a[i][j]=b-1;
		}
	}
	int sum=-1;
	for(int ii=1;ii<=n;ii++)
	{
		for(int jj=1;jj<=n;jj++)
		{
			cout<<a[ii][jj]<<" ";
		}cout<<endl;
		
	}
}
