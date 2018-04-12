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
long long n,ans=0,k,v[1001]={0},b[1001]={0},m[1001]={0},l=0,f[1001][1001]={0};
bool bc[1001]={0},vv[1001]={0};
double X;
struct re
{
	long long v,m,kk,bh;
}q[1001],p[1001];
inline long long get_num()
{
long long num = 0;
char c;
bool flag = false;
while ((c = getchar()) == ' ' || c == '\n' || c == '\r');
if (c == '-') flag = true;
else num = c - '0';
while (isdigit(c = getchar()))
num = num * 10 + c - '0';
return (flag ? -1 : 1) * num;
}
int main()
{
	cin>>n>>k>>X;
	X*=10;
	long long s=(long long) X;
	for(long long i=1;i<=n;i++)
	{
		double q;
		cin>>q;
		v[i]=q*10;
	}
	for(long long i=1;i<=n;i++)
	{
		cin>>m[i];
	}
	for(long long i=1;i<=n;i++)
	{
		cin>>b[i];
		q[b[i]].v=v[i];
		q[b[i]].m=m[i];
		q[b[i]].kk=i;
		if(!bc[b[i]])
		{
			bc[b[i]]=1;
		}else
		{
			vv[i]=1;
		}
	}
	for(long long i=1;i<=k;i++)
	{
	    long long w;
	    cin>>w;
	    for(long long i=1;i<=n;i++)
	    {
	    	if(b[i]==w)
	    	vv[i]=1;
	    }
	    ans+=q[w].m;
	    s-=q[w].v;
	}
	for(long long i=1;i<=n;i++)
	{
		if(!vv[i])
		{
			l++;
			p[l].v=v[i];
			p[l].m=m[i];
			p[l].bh=b[i];
		}
	}
	for(long long i=1;i<=l;i++)
	{
		//cout<<p[i].v<<" "<<p[i].m<<'\n';
	}
	//cout<<ans<<" "<<s<<endl;
	for(long long j=0;j<=s;j++)
	{
		for(long long i=0;i<=l;i++)
		{
			if(j<p[i].v)
			{f[i][j]=f[i-1][j];continue;}
			else
			{
			    f[i][j]=max(f[i-1][j],f[i-1][j-p[i].v]+p[i].m);
			    //cout<<f[i][j]<<" ";
			}
		}//cout<<endl;
	}
	cout<<f[l][s]+ans;

}

