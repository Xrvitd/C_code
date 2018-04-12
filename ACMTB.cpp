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
int n,m,k,h,t,ret=0;
int a[3][5]={0};
string an;
struct RE {
	
    int	m[3][5];
    string s="";
}q[100010];
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
void copy(int a[3][5],int b[3][5])
{
	for(int i=1;i<=2;i++)
	{
		for(int j=1;j<=4;j++)
		{
			a[i][j]=b[i][j];
		}
	}
}
int z(int a[3][5])
{
	int an=0;
	an+=a[2][1];
	an+=a[2][2]*10;
	an+=a[2][3]*100;
	an+=a[2][4]*1000;
	an+=a[1][4]*10000;
	an+=a[1][3]*100000;
	an+=a[1][2]*1000000;
	an+=a[1][1]*10000000;
	return an;
}
bool v[999999]={0};
int main()
{
	cin>>k;
	for(int ii=1;ii<=k;ii++)
    {
    	memset(v,0,sizeof(v));
        string s;
        cin>>s;
        a[1][1]=s[0]-'0';
        a[1][2]=s[1]-'0';
        a[1][3]=s[2]-'0';
        a[1][4]=s[3]-'0';
        a[2][4]=s[4]-'0';
        a[2][3]=s[5]-'0';
        a[2][2]=s[6]-'0';
        a[2][1]=s[7]-'0';
        v[z(a)%999997]=1;
        cin>>an;
        ret=(an[0]-'0')*10000000+
            (an[1]-'0')*1000000+
            (an[2]-'0')*100000+
            (an[3]-'0')*10000+
            (an[4]-'0')*1000+
            (an[5]-'0')*100+
            (an[6]-'0')*10+
            (an[7]-'0');
           
        
        h=0;t=1;
        copy(q[1].m,a);
        while(h<=t)
        {
        	h++;
        	
        	t++;
        	for(int i=1;i<=4;i++)
        	{
        		q[t].m[1][i]=q[h].m[2][i];
        		q[t].m[2][i]=q[h].m[1][i];
        		
        	}
        	/*for(int i=1;i<=2;i++)
        	{
        		for(int j=1;j<=4;j++)
        		{
        			cout<<q[t].m[i][j]<<" ";
        		}
        		cout<<endl;
        	}cout<<endl;*/
        	if(!v[z(q[t].m)%999997])
        		{
        			v[z(q[t].m)%999997]=1;
        			q[t].s=q[h].s+"A"; 
        			if(z(q[t].m)==ret)
        			{
        				cout<<q[t].s<<'\n';
        				break;
        			}
        			t++;
        			
        		}
        	t--;
        	
        	
        	t++;
        	q[t].m[1][1]=q[h].m[1][4];
        	q[t].m[2][1]=q[h].m[2][4];
        	for(int i=2;i<=4;i++)
        	{
        		q[t].m[1][i]=q[h].m[1][i-1];
        		q[t].m[2][i]=q[h].m[2][i-1];
        	}
	
			if(!v[z(q[t].m)%999997])
        		{
        			v[z(q[t].m)%999997]=1;
        			q[t].s=q[h].s+"B"; 
        			if(z(q[t].m)==ret)
        			{
        				cout<<q[t].s<<'\n';
        				break;
        			}
        			t++;
        		}
        	t--;
        	
        	
        	t++;
        	q[t].m[1][2]=q[h].m[2][2];
        	q[t].m[1][3]=q[h].m[1][2];
        	q[t].m[2][2]=q[h].m[2][3];
        	q[t].m[2][3]=q[h].m[1][3];
        	for(int i=1;i<=4;i+=3)
        	{
        		q[t].m[1][i]=q[h].m[1][i];
        		q[t].m[2][i]=q[h].m[2][i];
        	}
			
			
			if(!v[z(q[t].m)%999997])
        		{
        			v[z(q[t].m)%999997]=1;
        			q[t].s=q[h].s+"C"; 
        			if(z(q[t].m)==ret)
        			{
        				cout<<q[t].s<<'\n';
        				break;
        			}
        			t++;
        		}
        	t--;
        	
        }
	    
    }
}

