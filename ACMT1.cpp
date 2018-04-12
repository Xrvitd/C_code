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
int n=0,k=0,g=0,o=0,d=0,m=0,r=0,i=0,ko=0;
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
	string s ;
		getline(cin,s);
	for(int q=1;q<=k;q++)
	{
		getline(cin,s);
		n=0;g=0;o=0;d=0;m=0;r=0;i=0;ko=0;
		for(int j=0;j<s.size();j++) 
		{
			if(s[j]=='g') g++;
			if(s[j]=='o') o++;
			if(s[j]=='d') d++;
			if(s[j]=='m') m++;
			if(s[j]=='r') r++;
			if(s[j]=='i') i++;
			if(s[j]=='n') n++;
			if(s[j]==' ') ko++;
		}
		int ans=min(g-1,o/3);
		ans=min(ans,d);
		ans=min(ans,m);
		ans=min(ans,r);ans=min(ans,ko);
		ans=min(ans,i);
		ans=min(ans,n/2);
	//	cout<<g<<o<<d<<m<<r<<i<<n<<endl;
	//	cout<<endl;
	if(ans>=1)
		cout<<ans<<'\n';
		else
		{
			cout<<0<<'\n';
		}
	}
}
 


