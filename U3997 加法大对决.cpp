#include<iostream>
using namespace std;
int a[4000001]={0},b[4000001]={0},n,m,ans[4000001]={0};
void add()
{
	for(int i=1;i<=n+m;i++)
	{
		ans[i]+=a[i]+b[i];
		if(ans[i]>=10)
		{
			ans[i]-=10;
			ans[i+1]+=1;
		}
	}
	for(int i=1;i<=n+m;i++)
	{
		if(ans[i]>=10)
		{
			ans[i]-=10;
			ans[i+1]+=1;
		}
	}
}
int main()
{
	string s1,s2;
	cin>>s1>>s2;
	n=s1.size();
	m=s2.size();
	int k=1;
	for(int i=s1.size();i>=1;i--)
	{
		a[k]=s1[i-1]-48;
		k++;
	}
	
	k=1;
	for(int i=s2.size();i>=1;i--)
	{
		b[k]=s2[i-1]-48;
		k++;
	}
	add();
	
	bool v=0;
	/*for(int i=n+m;i>=1;i--)
	{
		if(ans[i]!=0)
		{
			cout<<ans[i];
			v=1;
		}else
		{
			if(!ans[i]&&!v)
			{
				continue;
			}else
			{
				cout<<0;
			}
		}
	}*/
	int kkk=0;
	for(int i=1;i<=6;i++)
	{
		kkk*=10;
		kkk+=ans[i];
	} 
	cout<<kkk%46640;
}
