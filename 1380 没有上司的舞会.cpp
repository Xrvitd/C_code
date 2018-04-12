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
int n,m,p=0,h[10001];
struct zqm
{
	int v,next,w;
}q[200001];
void add(int a,int b)
{
	p++;
	q[p].v=b;
	q[p].next=h[a];
	h[a]=p;
}
int a[10001];
int f[10001][2];
bool v[6001];

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
void dfs(int x)
{
	int pp=h[x];
	while(pp)
	{
		
		int k=q[pp].v;
		if(v[k])
		{
		v[k]=0;
		dfs(k);
		f[x][0]+=max(f[k][1],f[k][0]);
		f[x][1]+=f[k][0];
		pp=q[pp].next;
		}
		
	}
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>f[i][1];
	} 
    for(int i=1;i<n;i++)
    {
    	int q,w;
    	cin>>q>>w;
    	v[q]=1;
    	add(w,q);
    }
    for(int i=1;i<=n;i++)
    {
    	if(!v[i])
    	{
    		v[i]=1;
    		dfs(i);
    		cout<<max(f[i][1],f[i][0]);
    		break;
    	}
    }
    
}

