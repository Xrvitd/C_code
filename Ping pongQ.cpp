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
#define P 1000000007
#define debug(x) cerr<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
#define lb(x) (x&-x)
using namespace std;
int n,N,m,a[20001],c[100005],BIT[100001],ans=0,d,cnt=0;
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
void add(int x){
	while (x <= 100005){
		BIT[x]++;
		x += lb(x);
	}
}
int sum(int x){
	int ansa = 0;
	while (x>0){
		ansa += BIT[x];
		x -= lb(x);
	}
	return ansa;
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--){
		scanf("%d", &N);
		memset(BIT, 0, sizeof(BIT));
		for (int i = 1; i <= N; i++){
			scanf("%d", &a[i]);
			add(a[i]);
			c[i] = sum(a[i]-1);
		}
		memset(BIT, 0, sizeof(BIT));
		for (int i = N,  cnt = 0; i > 0; i--){
			add(a[i]);
			d = sum(a[i] - 1);
			cnt += c[i] * (N - i - d) + (i - c[i] - 1)*d;
		}
		printf("%lld\n", cnt);
	}
	return 0;

}

