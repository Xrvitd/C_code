#include<iostream>
using namespace std;
int n,m,x1,y1,k=0,bz=0;
bool a[2001][2001]={0};
struct re 
{
	int x,y;
} q[10001];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			char c;
			cin>>c;
			if(c=='#')
			{
				k++;
				if(k==1)
				{
					q[k].x=i;
					q[k].y=j;
					x1=i;
					y1=j;
				}
				if(k==2)
				{
					if(i==x1)
					{
						bz=1;
					}else
					{
						if(j==y1)
						{
							bz=2;
						}
						else
						{
							cout<<"NO";
							return 0;
						}
					}
				}
				if(k>2)
				{
					if(bz==1)
					{
						if(i!=x1)
						{
							cout<<"NO";
							return 0;
						}
					}else
					{
						if(j!=y1)
						{
							cout<<"NO";
							return 0;
						}
					}
				}
				a[i][j]=1;
			}
		}
	}
	cout<<"YES";
	return 0;
} 
