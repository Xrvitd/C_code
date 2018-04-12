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
int n,m;
int q[1000001],lq[1000001]={0},h[13599],v[13599],w[13599],z[13599],next[13599],p,ha=0,ti=1,d[13599][5];
bool f[13599];
void add(int a,int b,int c,char d)
{
	p++;
	v[p]=b;
	w[p]=c;
	if(d=='L') z[p]=1;
	if(d=='O') z[p]=2;
	if(d=='V') z[p]=3;
	if(d=='E') z[p]=4;
	next[p]=h[a];
	h[a]=p;
}
void spfa()
{
	q[1]=1;
	f[1]=1;
	memset(d,127,sizeof(d));
	d[1][0]=0;
	while(ha<=ti)
	{
		ha++;
		p=h[ha];
		int i=q[ha];
		//f[ha]=0;
		while(p)
		{
			if(v[p]==n&&lq[ha]==3&&z[p]==4)
			{
				d[v[p]][4]=min(d[v[p]][4],d[i][3]+w[p]);
			}
			if(d[v[p]][lq[ha]]<=d[i][z[p]]+w[p]&&lq[ha]+1==z[p]&&v[p]!=n)
			{
				d[v[p]][z[p]]=d[i][lq[ha]]+w[i];
				//if(!f[v[p]])
				//{
					ti++;
					q[ti]=v[p];
					//f[v[p]]=1;
					lq[ti]=z[p];
			//	}
			}
			p=next[p];
		}
	}
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int a,b,c;
		char d;
		cin>>a>>b>>c>>d;
		add(a,b,c,d);
		add(b,a,c,d);
	}
	spfa();
	cout<<d[n];
}

