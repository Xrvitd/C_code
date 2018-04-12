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
int n,m,q[10000001][16],step[10000001];
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
bool win(int x)
{
	for(int i=1;i<=15;i++)
	{
		if(q[x][i]!=0)
		return 0;
	}return 1;
}
void copy(int x,int y)
{
	for(int k=1;k<=15;k++)
	{
    	q[y][k]=q[x][k];
	}
	step[y]=step[x]+1;
}
int main()
{
	freopen("landlords.in","r",stdin);
	freopen("out.txt","w",stdout); 
	n=get_num();m=get_num();
	int lt=0;
	while(n)
	{
		memset(q,0,lt+1);
		memset(step,0,lt+1);
		for(int i=1;i<=m;i++)
		{
			int w,e;
			cin>>w>>e;
			if(w==0)
			{
				if(e==1)
				q[1][14]++;
				else
				q[1][15]++;
			}
			q[1][w]++;
		}
		int h=0,t=1;bool vvv=1;
		while(h<=t)
		{
			h++;
			if(step[h]>m)
			{
				continue;
			}
			if(!vvv)
			{
				break;
			}
			for(int i=1;i<=13;i++)
			{
				if(q[h][i]>=2)
			    {
				    t++;
				    copy(h,t);
				    q[t][i]-=2;
				    if(win(t))
				    {
					    cout<<step[t]<<"\n";
					    vvv=0;
				    	break;
		    		}

		    	}
			}
			for(int i=1;i<=13;i++)
		    {
		    	if(q[h][i])
		    	{
		    		t++;
		    	    copy(h,t);
		    	    q[t][i]--;
		    	    if(win(t))
					{
						cout<<step[t]<<"\n";
						vvv=0;
				    	break;
					}
		    	}
		    	
		    }
		}
		lt=t;
		n--; 
	}
}
