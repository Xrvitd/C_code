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
#define debug(x) cerr<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
int n,m,a[51][51],v[1001][1001],f[1001],ans=0;
int b[1001][1001];
int kk=1;
int fx[9]={0,1,1,1,-1,-1,-1,0,0};
int fy[9]={0,1,0,-1,1,0,-1,1,-1};
int find(int x)
{
	return x==f[x] ? x:f[x]=find(f[x]);
}
struct zqm
{
	int x,y,s;
	
}q[100001];
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
void dfs(int x,int y)
{
	for(int i=1;i<=8;i++)
	{
		int tx=x+fx[i],ty=y+fy[i];
		if(!v[tx][ty]&&a[tx][ty]&&tx>0&&tx<=n&&ty>0&&ty<=m)
		{
			v[tx][ty]=kk;
			dfs(tx,ty);
		}
	}
}
bool cmp(zqm a ,zqm b)
{
	return a.s<b.s;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			char c;
			cin>>c;
			if(c=='.')a[i][j]=0;
			else a[i][j]=1;
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(!v[i][j]&&a[i][j])
			{
				v[i][j]=kk;
				dfs(i,j);
				kk++; 
			}
			
		}
	} 
	kk--;
	cout<<kk;
	cout<<endl;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			for(int k=i-2;k>=1;k--)
			{
				for(int l=j-1;l<=j+1;l++)
				{
					if(b[v[i][j]][v[k][l]]==0)
					{
						b[v[i][j]][v[k][l]]=1000;
					}
					b[v[i][j]][v[k][l]]=min(b[v[i][j]][v[k][l]],i-k-1);
					b[v[k][l]][v[i][j]]=b[v[i][j]][v[k][l]];
				}
			}
			for(int k=i+2;k<=n;k++)
			{
				for(int l=j-1;l<=j+1;l++)
				{
					if(b[v[i][j]][v[k][l]]==0)
					{
						b[v[i][j]][v[k][l]]=1000;
					}
					b[v[i][j]][v[k][l]]=min(b[v[i][j]][v[k][l]],k-i-1);
					b[v[k][l]][v[i][j]]=b[v[i][j]][v[k][l]];
				}
			}
			for(int k=i-1;k<=i+1;k++)
			{
				for(int l=1;l<=j-2;l++)
				{
					if(b[v[i][j]][v[k][l]]==0)
					{
						b[v[i][j]][v[k][l]]=1000;
					}
					b[v[i][j]][v[k][l]]=min(b[v[i][j]][v[k][l]],j-l-1);
					b[v[k][l]][v[i][j]]=b[v[i][j]][v[k][l]];
				}
			}
			for(int k=i-1;k<=i+1;k++)
			{
				for(int l=j+2;l<=m;l++)
				{
					if(b[v[i][j]][v[k][l]]==0)
					{
						b[v[i][j]][v[k][l]]=1000;
					}
					b[v[i][j]][v[k][l]]=min(b[v[i][j]][v[k][l]],l-j-1);
					b[v[k][l]][v[i][j]]=b[v[i][j]][v[k][l]];
				}
			}
		}
	}
	int p=0;
	/*for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cout<<v[i][j]<< " ";
		}cout<<endl;
	}*/ 
	for(int i=1;i<=kk;i++)
	{
		for(int j=1;j<=kk;j++)
		{
			//cout<<b[i][j]<< " ";
			p++;
			q[p].x=i;
			q[p].y=j;
			q[p].s=b[i][j];
		}//cout<<endl;
	}
	sort(q+1,q+1+p,cmp);
	for(int i=1;i<=kk;i++)
	{
		f[i]=i;
	}
	int  pp=kk; 
    for(int i=1;i<=p;i++)
    {
    	if(q[i].s&&find(f[q[i].x])!=find(f[q[i].y]))
    	{
    		kk--;
    		ans+=q[i].s;
    		f[find(q[i].x)]=find(f[q[i].y]);
    		if(kk==1)
    		{
    			break;
    		}
    	}
    }
    cout<<pp-kk<< " "<<ans<<endl;
}

