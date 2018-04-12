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
int n,m,a[10][10];
int h=0,t=1,ans=0;
const int fx[5]={0,1,-1,0,0};
const int fy[5]={0,0,0,1,-1};
bool v[8][5]={0};
struct zqm 
{
	int m[10][10],s,x,y,f,l;
}q[100001];
void downl(int x,int y)
{
	int deep=0;
	for(int i=x-1;i>=1;i--)
	{
		if(!q[h].m[i][y-1])
		{
			deep++;
		}
		t++;
		q[t]=q[h];
		q[t].s++;
		q[t].m[i-deep][y-1]=q[h].m[i][y];
		for(int i=x;i<=7;i++)
		{
			q[t].m[i][y]=q[t].m[i+1][y];
			q[t].m[i+1][y]=0;
		}
	}
}
void downr(int x,int y)
{
	int deep=0;
	for(int i=x-1;i>=1;i--)
	{
		if(!q[h].m[i][y+1])
		{
			deep++;
		}
		t++;
		q[t]=q[h];
		q[t].s++;
		q[t].m[i-deep][y+1]=q[h].m[i][y];
		for(int i=x;i<=7;i++)
		{
			q[t].m[i][y]=q[t].m[i+1][y];
			q[t].m[i+1][y]=0;
		}
	}
}
void xc()
{
	memset(v,0,sizeof(v));
	for(int i=1;i<=7;i++)
	{
		for(int j=1;j<=5;j++)
		{
			if(!q[t].m[i][j]) 
			{
				for(int k=1;k<=4;k++)
				{
					if(q[t].m[i][j]==q[t].m[i+fx[k]][j+fy[k]]&&q[t].m[i+fx[k]*2][j+fy[k]*2])
					{
						v[i][j]=1;
						v[i+fx[k]][j+fy[k]]=1;
						v[i+fx[k]*2][j+fy[k]*2]=1;
					}
				}
			}
		}
	}
	for(int i=1;i<=7;i++)
	{
		for(int j=1;j<=5;j++)
		{
			if(v[i][j])
			{
				q[t].m[i][j]=0;
				int jj=j+1;
				while(q[t].m[i][jj])
				{
					q[t].m[i][jj-1]=q[t].m[i][jj];
					q[t].m[i][jj]=0;
					jj++;
				}
			}
		}
	}
} 
bool win()
{
	for(int i=1;i<=7;i++)
	{
		for(int j=1;j<=5;j++)
		{
			if(q[t].m[i][j]) return 0;
		}
	} 
	return 1;
}
int main()
{
	cin>>n;
	for(int i=1;i<=5;i++)
	{
		for(int j=1;j<=7;j++)
		{
			cin>>a[j][i];
			q[1].m[j][i]=a[j][i]; 
			if(a[j][i]==0)break;
		}
	} 
	for(int i=7;i>0;i--)
	{
		for(int j=1;j<=5;j++)
		{
			cout<<q[t].m[i][j]<<" " ;
	    }
	    cout<<endl;
	}
	bool back=0;
	q[1].l=0;
	int ss=0;
	while(h<=t&&!back)
	{
		h++;
		if(q[h].s>ss)
		break;
		for(int i=1;i<=7;i++)
		{
			for(int j=1;j<=5;j++)
			{
				if(q[h].m[i][j])
				{	
					if(q[h].m[i][j-1]&&j-1>0)
					{
						t++;
						q[t]=q[h];
						q[t].s++;
						q[t].m[i][j]=q[h].m[i][j-1];
						q[t].m[i][j-1]=q[h].m[i][j];
						xc();
						q[t].x=i;
						q[t].y=j;
						q[t].f=-1;
						q[t].l=h; 
						if(win()) {back=1;cout<<q[t].s;ans=t;ss=q[t].s;}
					}else
					{
						downl(i,j);
						xc();
						q[t].x=i;
						q[t].y=j;
						q[t].f=-1;
						q[t].l=h;
						if(win()) {back=1;cout<<q[t].s;ans=t;}
					}
					if(q[h].m[i][j+1]&&j+1<=5)
					{
						t++;
						q[t]=q[h];
						q[t].s++;
						q[t].m[i][j]=q[h].m[i][j+1];
						q[t].m[i][j+1]=q[h].m[i][j];
						xc();
						q[t].x=i;
						q[t].y=j;
						q[t].f=1;
						q[t].l=h;
						if(win()) {back=1;cout<<q[t].s;ans=t;}
					}else
					{
						downr(i,j);
						xc();
						q[t].x=i;
						q[t].y=j;
						q[t].f=1;
						q[t].l=h;
						if(win()) {back=1;cout<<q[t].s;ans=t;}
					}
				}
			}
		}
	}
	int i=0,g=t;
	while(i<=q[t].s)
	{
		i++;
		cout<<q[g].x<<" "<<q[g].y<<" "<<q[g].f<<"\n";
		g=q[g].l;
	}

}

