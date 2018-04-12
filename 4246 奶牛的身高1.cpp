#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int f[10100],d[10001];
int find(int x)
  {
  	if(f[x]==x) return x;
	long long  k=find(f[x]);
	d[x]=d[x]+d[f[x]];
	f[x]=k;
	return f[x];
  }
int main()
  {
  	int qqq,n,m;
  	cin>>qqq;
  	int q,w,e;
  	long long  qq,ww;
  	while (qqq--)
  	  {
  	  	bool v=1;
  	  	cin>>n>>m;
  	  	for (int i=1;i<=n;i++)
  	  	  f[i]=i;
  	  	for (int i=1;i<=m;i++)
  	  	  {
  	  	  	scanf("%d%d%d",&q,&w,&e);
  	  	  	
			qq=find(q);
			ww=find(w);
			if(qq!=ww)
			{
				f[qq]=ww;
				d[qq]=d[w]-d[q]+e;
			}else
			{
				if(d[q]-d[w]!=e)
				{
					v=0;
					break;
				}    
			}
		  }
		/*for (int i=1;i<=n;i++)
		  cout<<i<<' '<<find(i)<<' '<<fa[i][1]<<endl;*/
		if(!v)
		{
			cout<<"Bessie is blind.\n";
		}else   
		{
			cout<<"Bessie's eyes are good\n";
		}  
	  }
  }

