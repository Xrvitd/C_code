#include<iostream>
using namespace std;
int n,m,f[51][6]={0};
long long ans=0;
void dfs(int s,int k)
{
	if(s>n||k>=m)
	{
		return;
	}
	
	if(k==m-1)
	{
		dfs(s+1,0);
		return;
	}
	ans++;
	dfs(s+1,k);
	dfs(s+1,k+1);
}
int main()
{
	cin>>n>>m;
	dfs(1,0);
	dfs(1,1);
	cout<<ans;
}
