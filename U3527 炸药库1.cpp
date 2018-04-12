#include<iostream>
using namespace std;
int n,m,f[51][6]={0},ans=0;
int main()
{
	cin>>n>>m;
	dfs(0);
	cout<<ans;
} 
