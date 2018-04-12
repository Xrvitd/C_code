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
const int fx[4]={1,-1,0,0};
const int fy[4]={0,0,1,-1};
long long n,m,k,ans=2147483647;
int d[31][31][4][4];
int ma[31][31]; 
long long dis[31][31][4];
bool v[31][31],f[31][31][4];
struct zqm
{
	int x,y,s,lf;
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
bool cj(int x,int y)
{
	if(x<=0||y<=0||x>n||y>m)
	{
		return 0;
	}
	return 1;
}
int find(int x,int y,int sx,int sy,int w,int e)
{
	if(x==w&&y==e)return 0; 
	int ha=0,ti=1;
	q[1].x=x;
	q[1].y=y;
	q[1].s=0;
	memset(v,0,sizeof(v));
	v[x][y]=1;
	v[sx][sy]=1;
	while(ha<=ti)
	{
		ha++;
		for(int i=0;i<=3;i++)
		{
			int tx=q[ha].x+fx[i],ty=q[ha].y+fy[i];
			if(cj(tx,ty)&&!v[tx][ty]&&ma[tx][ty])
			{
				v[tx][ty]=1;
				ti++;
				q[ti].x=tx;
				q[ti].y=ty;
				q[ti].s=q[ha].s+1;
				if(tx==w&&ty==e)
				{
					return q[ti].s;
				}
			}
		}
	}
	return 2147483600;
}
int bfs(int x,int y,int st,int t)
{
	memset(q,0,sizeof(q));
	int ha=0,ti=1;
	q[1].x=x+fx[st];
	q[1].y=y+fy[st];
	q[1].s=0;
	memset(v,0,sizeof(v));
	v[q[1].x][q[1].y]=1;
	v[x][y]=1;
	while(ha<=ti)
	{
		ha++;
		//cout<<q[ha].x<< " "<<q[ha].y<<endl;
		for(int i=0;i<=3;i++)
		{
			int tx=q[ha].x+fx[i],ty=q[ha].y+fy[i];
			if(cj(tx,ty)&&!v[tx][ty]&&ma[tx][ty])
			{
				v[tx][ty]=1;
				ti++;
				q[ti].x=tx;
				q[ti].y=ty;
				q[ti].s=q[ha].s+1;
				if(tx==x+fx[t]&&ty==y+fy[t])
				{
					return q[ti].s;
				}
			}
		}
	}
	return 2147483640;
}
int spfa(int x,int y,int fa,int fix,int fiy)
{
//	  3 4  1  2 2
	memset(dis,127,sizeof(dis));memset(f,0,sizeof(f));
	int ha=0,ti=1;
	q[1].x=x;q[1].y=y;
    q[1].lf=fa;
    f[x][y][fa]=1;
    dis[x][y][fa]=0;
	while(ha<=ti)
	{
		ha++;
		//cout<<q[ha].x<<" "<<q[ha].y<<endl; 
		f[q[ha].x][q[ha].y][q[ha].lf]=0;
		for(int i=0;i<=3;i++)
	    {
			int tx=q[ha].x+fx[i],ty=q[ha].y+fy[i];
			int fan;
			if(i==0) fan=1;
			if(i==1) fan=0;
			if(i==2) fan=3;
			if(i==3) fan=2;
			if(cj(tx,ty)&&ma[tx][ty]&&dis[tx][ty][fan]>dis[q[ha].x][q[ha].y][q[ha].lf]+d[q[ha].x][q[ha].y][q[ha].lf][i])
			{
				//cout<<tx<<" "<<ty<<endl;
				/*if(tx==fix&&ty==fiy)
				{
					cout<<q[ha].x<<" " <<q[ha].y<<"  "<<q[ha].lf<<endl;
				} */
				dis[tx][ty][fan]=dis[q[ha].x][q[ha].y][q[ha].lf]+d[q[ha].x][q[ha].y][q[ha].lf][i];
				if(!f[tx][ty][fan])
				{
					f[tx][ty][fan]=1;
					ti++;
					q[ti].x=tx;
					q[ti].y=ty;
					q[ti].lf=fan;
				}
			}
		
	    }	
	    //cout<<endl;
	}
	long long anss=2147483647;
	for(int i=0;i<=3;i++)
	{
		anss=min(anss,dis[fix][fiy][i]);
	}
	return anss;
}
int main()
{
	
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>ma[i][j];
		}
	}
	memset(d,127,sizeof(d));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(!ma[i][j])continue;
			for(int l=0;l<=3;l++)
			{
				d[i][j][l][l]=1;
			}
			for(int l=0;l<=3;l++)
			{
				if(!cj(i+fx[l],j+fy[l])||!ma[i+fx[l]][j+fy[l]])continue;
				for(int o=0;o<=3;o++)
				{
			        if(!cj(i+fx[o],j+fy[o])||!ma[i+fx[o]][j+fy[o]]) continue;
					if(o==l)continue;
					d[i][j][l][o]=bfs(i,j,l,o)+1;
				}
			}
		}
	}
	//cout<<d[1][28][2][3]<<endl;
	//cout<<spfa(3,4,3,2,2);
	for(int i=1;i<=k;i++)
	{
		ans=2147483647;
		int kx,ky,sx,sy,mx,my;
		cin>>kx>>ky>>sx>>sy>>mx>>my;
		if(sx==mx&&sy==my)
		{
			cout<<0<<endl;
			continue;
		}
		for(int i=0;i<=3;i++)
		{
			int tx=sx+fx[i],ty=sy+fy[i];
			long long ll=0;
			if(!cj(tx,ty)||!ma[tx][ty])continue;
			ll+=find(kx,ky,sx,sy,tx,ty);
			//cout<<ll<<" ";
			ll+=spfa(sx,sy,i,mx,my);
			//cout<<ll<<" \n";
			if(ll<2100000000)
			ans=min(ll,ans);			
		}
		if(ans>2100000000)
		{
			cout<<"-1\n";
		}else
		cout<<ans<<endl;
	} 
}

