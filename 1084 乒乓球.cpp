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
int n,m,k=0,o=0;
int q,w,e,r;
struct zqm
{
	int x,y;
}a[10001],b[1001];
int main()
{
	char c;
	while(cin>>c)
	{
		if(c=='E')
		{
			
			k++;
				a[k].x=q;
				a[k].y=w;
				o++;
				b[o].x=e;
				b[o].y=r;
			break;	
		}
		if(c=='W')
		{
			q++;
			if(q==11)
			{
				k++;
				a[k].x=q;
				a[k].y=w;
				q=0;w=0;
			}
			e++;
			if(e==21)
			{
				o++;
				b[o].x=e;
				b[o].y=r;
				e=0;r=0;
			}
		}
		if(c=='L')
		{
			w++;
			if(w==11)
			{
				k++;
				a[k].x=q;
				a[k].y=w;
				w=0;q=0;
			}
			r++;
			if(r==21)
			{
				o++;
				b[o].x=e;
				b[o].y=r;
				r=0;e=0;
			}
		}
		
	}
	for(int i=1;i<=k;i++)
	{
		cout<<a[i].x<<":"<<a[i].y<<endl;
	} 
	cout<<endl;
	for(int i=1;i<=o;i++)
	{
		cout<<b[i].x<<":"<<b[i].y<<endl;
	} 

}

