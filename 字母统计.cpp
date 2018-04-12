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
int n,m,k;
string s[5],ll;
int sum[1000],ma=0,la[1000];
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
	freopen("out.txt","w",stdout);
    cin>>k;
    getline(cin,ll);
	while(k--)
	{
		memset(sum,0,sizeof(sum));
        memset(la,0,sizeof(la));
		ma=0;
		for(int i=1;i<=4;i++)
		{
			getline(cin,s[i]);
			for(int j=0;j<s[i].size();j++)
			{
				if(s[i][j]>='A'&&s[i][j]<='Z')
				{
					sum[s[i][j]]++;
					ma=max(ma,sum[s[i][j]]);
				}
			}
		}
		for(int i=1;i<=ma;i++)
		{
			for(int j=1;j<=26;j++)
			{
				if(sum[j-1+'A']>=ma-i+1)
				{
					la[i]=j;
				}
			}	
		} 
		for(int i=1;i<=ma;i++)
		{
			for(int j=1;j<la[i];j++)
			{
				if(sum[j-1+'A']>=ma-i+1)
				{
					cout<<"* ";
				}else
				{
					cout<<"  ";
				}
			}
			
			if(sum[la[i]-1+'A']>=ma-i+1)
			{
					cout<<"*";
			}else
			{
					cout<<" ";
			}
			cout<<"\n";
		}
		for(int i=0;i<25;i++)
		{
			cout<<(char) ('A'+i)<<" ";
		}
		cout<<"Z";
		if(k) 
		cout<<"\n";
	} 
}

