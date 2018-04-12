#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
using namespace std;
int n;
int x=0,y=0,z=0,rxa,rxc,rya,ryc,rza,rzc,rp=2333333,m[21][21][50001],bh[21][21];
double ans;
struct zqm
{
	double x,y;
	int s,q,w;
}a[50001];
int main()
{
	cin>>n;
	cin>>rxa>>rxc>>rya>>ryc>>rza>>rzc;
	for(int i=1;i<=5;i++)
	{
		a[i].s=1;
	}
	for(int i=1;i<=n;i++)
	{
		x=(y*rxa+rxc)%rp;
		y=(z*rya+ryc)%rp;
		z=(x*rza+rzc)%rp;
	//	cout<<x<<" "<<y<< " "<<z<< " \n";
		double k=0;
		k=x%20+(double)(y%10)/10.0+(double)(z%10)/100.0;
		a[i].x=k;
		x=(y*rxa+rxc)%rp;
		y=(z*rya+ryc)%rp;
		z=(x*rza+rzc)%rp;
	//	cout<<x<<" "<<y<< " "<<z<< " \n";
		k=x%20+(double)(y%10)/10+(double)(z%10)/100;
		a[i].y=k;
		a[i].q=(int)a[i].x;
		a[i].w=(int)a[i].y;	
		bh[a[i].q][a[i].w]++;
		m[a[i].q][a[i].w][bh[a[i].q][a[i].w]]=i;
		//cout<<a[i].x<< " "<<a[i].y<<endl; 
	}
	/*for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			int e=a[i].q,r=a[i].w,t=a[j].q,y=a[j].w;
			if(e<t&&r<y)
			{
				ans+=a[j].x+a[j].y-a[i].x-a[i].y;
			}
			if(e>t&&r>y)
			{
				ans+=a[i].x+a[i].y-a[j].x-a[j].y;
			}
		}
	}*/
	for(int i=1;i<=20;i++)
	{
		for(int j=1;j<=20;j++)
		{
			for(int p=1;p<=bh[i][j];p++)
			for(int ii=1;ii<i;ii++)
			{
				for(int jj=1;jj<j;jj++)
				{
					for(int l=1;l<=bh[ii][jj];l++)
					{
						int z=m[i][j][p],c=m[ii][jj][l];
						ans+=a[z].x+a[z].y-a[c].x-a[c].y;
					}
				}
			}
		}
	}
	printf("%.5llf",ans/n);
}

