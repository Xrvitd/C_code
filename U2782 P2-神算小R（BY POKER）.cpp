#include<iostream>
using namespace std;
int n,m;
int a[1000000]={0},ans[21]={0};
int main()
{
	cin>>n;
	if(n%2!=0)
	{
		cout<<"NUMBER ERROR!!";
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		a[i]=i;
	}
	bool ll=0,k=0,kk=0;
	int h=0,t=n;
	while(!ll)
	{
		h++;
		if(a[h]==0)
		{
			break;
		}
		//cout<<h<<"   ";
		if(!k)
		{
			if(!kk)
			{
				
				ans[a[h]]=1;
				a[h]=0;
				kk=1;
			//	cout<<"+\n";
			}else
			{
				ans[a[h]]=2;
				a[h]=0;
				kk=0;
			//	cout<<"-\n";
			}
			k=1;
		}else
		{
			t++;
			a[t]=a[h];
			a[h]=0;
			k=0;
		//	cout<<"@\n";
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(ans[i]==1)
		{
			cout<<'+';
		}else
		{
			cout<<'-';
		}
	}
 } 
