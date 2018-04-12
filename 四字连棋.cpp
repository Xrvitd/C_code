#include<iostream>
#include<cmath>
#include<map> 
using namespace std;
int n,m,h,t,q[1000001][5][5]={0},a[5][5],step[1000001]={0};
struct re 
{
	int x,y;
};
map<string,int> v;
struct re la[1000001][3];
//bool v[1000001]={0};
int f[1000001]={0};
const int fx[5]={0,0,0,1,-1};
const int fy[5]={0,1,-1,0,0};
void copy(int qq,int w)
{
	for(int i=1;i<=4;i++)
	{
		for(int j=1;j<=4;j++)
		{
			q[w][i][j]=q[qq][i][j];
		}
	}
}
string zhuan(int x[5][5])
{
	
	string s; 
	s=x[1][1];
	s+=x[1][2];
	s+=x[1][3];
	s+=x[1][4];
	s+=x[2][1];
	s+=x[2][2];
	s+=x[2][3];
	s+=x[2][4];
	s+=x[3][1];
	s+=x[3][2];
	s+=x[3][3];
	s+=x[3][4];
	s+=x[4][1];
	s+=x[4][2];
	s+=x[4][3];
	s+=x[4][4];
	return s;
} 
bool win(int x[5][5])
{
	
	for(int i=1;i<=4;i++)
	{
		bool vq=0;
		for(int j=1;j<=3;j++)
		{
			if(x[j][i]!=x[j+1][i])
			{
				vq=1;
			}
		}
		if(!vq)
	    {
		return 1;
	    }
	}
	for(int i=1;i<=4;i++)
	{
		bool v1=0;
		for(int j=1;j<=3;j++)
		{
			if(x[i][j]!=x[i][j+1])
			{
				v1=1;
			}
		}
		if(!v1)
		{
			return 1;
		}
	}
	int vvv=0,vv=0;
	for(int i=1;i<=3;i++)
	{
		if(x[i][i]!=x[i+1][i+1])
		vvv=1;
		if(x[i][4-i+1]!=x[i+1][4-i])
		{
			vv=1;
		}
	}
	if(!vvv||!vv)
	{
		return 1;
	}
	return 0;
}
int main()
{
	int klk=0;
	for(int i=1;i<=4;i++)
	{
		for(int j=1;j<=4;j++)
		{
			char ch;
			cin>>ch;
			if(ch=='B') 
			{
				a[i][j]=0;
				q[1][i][j]=0;
				q[2][i][j]=0;
			}
			if(ch=='W') 
			{
				q[2][i][j]=1;
				a[i][j]=1;
				q[1][i][j]=1;
			}
			if(ch=='O') 
			{
				klk++;
				la[1][klk].x=i;
				la[1][klk].y=j;
				q[2][i][j]=2;
				a[i][j]=2;
				q[1][i][j]=2;
			}
		}
	}
	v[zhuan(a)]=1;
	h=0;t=1;
	while(h<=t)
	{
		h++;
		for(int io=1;io<=2;io++)
		{
		   int i,j;
		   i=la[h][io].x;
		   j=la[h][io].y;
				if(q[h][i][j]==2)
				{
					for(int k=1;k<=4;k++)
					{
						int tx=i+fx[k],ty=j+fy[k];
						if(i+fx[k]<=4&&i+fx[k]>0&&j+fy[k]<=4&&j+fy[k]>0)
						{
							if(q[h][tx][ty]==2)
							continue;
							if(h!=1)
							{
							if(f[h]==1)
							{
								if(q[h][tx][ty]==1)
							    {
							    	continue;
							    }
							}
							else
							if(f[h]==2)
							{
								if(q[h][tx][ty]==0)
								{
									continue;
								}
							}
							}
							t++;
							step[t]=step[h]+1;
							copy(h,t);
							q[t][i][j]=q[t][tx][ty];
							q[t][tx][ty]=2;
							if(q[t][i][j]==1) f[t]=1;
							if(q[t][i][j]==0) f[t]=2;
							if(io==1)
							{
								la[t][1].x=tx;
								la[t][1].y=ty;
								la[t][2].x=la[h][2].x;
								la[t][2].y=la[h][2].y;
							}else
							{
								la[t][2].x=tx;
								la[t][2].y=ty;
								la[t][1].x=la[h][1].x;
								la[t][1].y=la[h][1].y;
							}
							if(v[zhuan(q[t])])
							{
								t--;
							}else
							{
								v[zhuan(q[t])]=1;
							}
							if(win(q[t]))
							{
								cout<<step[t];
								return 0;
							}
						}
					}
				}
			
		}
		
	}

}
