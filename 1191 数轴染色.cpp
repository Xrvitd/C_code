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
int t[1000010],lazy[1000010]; 
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
void build(int x,int l,int r)
{
	if(l==r)
	{
		t[x]=1;
		return;
	} 
	int mid=(l+r)>>1;
	build(2*x,l,mid);
    build(2*x+1,mid+1,r);
    t[x]=t[2*x]+t[2*x+1];
}
void find(int x,int l,int r,int q,int w)
{
	if(t[x]==0)
	return;
	if(l==q&&r==w)
    {
    	t[x]=0;
    	return;
    }
    int mid=(l+r)>>1;
    if(mid>=w)
    {
        find(2*x,l,mid,q,w);
    }else
    {
    	if(mid<q)
    	find(2*x+1,mid+1,r,q,w);
    	else
    	{
		find(2*x,l,mid,q,mid);
		find(2*x+1,mid+1,r,mid+1,w);
	    }
    }
    t[x]=t[2*x]+t[2*x+1];
}
int main()
{
	cin>>n>>m;
	build(1,1,n);
	for(int i=1;i<=m;i++)
	{
		int q,w;
		q=get_num();
		w=get_num();
		find(1,1,n,q,w);
		cout<<t[1]<<endl;
	}
}

