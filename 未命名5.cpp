#include<iostream>
using namespace std;
int n,m,a[1001][1001],b[1001][1001],bq[1001]={0};
bool v[1001]={0},vv[1001]={0};
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int q,w;
		cin>>q>>w;
		if(!a[q][w])
		{
			bq[q]++;
		    b[q][bq[q]]=w;
		}
		a[q][w]=1;
	}
	/*for(int ii=1;ii<=n;ii++)
	{*/
		/*if(vv[2])
	{
		cout<<"T";
		continue;
	}*/
	cout<<b[2][1];
		int h=0,t=1;
	int q[100001]={0};
	q[1]=2;v[2]=1;
	while(h<=n)
	{
		h++;
		for(int i=1;i<=bq[i];i++)
		{
			int l=b[q[h]][i];
			cout<<l<<" ";
			if(v[l])
			{
				vv[l]=1; 
			}else
			{
				t++;
				v[l]=1;
				q[t]=l;
			}
		}
	}
	if(vv[2])
	{
		cout<<"T";
	}else
	{
		cout<<"F";
	}
	//}
	
} 
