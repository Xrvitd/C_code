#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#define _min(x, y) ((x)<(y)?(x):(y))
using namespace std;
int n,m,p[320000];
char s[320000],str[320000];

void mana()
{
	int i,mx=0,id;
	for(i=n; str[i]!=0; i++)
		str[i] = 0;
	for(int i=1;i<n;i++)
	{
		if(mx>i)
		{
			p[i]=_min(p[id*2-i],p[id]+id-i);
		}else
		{
			p[i]=1;
		} 
		/*while(s[i+p[i]]==s[i-p[i]])
		{
			p[i]++;
		} */
		for(; str[i+p[i]] == str[i-p[i]]; p[i]++)
            ;
		if(p[i]+i>mx)
		{
			mx=p[i]+i;
			id=i;
		}
	}
}
void init()
{
	str[0]='$';
	str[1]='#';
	for(int i=0;i<strlen(s);i++)
	{
		str[i*2+2]=s[i];
		str[i*2+3]='#';
	}
	n=strlen(s)*2+2;
	s[n]=0;
}
int main()
{
	while(scanf("%s", s)!=EOF)
	{
		n=strlen(s);
		init();
		mana();
		int ans=0;	//cout<<s<<endl;
		for(int i=0;i<n;i++)
		{
			if(p[i]>ans)
				ans = p[i];
		}
		printf("%d\n", ans-1);
	}
    return 0;
}

