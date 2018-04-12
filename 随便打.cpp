#include<iostream>
#include<map>
using namespace std;
int n,m,a[6][6]={0};
int fx[5]={0,0,0,1,-1},fy[5]={0,1,-1,0,0};
struct re 
{
	int x,y;
    int  v[6][6];
} q[10001];
map<string,bool> f;
string z(int k)
{
	string ss;
	ss[0]=' ';
	int l=1;
	for(int i=1;i<=5;i++)
	{
		for(int j=1;j<=5;j++)
		{
			char c;
			c=(int) q[k].v[i][j] +'0';
			ss[l]=c;
			l++;
		}
	}
	
	return ss;
}
bool win(int ii)
{
	bool vvv=0;
	for(int i=1;i<=5;i++)
	{
		for(int j=1;j<=5;j++)
		{
			if(!q[ii].v[i][j])
			{
				vvv=1;
			}
		}
	}
	if(vvv)
	{
		return 0;
	}
	return 1;
}
int main()
{
	q[1].v[1][2]=1;
	cout<<z(1);
	/*q[1].v[1][2]=1;q[1].x=1;
	q[1].y=2;
	int h=0,t=1;
	
	f[z(1)]=1;
	while(h<=t)
	{
		h++;
		for(int i=1;i<=4;i++)
		{
			int tx=q[h].x+fx[i],ty=q[h].y+fy[i];
			if(tx>=1&&tx<=5&&ty>=1&&ty<=5)
			{
				cout<<tx<<" "<<ty<<endl; 
				t++;
				q[t]=q[h];
				q[t].v[tx][ty]=1;
				if(!f[z(t)])
				{
					q[t].x=tx;
					q[t].y=ty;
					for(int ii=1;ii<=5;ii++)
					{
						for(int j=1;j<=5;j++)
						{
							cout<<q[t].v[ii][j]<< " ";
						}
						cout<<endl;
					}
					cout<<endl;
					if(win(t))               
					{
						cout<<"FOUND!!";
						return 0;
					}
				}else
				{
					t--;
				}
			}
		} 
	}
	cout<<"CAN NOT FOUND!!!!!!";
	return 0;*/
}
