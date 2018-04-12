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
int n,p,m,h[100001];
int rd[100010];
stack<int>s;
struct zqm
{
	int v,next;
}q[200001];
void add(int a,int b)
{
	p++;
	q[p].v=b;
	q[p].next=h[a];
	h[a]=p;
}
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
void topusort()
{
	for(int i=1;i<=n;i++)
	{
		if(rd[i]==0)
		{
			s.push(i);
		}
	}
	while(!s.empty())
	{
		int t=s.top();
		s.pop();
		p=h[t];
		while(p)
		{
			int k=q[p].v;
			rd[k]--;
			if(rd[k]==0)
			{
				s.push(k);
			}
			p=q[p].next;
		}
	}
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int q,w;
		cin>>q>>w;
		add(q,w);
		rd[w]++;
	}
	topusort();
	bool vv=0;
	int cnt=0;
    for(int i=1;i<=n;i++)
    {
    	if(rd[i])
    	{
    		vv=1;
    		cnt++;
    	}
    }if(vv)
    {
    	cout<<"T_T\n";
    	cout<<cnt;
    }else
    cout<<"o(กษ_กษ)o";
}

