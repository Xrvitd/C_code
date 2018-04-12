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
 
const int maxn=250;
const int maxm=10;
 
string s;
int slen;
string words[maxm];
int wordslen[maxm];
int f[maxn][maxm];
int sum[maxn][maxn];
int n,k,m,qqw;
 
void init()
{
    string tmp;
    cin>>n>>k;
    for (int i=1;i<=n;i++)
    {
        cin>>tmp;
        s+=tmp;
    }
    slen=s.size();
    cin>>m;
    for (int i=1;i<=m;i++)
    {
        cin>>words[i];
        wordslen[i]=words[i].size();
    }
}
 
int add(int l,int r)
{
    int ans=0;
    if (r-1>=0) ans=sum[l][r-1];
    bool vis[maxn]={0};
    for (int i=1;i<=m;i++)
    {
        int qd=r-wordslen[i]+1;
        if (qd<l) continue;
        if (qd==s.find(words[i],qd))
        {
            if (vis[qd]) continue;
            vis[qd]=1;
            ans++;
            for (int j=1;j<=m;j++)
            {
                int dq=r-wordslen[j];
                if (dq==qd)
                    if (dq==s.find(words[j],dq))
                    {
                        ans--;
                        break;
                    }
            }
        }
    }
    return ans;
}
 
void gsum()
{
    for (int i=0;i<=slen-1;i++)
        for (int j=i;j<=slen-1;j++)
        {
            sum[i][j]=add(i,j);
          //  printf("%d %d --> %d\n",i,j,sum[i][j]);
        }
}
 
void work()
{
    for (int i=0;i<=slen-2;i++)
        f[i][1]=sum[0][i];
    for (int i=0;i<=slen-2;i++)
        for (int j=2;j<=min(k-1,i+1);j++)
            for (int u=j-2;u<=i-1;u++)
                f[i][j]=max(f[i][j],f[u][j-1]+sum[u+1][i]);
    int ans=0;
    if (k==0)
        ans=sum[0][slen-1];
    else
        for (int i=k-1;i<=slen-2;i++)
            ans=max(ans,f[i][k-1]+sum[i+1][slen-1]);
    printf("%d\n",ans);
}
 
int main()
{
	cin>>qqw;
	while(qqw--)
	{
		init();
    gsum();
    work();
	}
    
    return 0;
}
