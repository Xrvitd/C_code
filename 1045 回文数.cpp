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
char s[10001];
inline long long get_num()
{
long long num = 0;
char c;
bool flag = false;
while ((c = getchar()) == ' ' || c == '\n' || c == '\r');
if (c == '-') flag = true;
else num = c - '0';
while (isdigit(c = getchar()))
num = num * 10 + c - '0';
return (flag ? -1 : 1) * num;
}
bool pd()
{
	long long kk=strlen(s);
	for(long long i=0;i<kk/2;i++)
	{
		if(s[i]!=s[kk-i-1]) return 0;
	}
	return 1;
}
long long cf(long long x,long long y)
{
	long long sum=1;
	for(long long i=1;i<=y;i++)
	sum*=x;
	return sum;
}
void chenge()
{
	char t[10001];
	int k=strlen(s);
	int last=0;
	for(int i=0;i<k;i++)
	{
		int x,y,z;
		if(s[i]<='9')
		{
			x=s[i]-'0';
		}
		if(s[i]=='A') x=10;
		if(s[i]=='B') x=11;
		if(s[i]=='C') x=12;
		if(s[i]=='D') x=13;
		if(s[i]=='E') x=14;
		if(s[i]=='F') x=15; 
		if(s[k-i-1]<='9')
		{
			y=s[k-i-1]-'0';
		}
		if(s[k-i-1]=='A') y=10;
		if(s[k-i-1]=='B') y=11;
		if(s[k-i-1]=='C') y=12;
		if(s[k-i-1]=='D') y=13;
		if(s[k-i-1]=='E') y=14;
		if(s[k-i-1]=='F') y=15; 
		z=x+y+last;
		//cout<<z<<" ";
		last=z/n;
		z=z%n;
		if(z==1) t[i]='1';
		if(z==2) t[i]='2';
		if(z==3) t[i]='3';
		if(z==4) t[i]='4';
		if(z==5) t[i]='5';
		if(z==6) t[i]='6';if(z==0) t[i]='0';
		if(z==7) t[i]='7';
		if(z==8) t[i]='8';
		if(z==9) t[i]='9';
		if(z==10) t[i]='A';
		if(z==11) t[i]='B';
    	if(z==12) t[i]='C';
		if(z==13) t[i]='D';
		if(z==14) t[i]='E';
		if(z==15) t[i]='F';
	}
	while(last>0)
	{
		int z=last%n;
		last=last/n;
		if(z==1) t[k]='1';
		if(z==2) t[k]='2';
		if(z==3) t[k]='3';
		if(z==4) t[k]='4';
		if(z==5) t[k]='5';
		if(z==6) t[k]='6';if(z==0) t[k]='0';
		if(z==7) t[k]='7';
		if(z==8) t[k]='8';
		if(z==9) t[k]='9';
		if(z==10) t[k]='A';
		if(z==11) t[k]='B';
    	if(z==12) t[k]='C';
		if(z==13) t[k]='D';
		if(z==14) t[k]='E';
		if(z==15) t[k]='F';
		k++;
	}
	for(int i=0;i<k;i++)
	{
		s[i]=t[k-1-i];
	}
}
int main()
{
	
	cin>>n>>s;
	long long k=0;
	while(k<30&&!pd())
	{
		chenge();
		k++;
	} 
	if(k>=30)
	{
		cout<<"Impossible!";
		return 0;
	}
	cout<<"STEP="<<k;
}

