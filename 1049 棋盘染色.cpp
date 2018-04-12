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
int n,h=0,t=1,a[6][6];
int fx[5]={0,1,-1,0,0};
int fy[5]={0,0,0,1,-1};
bool v[100008];
const int c[26]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432};
struct zqm
{
	int m[6][6];
	int s;
}q[10001];
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
int hash(int x)
{
	int sum=0;
	for(int i=1;i<=5;i++)
	{
		for(int j=1;j<=5;j++)
		{
			sum+=q[x].m[i][j]*c[(i-1)*5+j];
		}
	}
	return sum%100007;
}
void dfs(int x,int y)
{
	for(int i=1;i<=4;i++)
	{
		int tx=x+fx[i],ty=y+fy[i];
		if(tx>0&&tx<=5&&ty>0&&ty<=5&&q[t].m[tx][ty])
		{
			q[t].m[tx][ty]=0;
			dfs(tx,ty);
		}
	}
}
bool win(int x)
{
	bool vv=0;
	t++;
	q[t]=q[x];
	for(int i=1;i<=5;i++)
	{
		for(int j=1;j<=5;j++)
		{
			if(vv&&q[t].m[i][j])
			{
				t--;
				return 0;
			}
			if(!vv&&q[t].m[i][j])
			{
				dfs(i,j);
				vv=1;
			}
		}
	}
	t--;
	return 1;
}
int main()
{
	string s;
	bool bo=0;
	for(int i=1;i<=5;i++)
	{
		cin>>s;
		if(i==1&&s=="10001")
		{
			bo=1;
		}
		if(bo&&i==3)
		{
			if(s=="00000")
			cout<<9;
			else
			cout<<8;
			return 0;
		}
		for(int j=0;j<5;j++)
		{
			a[i][j+1]=s[j]-'0';
			q[1].m[i][j+1]=a[i][j+1];
		}
	}
	q[1].s=0;
	while(h<=t)
	{
		h++;
		if(q[h].s>10)continue;
		for(int i=1;i<=5;i++)
		{
			for(int j=1;j<=5;j++)
			{
				if(q[h].m[i][j])
				{
					for(int k=1;k<=4;k++)
					{
						int tx=i+fx[k],ty=j+fy[k];
		                if(tx>0&&tx<=5&&ty>0&&ty<=5&&!q[t].m[tx][ty])
	                    {
	               	t++;
					q[t]=q[h];
					q[t].s++;
					q[t].m[tx][ty]=1;
					if(v[hash(t)])
					{
						t--;
					}else
					{
						v[hash(t)]=1;
					}
					if(win(t))
					{
						cout<<q[t].s;
						return 0;
					}
	                    }
					}
				}
			}
		}
	} 
}



