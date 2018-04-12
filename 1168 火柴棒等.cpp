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
int n,m=0,a[10]={6,2,5,5,4,5,6,3,7,6};
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
    cin>>n;
    n-=4;
    for(int i=0;i<=1000;i++)
    {
    	int ii=0,k=i;
    	while(1)
    	{
    		ii+=a[k%10];
    		
    		k/=10;if(k==0) break;
    	}
    	for(int j=0;j<=1000;j++)
    	{
    		int jj=0,kk=j;
    		while(1)
        	{
    		jj+=a[kk%10];
    		
    		kk/=10;
    		if(kk==0) break;
        	}
    		int l=i+j,ll=0;
    		while(1)
        	{
    		ll+=a[l%10];
    		
    		l/=10;if(l==0) break;
        	}
        	//cout<<i<<" "<<j<<" "<<i+j<<" "<< ii+jj+ll<<endl;
        	if(ii+jj+ll==n)
        	{
        		m++;
        	}
        	
    	}
    	
    }
    cout<<m;
}

