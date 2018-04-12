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
int n,m,q[10000001][16],step[10000001];
struct zqm
{
	int data,color;
}a[25];
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
bool win(int x)
{
	for(int i=1;i<=15;i++)
	{
		if(q[x][i]!=0)
		return 0;
	}return 1;
}
void copy(int x,int y)
{
	for(int k=1;k<=15;k++)
	{
    	q[y][k]=q[x][k];
	}
	step[y]=step[x]+1;
}
int main()
{
	freopen("landlords.in","r",stdin);
	freopen("out.txt","w",stdout); 
	n=get_num();m=get_num();
	for(int ii=1;ii<=n;ii++)
	{
		memset(q,0,sizeof(q));
		for(int i=1;i<=m;i++)
		{
			int qw,w;
			qw=get_num();
			w=get_num();
			if(qw==0)
			{
				if(w==1)
				{
					q[1][14]++;
					 
				}else
				{
					q[1][15]++;
				}
			}
			q[1][qw]++;
		}
		int h=0,t=1;bool vvv=1;
		while(h<=t)
		{
			h++;
			if(step[h]>m)
			{
				continue;
			}
			bool vv=1;
			if(!vvv)
			{
				break;
			}
			/*if(q[h][10]&&q[h][11]&&q[h][12]&&q[h][13]&&q[h][1])
			{
				t++;
				copy(h,t);
				for(int i=10;i<=13;i++)
				{
					q[t][i]--;
				}
				q[t][1]--;
			    if(win(t))
			    {
					cout<<step[t]<<"\n";
					vv=0;
					vvv=0;
					break;
				}
			}
			for(int i=3;i<=10;i++)
			{
				if(q[h][i]&&q[h][i+1]&&q[h][i+2]&&q[h][i+3]&&vv)
				{
					for(int j=i+4;j<=13;j++)
					{
						if(j==13&&q[h][1]&&q[h][j])
						{
							t++;
							copy(h,t);
							q[t][1]--;
							for(int k=i;k<=13;k++)
							{
								q[t][k]--;
							}
							if(win(t))
							{
								cout<<step[t]<<"\n";
								vv=0;
								vvv=0;
								break;
							}
						} 
						if(q[h][j])
						{
							t++;
							copy(h,t);
							for(int k=j;k>=i;k--)
							{
								q[t][k]--;
							}
							if(win(t))
							{
								cout<<step[t]<<"\n";
								vv=0;
								vvv=0;
								break;
							}
						}else
						{
							break;
						}
					}
				}
			}*/  //判断顺子
			/*if(q[h][14]&&q[h][15])
			{
				t++;
				copy(h,t);
				q[t][14]=0;
				q[t][15]=0;
				if(win(t))
				{
					cout<<step[t]<<"\n";
					vvv=0;
					break;
				}
			}else
			{
				if(q[h][14])
				{
					t++;copy(h,t);
				q[t][14]=0;
				if(win(t))
				{
					cout<<step[t]<<"\n";
					vvv=0;
					break;
				}
				}
				if(q[h][15])
				{
					t++;copy(h,t);
				q[t][15]=0;
				if(win(t))
				{
		     		cout<<step[t]<<"\n";
					vvv=0;
					break;
				}
				}
			}*/  //   大小王
			for(int i=1;i<=13;i++)
			{
				//cout<<q[h][i]<< " ";
				/*if(q[h][i]==4)
				{
					t++;
					copy(h,t);
					q[t][i]-=4;
					if(win(t))
		     		{
		     		cout<<step[t]<<"\n";
					vvv=0;
					break;
			    	}
					for(int j=1;j<=15;j++) 
					{
						if(q[h][j])
						{
							if(q[h][j]>1)
							{
								for(int l=j;l<=15;l++)
								{
									if(q[h][l])
									{
										t++;
										copy(h,t);
										q[t][i]-=4;
										q[t][j]-=1;
										q[t][l]-=1; 
										if(win(t))
				                        {
		                             		cout<<step[t]<<"\n";
		                        			vvv=0;
		                          			break;
		                        		}
									}
								}
							}else
							{
								for(int l=j+1;l<=15;l++)
								{
									if(q[h][l])
									{
										t++;
										copy(h,t);
										q[t][i]-=4;
										q[t][j]-=1;
										q[t][l]-=1; 
										if(win(t))
				                        {
		     	                         	cout<<step[t]<<"\n";
				                        	vvv=0;
					                        break;
		                           		}
									}
								}
							}
						}
					}
				}
				if(q[h][i]>=3)
				{
					t++;
					copy(h,t);
					q[t][i]=q[h][i]-3;
					if(win(t))
		     		{
		     		cout<<step[t]<<"\n";
					vvv=0;
					break;
			    	}
			    	for(int j=1;j<=15;j++)
			    	{
			    		if(q[h][j])
			    		{
			    			t++;
			    			copy(h,t);
			    			q[t][i]-=3;
			    			q[t][j]-=1;
			    			if(win(t))
		     		        {
		                		cout<<step[t]<<"\n";
			            		vvv=0;
			            		break;
			            	}
			    		}
			    		if(q[h][j]>=2)
			    		{
			    			t++;
			    			copy(h,t);
			    			q[t][i]-=3;
			    			q[t][j]-=2;
			    			if(win(t))
		     		        {
		                		cout<<step[t]<<"\n";
			            		vvv=0;
			            		break;
			            	}
			    		}
			    	}
				}*/
			  
			    if(q[h][i]>=2)
			    {
				    t++;
				    copy(h,t);
				    q[t][i]-=2;
				    if(win(t))
				    {
					    cout<<step[t]<<"\n";
					    vvv=0;
				    	break;
		    		}

		    	}
		    }
		    /*for(int i=3;i<=12;i++)
		    {
		    	if(q[h][i]>=2&&q[h][i+1]>=2)
		    	{
		    		for(int j=i+2;j<=13;j++)
		    		{
		    			if(j==13&&q[h][j]>=2&&q[h][1]>=2)
		    			{
		    				t++;
		    				copy(h,t);
							for(int k=i;k<=j;k++)
							{
								q[t][k]-=2;
							} 
							q[t][1]-=2;
							if(win(t))
							{
								cout<<step[t]<<"\n";
								vv=0;
								vvv=0;
								break;
							}
		    			}
		    			if(q[h][j]>=2)
		    			{
		    				t++;
		    				copy(h,t);
		    				for(int k=i;k<=j;k++)
		    				{
		    					q[t][k]-=2;
		    				}
		    				if(win(t))
							{
								cout<<step[t]<<"\n";
								vv=0;
								vvv=0;
								break;
							}
		    			}else
		    			{
		    				break;
		    			}
		    		}
		    	}
		    }*/
		    //
		    /*if(q[h][13]>=3&&q[h][1]>=3)
		    {
		    	t++;
		    	copy(h,t);
		    	q[t][13]-=3;
		    	q[t][1]-=3;
		    	if(win(t))
				{
		     		cout<<step[t]<<"\n";
					vvv=0;
					break;
				}
		    }
		    for(int i=3;i<=12;i++)
		    {
		    	if(q[h][i]>=3&&q[h][i+1]>=3)
		    	{
		    		for(int j=i+1;j<=13;j++)
		    		{
		    			if(j==13&&q[h][j]>=3&&q[h][1]>=3)
		    			{
		    				t++;
		    				copy(h,t);
							for(int k=i;k<=j;k++)
							{
								q[t][k]-=3;
							} 
							q[t][1]-=3;
							if(win(t))
							{
								cout<<step[t]<<"\n";
								vv=0;
								vvv=0;
								break;
							}
		    			}
		    			if(q[h][j]>=3)
		    			{
		    				t++;
		    				copy(h,t);
		    				for(int k=i;k<=j;k++)
		    				{
		    					q[t][k]-=3;
		    				}
		    				if(win(t))
							{
								cout<<step[t]<<"\n";
								vv=0;
								vvv=0;
								break;
							}
		    			}else
		    			{
		    				break;
		    			}
		    		}
		    	}
		    }*/
		    for(int i=1;i<=13;i++)
		    {
		    	if(q[h][i])
		    	{
		    		t++;
		    	    copy(h,t);
		    	    q[t][i]--;
		    	    if(win(t))
					{
						cout<<step[t]<<"\n";
						vv=0;
						vvv=0;
				    	break;
					}
		    	}
		    	
		    }
		}  
		//cout<<t;
	}
	

}

