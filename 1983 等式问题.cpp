#include<iostream>
#include<cstdio>
using namespace std;
int n,m,ansa=0;
char s[100];
int fs(int x1,int x2,int x3,int x4,int x5,int x6,int x7,int x8)
{
    
	int k=1;
	s[k]='1';
	if(x1==1) { k++;s[k]='+';	} if(x1==2) { k++;s[k]='-';	}
	k++; s[k]='2'; if(x2==1) { k++;s[k]='+';	} if(x2==2) { k++;s[k]='-';	}
	k++; s[k]='3'; if(x3==1) { k++;s[k]='+';	} if(x3==2) { k++;s[k]='-';	} 
	k++; s[k]='4'; if(x4==1) { k++;s[k]='+';	} if(x4==2) { k++;s[k]='-';	}
	k++; s[k]='5'; if(x5==1) { k++;s[k]='+';	} if(x5==2) { k++;s[k]='-';	}
	k++; s[k]='6'; if(x6==1) { k++;s[k]='+';	} if(x6==2) { k++;s[k]='-';	}
	k++; s[k]='7'; if(x7==1) { k++;s[k]='+';	} if(x7==2) { k++;s[k]='-';	}
	k++; s[k]='8'; if(x8==1) { k++;s[k]='+';	} if(x8==2) { k++;s[k]='-';	}
	k++; s[k]='9'; 
	return k;
}
int js(int ss)
{
	int i=1,l=1,ans=0,f=1;
	while(i<=ss+1)
	{
		i++;
		if(s[i]=='-'||s[i]=='+'||i==ss+1)
		{
			int an=s[l]-'0';
			for(int j=l+1;j<i;j++)
			{
				an*=10;
				an+=s[j]-'0';
			}
			if(f)
			{
				ans+=an;
			}else
			{
				ans-=an;
			}
			if(s[i]=='-') f=0;else f=1;
			l=i+1;
		}
	}
	return ans;
}
int main()
{
	cin>>n;
	/*for(int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	cout<<js(n);*/
	
	for(int i=1;i<=3;i++)
	{
		for(int j=1;j<=3;j++)
		{
			for(int kk=1;kk<=3;kk++)
			{
				for(int l=1;l<=3;l++)
				{
					for(int q=1;q<=3;q++)
					{
						for(int w=1;w<=3;w++)
						{
							for(int e=1;e<=3;e++)
							{
								for(int r=1;r<=3;r++)
								{
									int k=fs(i,j,kk,l,q,w,e,r);
									if(n==js(k))
									{
										ansa++;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	cout<<ansa;
} 
