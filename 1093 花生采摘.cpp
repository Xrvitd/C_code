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
int fx[5]={0,1,-1,0,0};
int fy[5]={0,0,0,1,-1};
int n,m,h,t,a[21][21],k,ans=0;
bool v[31][31];
struct zqm
{
	int x,y,s,ti,mi,bh;
}q[10001];
struct re
{
	int x,y,s;
}b[100001];
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
bool cmp(re a,re b)
{
	return a.s>b.s;
}
int main()
{
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
			b[(i-1)*n+j].s=a[i][j];
			b[(i-1)*n+j].x=i;
			b[(i-1)*n+j].y=j;
		}
	}
	sort(b+1,b+1+10001,cmp);
    h=0;t=1;
    t=k;
    t--;
    int su=0,xx=1,yy=b[1].y,i=1;
    while(t>0)
    {
    	cout<<xx<<" "<<yy<< " "<<t<<endl;
    	if(b[i].s==0)
        {
        	if(t>b[i].y)
    	    {
    		ans=max(ans,su);
         	}
        	break;
        }
    	t-=abs(b[i].y-yy)+abs(b[i].x-xx);
    	su+=b[i].s;
    	t--;
    	xx=b[i].x;
    	yy=b[i].y;
    	if(t>=b[i].x)
    	{
    		ans=max(ans,su);
    	}else
    	{
    		break;
    	}
    	i++;
    }
    cout<<ans;
}

