#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n=0,m;
int a[10000001];
string s;
int ans[10000001],k=0;
bool c()
{
	int q4=0;
	for(int i=1;i<=4;i++)
	{
		q4*=10;
		q4+=a[i];
	}int y=q4%73;
	//k++;
//	ans[k]=q4/73;
int t;
	for(int i=5;i<=s.size()-3;i+=4)
	{
		y*=10;
		y+=a[i];
		y*=10;
		y+=a[i+1];
		y*=10;
		y+=a[i+2];
		y*=10;
		y+=a[i+3];
		y=y%73;
		t=i;
	}
	int x=0;
	for(int i=t+1;i<=s.size();i++)
	{
		y*=10;
		y+=a[i];
	}
	y=y%73;
	if(y==0) return 1;
	return 0;
}
bool d()
{
	int q4=0;
	for(int i=1;i<=4;i++)
	{
		q4*=10;
		q4+=a[i];
	}int y=q4%137;
	//k++;
//	ans[k]=q4/73;
	for(int i=5;i<=s.size();i++)
	{
		y*=10;
		y+=a[i];
		y=y%137;
	}
	if(y==0) return 1;
	return 0;
}
int main()
{
	while(cin>>s)
	{
		n++;
		cout<<"Case #"<<n<<": ";
		for(int i=1;i<=s.size();i++)
		{
			a[i]=s[i-1]-'0';
		}
		if(c()&&d())
		{
			cout<<"YES\n";
		}else
		{
			cout<<"NO\n";
		}
	} 

}

