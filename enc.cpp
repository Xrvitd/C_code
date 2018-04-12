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
#define debug(x) cerr<<#x<<"="<<x<<endl
using namespace std;
int n;
string m,s,c; 
int a[200]={0},f[200]={0};
int main()
{
	cin>>m>>s>>c;
	for(int i=0;i<m.size();i++)
	{
		int k=m[i];
		if(a[k]==0)
		{
			a[k]=(int) s[i];
			if(f[k]==0)
			{
			    f[(int)s[i]]=k;
			}else
			{
				if(f[k]!=k)
				{
					cout<<"ERROR";
				return 0;
				}
			}
			
		}else
		{
			if(a[k]!=(int) s[i])
			{
				cout<<"ERROR";
				return 0;
			}
		}
	}
	for(int i=0;i<c.size();i++)
	{
		int k=c[i];
		if(f[k]==0)
		{
			cout<<"ERROR";
				return 0;
		}
	} 
	for(int i=0;i<c.size();i++)
	{
		int k=c[i];
		cout<<(char) f[k];
	}
}

