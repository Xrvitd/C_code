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
#define MP(x,y) make_pair(x,y)
using namespace std;
const int fx[5]={0,1,-1,0,0};
const int fy[5]={0,0,0,1,-1};
int n,m,k,p=0,qw=0;
int a[10][10],q[10001][10][10];
struct zqm
{
	int x,y,ff;
}qq[10001];
long long ha[35]={0,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824,2147483648,4294967296,8589934592,17179869184};
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
bool v[8][6],f[1000008],ans=0;
bool cj(int x,int y)
{
	if(x<=0||y<=0||x>7||y>5)
	{
		return 0;
	}
	return 1;
}
void down(int c[][10])
{
	bool chenge=0;
	memset(v,0,sizeof(v));
	for(int i=1;i<=7;i++)
	{
		for(int j=1;j<=5;j++)
		{
			for(int l=1;l<=4;l++)
			{
				int tx=i+fx[l],ty=j+fy[l];
				int ttx=tx+fx[l],tty=ty+fy[l];
				if(cj(tx,ty)&&cj(ttx,tty)&&c[i][j]!=0&&c[i][j]==c[tx][ty]&&c[i][j]==c[ttx][tty])
				{
					//cout<<i<<" "<<j<<"   "<<tx<< " "<<ty<< "   "<<ttx<< " " <<tty<<endl;  
					chenge=1;
					v[i][j]=1;
					v[tx][ty]=1;
					v[ttx][tty]=1;
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
				//cout<<i<<" "<<j<<endl;
				c[i][j]=0;
			}
		}
	}
	for(int i=1;i<=7;i++)
	{
		for(int j=1;j<=5;j++)
		{
			if(c[i][j]==0&&c[i+1][j]!=0)
			{
				//cout<<i<<" "<<j<<endl;
				for(int l=i+1;l<=8;l++)
				{
					c[l-1][j]=c[l][j];
				}
			}
		}
	}
	if(chenge)
	{
		down(c);
	}
}
void debug(int c[][10]) 
{
	for(int i=7;i>=1;i--)
	{
		for(int j=1;j<=5;j++)
		{
			cout<<c[i][j]<<" ";
		}
		cout<<endl;
	}
}
void copy(int x,int y)
{
	for(int i=1;i<=7;i++)
	{
		for(int j=1;j<=5;j++)
		{
			q[x][i][j]=q[y][i][j];
		}
	} 
}
int hash(int x)
{
	long long s=0;
	for(int i=1;i<=7;i++)
	{
		for(int j=1;j<=5;j++)
		{
			s+=ha[((i-1)*5+j)-1]*q[x][i][j];
		}
	}
	long long kk=s%1000007;
	return (int) kk;
}
bool win(int c[][10])
{
	for(int i=1;i<=7;i++)
	{
		for(int j=1;j<=5;j++)
		{
			if(c[i][j]!=0)
			return 0;
		}
	}
	return 1;
}
void dfs(int s)
{
	if(s>k)return;
	//debug(q[p]);
	int pp=p;
	for(int i=1;i<=7;i++)
	{
		for(int j=1;j<=5;j++)
		{
			if(q[p][i][j]!=0)
			for(int l=3;l<=4;l++)
			{
				int tx=i+fx[l],ty=j+fy[l];
				if(cj(tx,ty))
				{
				//	cout<<i<<" "<<j<<"   "<<tx<< " "<<ty<<endl; 
					p++;
					copy(p,pp);
					int kkk=q[p][i][j];
					q[p][i][j]=q[p][tx][ty];
					q[p][tx][ty]=kkk;
					down(q[p]);
					if(win(q[p]))
	                {
		                cout<<"!!!!!!!!!";
		                ans=1;
		                return;
	                }
					int has=hash(p);
					if(!f[has])
					{
						f[has]=1;
						dfs(s+1);
						if(ans)
						{
							qw++;
							qq[qw].x=i-1;
							qq[qw].y=j-1;
							if(l==3)
							{
								qq[qw].ff=1;
							}else
							{
								qq[qw].ff=-1;
							}
							return;
						}
					}else
					{
						p--;
					}
				}
			}
		}
	}
}
int main()
{
	cin>>k;
	for(int i=1;i<=5;i++)
	{
		for(int j=1;j<=7;j++)
		{
			cin>>a[j][i];
			if(a[j][i]==0)break;
		}
	} 
	cout<<endl;
	down(a);
	for(int i=1;i<=7;i++)
	{
		for(int j=1;j<=5;j++)
		{
			q[1][i][j]=a[i][j];
		}
	}
	f[hash(1)]=1;
	p++;
	dfs(0);
	for(int i=qw;i>=1;i--)
	{
		cout<<qq[i].y<<" "<<qq[i].x<<" "<<qq[i].ff;
		cout<<endl;
	}
}

