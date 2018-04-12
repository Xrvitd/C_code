#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
long long  p,q,x,y,z,t,n,m,kk,f[1001],d[1001];bool v=1;
inline int get_num()
{	
int num = 0;
char c;
bool flag = false;
while ((c = getchar()) == ' ' || c == '\n' || c == '\r');	
if (c == '-') flag = true;	
else num = c - '0';	
while (isdigit(c = getchar()))		
num = num * 10 + c - '0';
return (flag ? -1 : 1) * num;
}
long long  find(long long  x)
{
	if(f[x]==x) return x;
	long long  te=find(f[x]);
	d[x]=d[x]+d[f[x]];
	f[x]=te;
	return f[x];
}
int main()
{
	cin>>t;
	
    for(long long  gg=1;gg<=t;gg++)
	{
	    n=get_num();
	    m=get_num();
		v=1;
		memset(d,0,sizeof(d)); 
		for(long long  i=0;i<=n;i++)
		{
			f[i]=i;
		}
		for(long long  i=1;i<=m;i++)
		{
		
			cin>>x>>y>>z;
			
			p=find(x);
			q=find(y);
			if(q!=p)
			{
				f[p]=q;
				d[p]=d[y]-d[x]+z;
			}else
			{
				if(d[x]-d[y]!=z)
				{
					v=0;
				
				}    
			}
			
		}
		if(!v)
		{
			printf("Bessie is blind.\n");
		}else   
		{
			printf("Bessie's eyes are good\n");
		}  
	}
	return 0;
}

