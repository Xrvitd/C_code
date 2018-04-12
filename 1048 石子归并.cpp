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
int a[10001],f[101][101],s[10001]; 
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}
	for(int l = 2; l <= n; ++l)  
        {  
            for(int i = 1; i <= n - l + 1; ++i)  
            {  
                int j = i + l - 1;  
                f[i][j] = 2147483647;  
                for(int k = i; k < j; ++k)  
                {  
                    f[i][j] = min(f[i][j],f[i][k] + f[k + 1][j] + s[j] - s[i-1]);  
                }  
            }  
        }  
	cout<<f[1][n];
	

}

