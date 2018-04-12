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
string s;
int i,j,d,ls,shang[1000001],a[100001]; 
int main()
{
	cin>>s;
	cin>>d;
	ls=s.size();
	for(int i=1;i<=ls;i++)
	{
		a[i]=s[ls-i]-'0';
	}
	j=0;
	for(int i=ls;i>=1;i--)
	{
		j=j*10+a[i];
		shang[i]=j/d;
		j%=d;
	}
	while ((shang[ls]==0)&&ls>0) ls--;
	for(int i=ls;i>=1;i--) cout<<shang[i];
	
	

}

