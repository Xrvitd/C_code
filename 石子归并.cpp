#include<iostream>
#include<algorithm>
using namespace std;
int n,m=0,a[1000001]={0};
int k=0;
struct re 
{
	int s,x,y;
};
struct re b[100001];
bool camp(struct re aa,struct re bb)
{
	if(aa.s<bb.s)
	return 1;
	return 0;
}
int main() 
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			k++;
			b[k].x=i;
			b[k].y=j;
			b[k].s=a[i]+a[j];
		}
	}
	sort(b+1,b+1+k,camp);
	for(int i=1;i<=k;i++)
	{
		cout<<b[i].s<<" ";
	}
	for(int i=1;i<n;i++)
	{
		m+=a[i];
		m+=a[i+1];
		a[i+1]+=a[i];
	    //cout<<a[i]<<" ";
	}
	//cout<<m;
}
