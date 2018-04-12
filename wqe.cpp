#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
struct re 
{
   string s;
int old;
};
bool camp(struct re a,struct re b)
{
	if(a.old<b.old)
	{
		return 0;
	}
	return 1;
}

struct re a[100001];
int main()
{
	cin>>n>>m;
for(int i=1;i<=n;i++)
{
cin>>a[i].s;
}
for(int i=1;i<=n;i++)
{
cin>>a[i].old;
}
sort(a+1,a+n+1,camp);
for(int i=1;i<=m;i++)
{
	cout<<a[i].s<<" ";
}

}

