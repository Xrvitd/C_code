#include<iostream>
using namespace std;
int f[45];
int main(){
	f[0]=1;
	f[1]=1;
	for(int i=2;i<40;i++){
		f[i]=f[i-1]+f[i-2];
		cout<<f[i]<<" ";
	}
	return 0;
}
