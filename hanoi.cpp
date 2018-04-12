#include<iostream>
using namespace std;
int n,m,s=0;
void f1(char c1,char c2,int n,char c3)
{
	if(n==0) return;
	s++;
	f1(c1,c3,n-1,c2);
	//cout<<n<<" from "<<c1<<" to "<<c3<<endl;
	f1(c2,c1,n-1,c3);
}
void f(char c1,char c2,int n,char c3)
{
	if(n==0) return;
	f(c1,c3,n-1,c2);
	cout<<n<<" from "<<c1<<" to "<<c3<<endl;
	f(c2,c1,n-1,c3);
}
int main()
{
	cin>>n;
	f1('A','B',n,'C');
	cout<<s<<endl;
	f('A','B',n,'C');
	return 0;
}
