#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m;
char s[1548][1548];
void dfs(int k,int x,int y)
{
	if(k==1)
	{
		s[x][y]='/';
		s[x][y+1]='_';
		s[x][y+2]='_';
		s[x][y+3]='\\';
		s[x-1][y+1]='/';
		s[x-1][y+2]='\\';
		return;
	}
	dfs(k-1,x,y);
	dfs(k-1,x,y+(1<<k));
	dfs(k-1,x-(1<<k-1),y+(1<<k-1));
}
int main()
{
	memset(s,(' '),sizeof(s));
	cin>>n;
	dfs(n,1<<n,1);
    for(int i=1;i<=(1<<n);i++)
    {
    	for(int j=1;j<=(1<<n+1);j++)
    	cout<<s[i][j];
    	if(i!=(1<<n)) 
    	cout<<endl;
    }
}

