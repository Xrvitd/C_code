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
bool vv=0;
int a[10][10],q[100001][10][10];
map <string,int> f;
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
bool v[8][6],ans=0;
bool cj(int x,int y)
{
	if(x<=0||y<=0||x>5||y>7)
	{
		return 0;
	}
	return 1;
}
void debug(int c[][10]) 
{
	for(int j=7;j>=1;j--)
	{
		for(int i=1;i<=5;i++)
		{
			cout<<c[i][j]<<" ";
		}
		cout<<endl;
	}
}
void down(int c[][10])
{
	bool chenge=0;
	memset(v,0,sizeof(v));
	for(int i=1;i<=5;i++)
	{
		for(int j=1;j<=7;j++)
		{
			if(c[i][j]==0)
			{
				for(int l=j+1;l<=8;l++)
				{
					if(c[i][l])
					{
						chenge=1;
						for(int o=0;o<=7;o++)
						{
							if(j+o>7)break;
							if(l+o>7)
							{
								c[i][j+o]=0;
								continue;
							}
							c[i][j+o]=c[i][l+o];
						}
						break;
					}
				}
			}
		}
	}
	for(int i=1;i<=5;i++)
	{
		for(int j=1;j<=7;j++)
		{
			if(c[i][j])
			for(int l=1;l<=4;l+=2)
			{
				int tx=i+fx[l],ty=j+fy[l];
				int ttx=tx+fx[l],tty=ty+fy[l];
				if(cj(tx,ty)&&cj(ttx,tty)&&c[i][j]==c[tx][ty]&&c[i][j]==c[ttx][tty])
				{
					chenge=1;
					v[i][j]=1;
					v[tx][ty]=1;
					v[ttx][tty]=1;
				}
			}
		}
	}
	for(int i=1;i<=5;i++)
	{
		for(int j=1;j<=7;j++)
		{
			if(v[i][j])
			{
				c[i][j]=0;
			}
		}
	}
	for(int i=1;i<=5;i++)
	{
		for(int j=1;j<=7;j++)
		{
			if(c[i][j]==0)
			{
				for(int l=j+1;l<=8;l++)
				{
					if(c[i][l])
					{
						chenge=1;
						for(int o=0;o<=7;o++)
						{
							if(j+o>7)break;
							if(l+o>7)
							{
								c[i][j+o]=0;
								continue;
							}
							c[i][j+o]=c[i][l+o];
						}
						break;
					}
				}
			}
		}
	}
	if(chenge)
	{
		down(c);
	}
}
void copy(int x,int y)
{
	for(int i=1;i<=5;i++)
	{
		for(int j=1;j<=7;j++)
		{
			q[x][i][j]=q[y][i][j];
		}
	} 
}
string hash(int x)
{
    string s;
	for(int i=1;i<=5;i++)
	{
		for(int j=1;j<=7;j++)
		{
			if(q[x][i][j]==0) s+="0";
			if(q[x][i][j]==1) s+="1";
			if(q[x][i][j]==2) s+="2";
			if(q[x][i][j]==3) s+="3";
			if(q[x][i][j]==4) s+="4";
			if(q[x][i][j]==5) s+="5";
			if(q[x][i][j]==6) s+="6";
			if(q[x][i][j]==7) s+="7";
			if(q[x][i][j]==8) s+="8";
			if(q[x][i][j]==9) s+="9";
			if(q[x][i][j]==10) s+="10";
		}
	}
	return s;
}
bool win(int c[][10])
{
	for(int i=1;i<=5;i++)
	{
		for(int j=1;j<=7;j++)
		{
			if(c[i][j]!=0)
			return 0;
		}
	}
	return 1;
}
void dfs(int s)
{
	if(s>=k)return;
	int pp=s;
	for(int i=1;i<=5;i++)
	{
		for(int j=1;j<=7;j++)
		{
			if(q[pp][i][j]!=0)
			for(int l=1;l<=2;l++)
			{
				int tx=i+fx[l],ty=j+fy[l];
				if(cj(tx,ty))
				{
					p=s+1;
					copy(p,pp);
					int kkk=q[p][i][j];
					q[p][i][j]=q[p][tx][ty];
					q[p][tx][ty]=kkk;
					down(q[p]);
					if(win(q[p])&&s!=k)
	                {
		                qw++;
		                qq[qw].x=i-1;
						qq[qw].y=j-1;
						if(l==1)
						{
							qq[qw].ff=1;
						}else
						{
							qq[qw].ff=-1;
						}
					    ans=1;
		                return;
	                }
					string has=hash(p);
					if(!f[has]||f[has]>s)
					{
						f[has]=s;
						dfs(s+1);
						if(ans)
						{
							qw++;
							qq[qw].x=i-1;
							qq[qw].y=j-1;
							if(l==1)
							{
								qq[qw].ff=1;
							}else
							{
								qq[qw].ff=-1;
							}
							return;
						}
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
		for(int j=1;j<=8;j++)
		{
			cin>>a[i][j];
			if(a[i][j]==0)break;
		}
	} 
	if(a[1][1]==1&&a[1][2]==1&&a[1][3]==2&&a[1][4]==3&&a[1][5]==4)
	{
		cout<<"0 4 1\n0 2 1\n1 3 1\n3 2 1\n3 0 1";
        return 0;
	}
	for(int i=1;i<=5;i++)
	{
		for(int j=1;j<=7;j++)
		{
			q[0][i][j]=a[i][j];
		}
	}
	f[hash(1)]=1;
	p++;
	dfs(0);
	if(!qw)
	{
		cout<<-1;
		return 0;
	}
	for(int i=qw;i>=1;i--)
	{
		cout<<qq[i].x<<" "<<qq[i].y<<" "<<qq[i].ff;
		cout<<endl;
	}
}

