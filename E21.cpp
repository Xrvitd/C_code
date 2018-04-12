#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cstdlib>
#include<string>
#include<bitset>
#include<iomanip>
#include<deque>
#define INF 1000000000
#define fi first
#define se second
#define N 100005
#define P 1000000007
#define MP(x,y) make_pair(x,y)
using namespace std;
int nn,mm,kn,km,k;
float a[4][4],x[4],ans[4];
float ave[4];
void averageh(float* a,int m,int n,float* b)
{
	
	for(int i=0;i<m;i++)
	{
		float sum=0;
		for(int j=0;j<n;j++)
		{
			sum+=a[i*m+j];
		}
		b[i]=sum/n;
	}
}
void averagel(float* a,int m,int n,float* b)
{
	
	for(int i=0;i<n;i++)
	{
		float sum=0;
		for(int j=0;j<m;j++)
		{
			sum+=a[j*m+i];
		}
		b[i]=sum/n;
	}
}
void removeh(float* a,int m,int n,int k)
{
	for(int i=k;i<m-1;i++)
	{
		for(int j=0;j<n;j++)
		{
			a[i*m+j]=a[(i+1)*m+j];
		}
	}
	for(int j=0;j<n;j++)
    {
		a[(m-1)*m+j]=-1;
    }
    mm--;
}
void removel(float* a,int m,int n,int k)
{
	for(int i=k;i<n-1;i++)
	{
		for(int j=0;j<m;j++)
		{
			a[j*m+i-1]=a[j*m+i];
		}
	}
	for(int j=0;j<m;j++)
    {
		a[j*m+n-1]=-1;
    }
    nn--;
}
void cheng(float* a,float* x,float* c)
{
	for(int i=0;i<km;i++)
	{
		for(int j=0;j<kn;j++)
		{
			c[i]+=a[i*km+j]*x[j];
		} 
	}
	
}
int main()
{
	mm=4;nn=4;
	kn=4;km=4;
	cout<<"n=4  m=4";
	cout<<endl;
	for(int i=0;i<km;i++)
	{
		for(int j=0;j<kn;j++)
		{
			a[i][j]=i;
		}
	}
	
	for(int i=0;i<km;i++)
	{
		for(int j=0;j<kn;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	
	averageh((float*)a,4,4,ave);
	for(int i=0;i<km;i++)
	{
		cout<<ave[i]<<" ";
	} cout<<endl;cout<<endl;
	averagel((float*)a,4,4,ave);
	for(int i=0;i<kn;i++)
	{
		cout<<ave[i]<<" ";
	} cout<<endl;cout<<endl;
	removeh((float*)a,km,kn,2);
	for(int i=0;i<mm;i++)
	{
		for(int j=0;j<nn;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}cout<<endl;
	removel((float*)a,km,kn,2);
	for(int i=0;i<mm;i++)
	{
		for(int j=0;j<nn;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			a[i][j]=i;
		}
	}
	cout<<"a数组已重置，请输入x矩阵：";
	for(int i=0;i<kn;i++)
	{
		cin>>x[i];
	}
	cheng((float*)a,x,ans);
	for(int i=0;i<km;i++)
	{
		cout<<ans[i]<<" ";
	}
}

