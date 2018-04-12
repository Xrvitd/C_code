#include<iostream>
using namespace std;
int n,m,l,p1,p2,p3,q,w;
string s;
void f(int x,int p)
{
	bool v=0;
	int nn=s[x+1]-s[x-1]-1;
	string ss;
	if(s[x-1]<=90) v=1;
	for(int i=1;i<=nn;i++)
	{
		for(int j=1;j<=p2;j++)
		{
			if(p==1&&!v)
			{
			char ch;
			ch=i+s[x-1];
			ss+=ch;
			}
			if(p==1&&v)
			{
				char ch;
			ch=i+s[x-1]+32;
			ss+=ch;
			}
			if(p==2&&!v)
			{
			char ch;
			ch=i+s[x-1]-32;
			ss+=ch;
			}
			if(p==2&&v)
			{
			char ch;
			ch=i+s[x-1];
			ss+=ch;
			}
			if(p==3)
			{
				char ch;
			ch='*';
			ss+=ch;
			}
		}
	}
//	cout<<ss<<endl;
	s.replace(x,1,ss);
	q=x;w=x+p2*nn-1;
}
void ff(int x)
{
		int nn=s[x+1]-s[x-1]-1;
			string ss;
	for(int i=1;i<=nn;i++)
	{
		for(int j=1;j<=p2;j++)
		{
		if(p1==3)
			{
			char ch;
			ch='*';
			ss+=ch;
			}
			else
			{
			char ch;
			ch=i+s[x-1];
			ss+=ch;
			}
		}
    }
	s.replace(x,1,ss);
	q=x;w=x+p2*nn-1;

}
int main()
{
	cin>>p1>>p2>>p3;
	cin>>s;
	bool v=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]!='-') v=1;
		if(v)
		if(s[i]=='-')
		{
			if(s[i-1]>s[i+1]) continue;
			if(s[i-1]<=57&&s[i+1]>=64) continue;
			if(s[i-1]>=64&&s[i+1]<=57) continue;	
			if(s[i-1]+1==s[i+1]) s.erase(i,0); 
		    if(s[i-1]==s[i+1]) continue;
		    if(!(s[i-1]>=48&&s[i-1]<=57))
		    {
		    	f(i,p1);
		    	if(p3==2)
		    	{
		    		int kk=-1;
		    		for(int j=q;j<=(q+w)/2;j++)
		    		{
		    			kk++;
		    			char ch;
						ch=s[j];
						s[j]=s[w-kk];
						s[w-kk]=ch;
					}
				}
			}
			else
			{
				ff(i);
				if(p3==2)
		    	{
		    		int kk=-1;
		    		for(int j=q;j<=(q+w)/2;j++)
		    		{
		    			kk++;
		    			char ch;
						ch=s[j];
						s[j]=s[w-kk];
						s[w-kk]=ch;
					}
				}
			}
		}
	}
	cout<<s;
	return 0;
}
