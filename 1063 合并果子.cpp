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
int n,m,ans=0;
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
priority_queue <int ,vector<int>,greater<int> >q;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
    	int w;
    	cin>>w;
    	q.push(w);
    }
    while(q.size()>1)
    {
    	int k=ans;
    	ans+=q.top();
    	q.pop();
    	ans+=q.top();
    	q.pop();
    	q.push(ans-k);
    }
    cout<<ans;
}

