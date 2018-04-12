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
int n,m,p,h[1001],s,t,sf;
double x4,y4,x1,x2,x3,yy1,y2,y3;
double a[401][401];
inline double  get_num()
{
double  num = 0;
char c;
bool flag = false;
while ((c = getchar()) == ' ' || c == '\n' || c == '\r');
if (c == '-') flag = true;
else num = c - '0';
while (isdigit(c = getchar()))
num = num * 10 + c - '0';
return (flag ? -1 : 1) * num;
}
struct re
{
	double  z[2][5];
}city[101];
struct zqm
{
	double  to,fr,next;
	double w;
}q[10001];
void add(int aa,int  b,int c)
{
	p++;
	q[p].to=b;
	q[p].fr=aa;
	q[p].w=c;
	q[p].next=h[aa];
	h[aa]=p;
}
double jl(double  a,double  b,double  c,double  d)
{
	double x=sqrt((b-a)*(b-a)+(d-c)*(d-c));
	
	return x;
}
void find()
{
	double l1,l2,l3;
	l1=jl(x1,x2,yy1,y2);
    l2=jl(x1,x3,yy1,y3);
	l3=jl(x2,x3,y2,y3);
	//cout<<endl<<l1<<" "<<l2<<" "<<l3<<" \n";
	
    if(l3>l1&&l3>l2)
    {
    	x4=x2+(x3-x1);
    	y4=y2+(y3-yy1);
    }
    if(l2>l1&&l2>l3)
    {
    	x4=x1+x3-x2;
    	y4=yy1+y3-y2;
    }
    if(l1>l2&&l1>l3)
    {
    	x4=x1+x2-x3;
    	y4=yy1+y2-y3;
    }
}

void build(int i,double k)
{
	i--;
	/*add(i*4+1,i*4+2,k*jl(x1,x2,for(int,y2));
	add(i*4+1,i*4+3,k*jl(x1,x3,yy1,y3));
	add(i*4+1,i*4+4,k*jl(x1,x4,yy1,y4));
	add(i*4+2,i*4+3,k*jl(x2,x3,y2,y3));
	add(i*4+2,i*4+4,k*jl(x4,x2,y4,y2));
	add(i*4+3,i*4+4,k*jl(x3,x4,y3,y4));
	add(i*4+2,i*4+1,k*jl(x1,x2,yy1,y2));
	add(i*4+3,i*4+1,k*jl(x1,x3,yy1,y3));
	add(i*4+4,i*4+1,k*jl(x1,x4,yy1,y4));
	add(i*4+3,i*4+2,k*jl(x2,x3,y2,y3));
	add(i*4+4,i*4+2,k*jl(x4,x2,y4,y2));
	add(i*4+4,i*4+3,k*jl(x3,x4,y3,y4));*/
	a[i*4+1][i*4+2]=k*jl(x1,x2,yy1,y2);
	a[i*4+1][i*4+3]=k*jl(x1,x3,yy1,y3);
	a[i*4+1][i*4+4]=k*jl(x1,x4,yy1,y4);
	a[i*4+2][i*4+3]=k*jl(x2,x3,y2,y3);
	a[i*4+2][i*4+4]=k*jl(x4,x2,y4,y2);
	a[i*4+3][i*4+4]=k*jl(x3,x4,y3,y4);
	a[i*4+2][i*4+1]=k*jl(x1,x2,yy1,y2);
	a[i*4+3][i*4+1]=k*jl(x1,x3,yy1,y3);
	a[i*4+4][i*4+1]=k*jl(x1,x4,yy1,y4);
	a[i*4+3][i*4+2]=k*jl(x2,x3,y2,y3);
	a[i*4+4][i*4+2]=k*jl(x4,x2,y4,y2);
	a[i*4+4][i*4+3]=k*jl(x3,x4,y3,y4);
}
void just_doit()
{
	for(int  i=1;i<=4*n;i++)
		{
			a[i][i]=0;
		}
	for(int  k=1;k<=n*4;k++)
	{
		for(int  i=1;i<=4*n;i++)
		{
			for(int  j=1;j<=4*n;j++)
			{
				if(a[i][j]>a[i][k]+a[k][j])
				{
					a[i][j]=a[i][k]+a[k][j];
				}
			}
		}
	}
}
void mama()
{
    double mi= 2147483647;
    for(int  i=1;i<=4;i++)
    {
    	for(int  j=1;j<=4;j++)
    	{
    		//cout<<a[(s-1)*4+i][(t-1)*4+j]<<endl;
    		mi=min(a[(s-1)*4+i][(t-1)*4+j],mi);
    	}
    }
    printf("%.1lf\n",mi);
}
int main()
{
	double  T;
	cin>>T;
	while(T--)
	{
		double  sh[101];
		cin>>n>>sf>>s>>t;
		memset(a,127,sizeof(a));
		
		for(int  i=1;i<=n;i++)
		{
			cin>>x1>>yy1>>x2>>y2>>x3>>y3>>sh[i];
			find();
			city[i].z[0][1]=x1;
			city[i].z[0][2]=x2;
			city[i].z[0][3]=x3;
			city[i].z[0][4]=x4;
			city[i].z[1][1]=yy1;
			city[i].z[1][2]=y2;
			city[i].z[1][3]=y3;
			city[i].z[1][4]=y4;
			build(i,sh[i]);
		}
		for(int  i=1;i<=n;i++)
		{
			for(int  j=1+i;j<=n;j++)
			{
				if(j==i)continue;
				for(int  k=1;k<=4;k++)
				{
					int x=(i-1)*4+k;
					for(int  l=1;l<=4;l++)
					{
						int y=(j-1)*4+l;
						a[x][y]=sf*jl(city[i].z[0][k],city[j].z[0][l],city[i].z[1][k],city[j].z[1][l]);
						a[y][x]=a[x][y];
					}
				}
			}
		}
		just_doit();
		mama();
	} 

}

