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
#define MP(x,y) make_pair(x,y)
using namespace std;
int n,m,k;
string s;
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
	cin>>k;
	for(int q=1;q<=k;q++)
	{
		cin>>n;
		for(int ii=1;ii<=n;ii++)
		{
			cin>>s;
			int len=s.size(),ans;
			for(int k=1; k<=len; k++)
			{  
            if(len%k==0){  
                  
                bool find = true;  
                for(int i=k; i<len; i++){  
                    if(s[i] ==s[i%k]){  
                    }else{  
                        find = false;  
                        break;  
                    }  
                }  
                  
                if(find){  
                cout<<k<<'\n';
                    break;  
                }  
            }  
        }  
		}
		cout<<'\n';
	}
} 

