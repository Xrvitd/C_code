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
int n=2147463644,m=0;
string s;
int a[200]={0};
int p(int aa)
{
    int i;
    if(aa==0) return 0;
    if(aa==1) return 0;
    for(i=2;i*i<=aa;i++)
    if(aa%i==0) return 0;
    return 1;
}
int main()
{
	char c;
	while(cin>>c)
	{
		int q=c-'a'+1;
		a[q]++;
	}
	for(int i=1;i<=26;i++)
	{
		if(a[i])
		n=min(n,a[i]);
		m=max(m,a[i]);
	}
	int k=m-n;
	if(p(k))
	cout<<"Lucky Word\n"<<k;
	else
	cout<<"No Answer\n"<<k;	return 0;
	

}

