#include<iostream>
#include<algorithm>
#include<map> 
using namespace std;
int n,m,yk=0,fk=0;
char y[200],f[200],z[200];
bool v[500]={0},vv[2333334]={0};
	char a[200];
int zh()
{
	int kk=0;
	for(int i=1;i<=n;i++)
	{
		kk+=(int )a[i];
		kk*=1000;
		kk=kk%2333333; 
	}
	return kk%2333333;
} 
int dfs(int s)
{
	if(s==n+1)
	{
		sort(a+1,a+n+1);
	    if(!vv[zh()])
	    {
	    	for(int i=1;i<=n;i++)
	    	{
	    		cout<<a[i];
	    	}
	    	cout<<"\n";
	    	vv[zh()]=1;
	    }
		
		return 0;
	} 
	for(int i=1;i<=m;i++)
	{
		if(!v[z[i]])
		{
			v[z[i]]=1;
			a[s]=z[i];
			//cout<<z[i]<< " "; 
			dfs(s+1);
			v[z[i]]=0;
		}
	}
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		char c;
		cin>>c;
		z[i]=c;
		if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
		{
			yk++;
			y[yk]=c;
		}else
		{
			fk++;
			f[fk]=c;
		}
	}
	sort(z+1,z+1+m);
	sort(y+1,y+yk+1);
	sort(f+1,f+fk+1);
	/*for(int i=1;i<=fk;i++)
	{
		cout<<f[i]<< " ";
	}
	cout<<"=================================================================";*/
	for(int i=1;i<=yk;i++)
	{
		v[y[i]]=1;
		a[1]=y[i];
		cout<<y[i]<< " ";
		for(int j=1;j<=fk;j++)
		{
			v[f[j]]=1;
			a[2]=f[j];
			cout<<f[j]<< " ";
			for(int l=j+1;l<=fk;l++)
			{
				v[f[l]]=1;
				a[3]=f[l];
				cout<<f[l]<< " \n";
		
				//dfs(4);
				
				v[f[l]]=0;
			}
			v[f[j]]=0;
		}
		v[y[i]]=0;
	}
} 
