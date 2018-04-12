#include<iostream>
using namespace std;
int n,m,a[100001]={0},h;
int main()

{
	h=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>m;
		if(m==1)
		{
			h++;
			cin>>a[h];
		}
		if(m==2)
		{
			if(!h)
			{
				cout<<"impossible!";return 0;
			}
			h--;
		}
		if(m==3)
		{
			cout<<a[h]<<endl;
		}
	}

}
