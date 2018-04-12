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
char s[10010],s1[10010],v[10010];
int longt(char* s)
{
	int sum=0;
	while(s[sum]!='\0')
	{
		sum++;
	}
	return sum;
}
char* get_du(char* s)
{
	int l=longt(s);
	for(int i=l-1;i>=0;i--)
	{
		if(s[i]=='\\')
		{
			return &s[i+1];
		}
	}
}
void get_mu(char* s,char* v)
{
	int l=longt(s);
	for(int i=l-1;i>=0;i--)
	{
		if(s[i]=='\\')
		{
			for(int j=0;j<=i;j++)
			{
				v[j]=s[j];
			}
			v[i+1]='\0';
			return;
		}
	}
}
void chenge(char* s,char* s1,char *v)
{
	int l=longt(s),k=longt(s1);
	for(int i=0;i<k;i++)
	{
		v[i]=s1[i];
	}
	bool bq=0;
	for(int i=l-1;i>=0;i--)
	{
		if(s[i]=='\\')
		{
		     for(int j=i+1;j<l;j++)
		     {
		        v[k]=s[j];
		     	k++;
		     }
		     v[k]='\0';
		     return;
		}
		
	}
}
void connect(char* s,char* s1)
{
	int l=longt(s),k=longt(s1);
	if(s[l-1]!='\\')
	{
		l++;
		s[l-1]='\\';
	}
	for(int i=0;i<=k;i++)
	{
		s[l+i]=s1[i];
	}
}
int main()
{
	cout<<"输入路径：\n"; 
	cin>>s;
	cout<<"longth:"<<longt(s)<<endl;
	cout<<"\n文件名："; 
	cout<<get_du(s)<<'\n';
	get_mu(s,v);
	cout<<"\n路径："; 
	cout<<v<<'\n';
	cout<<"\n输入要替换的路径：";
	cin>>s1;
	chenge(s,s1,v);
	cout<<v<<'\n';
     cout<<"\n输入要合并的路径和文件名：\n";
	cin>>s>>s1;
	connect(s,s1);
	cout<<s;
} 


