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
int n,m,yq,ma,x,y,k,ll,yx;
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
int main()
{
	cin>>yq;
	cin>>n>>m;
	int q,w;
	while(cin>>q>>w)
	{
		if(q==-1)break;
		x=q;y=w;
		if(q==yq)
		yx=w;
		if((q-n)*w>ma)
		{
			ma=(q-n)*w;
			ll=q;
		}
	}
	cin>>k;
	int s=1;
	int c=x-n+s,d=y-k*s;
	while(d>0)
	{
        //cout<<c<< " "<<d<<endl;
		if(x-n+s==yq)  yx=y-k*s;
		//cout<<yx<< " "; 
		c=x-n+s;
		d=y-k*s;
		if(c*d>ma)
		{
			ma=c*d;
			ll=x+s;
		}else
		{
			break;
		}
		s++;
	}
	if(!yx)
	{
		int r=x,t=y;
		while(r!=yq)
		{
			r++;
			t-=k;
		}
		yx=k;
	}
	if(k<=0)
	{
		cout<<"NO SOLUTION";
		return 0;
	} 
	if(ma%yx==0)
	cout<<ma/yx;
	else
	cout<<ma/yx+1;
   
	
}

