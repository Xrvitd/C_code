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
int n,m,w[200001],h[200001],p=0,qu[200001],tot,ans,sum;
struct zqm
{
	int v,next;
}q[400101];
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
void add(int a,int b)
{
	p++;
	q[p].v=b;
	q[p].next=h[a];
	h[a]=p;
}
int main()
{
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int q,w;
		q=get_num();w=get_num();
		add(q,w);
		add(w,q);
	} 
	for(int i=1;i<=n;i++)
	{
		w[i]=get_num();
	}
	for(int i=1;i<=n;i++)
	{
		map <int,bool> v;
		v[i]=1;
		tot=0;
		p=h[i];
		while(p)
		{
			tot++;
			qu[tot]=q[p].v;
			p=q[p].next;
			v[q[p].v]=1;
		}
		for(int j=1;j<=tot;j++)
		{
			p=h[qu[j]];
			while(p)
			{
				int k=q[p].v;
				if(v[k])
				{
					p=q[p].next;
					continue;
				}
				v[k]=1;
				ans=max(ans,w[i]*w[k]);
				sum+=w[i]*w[k];
			}
		}
	}
	cout<<ans<<" "<<sum;

}

