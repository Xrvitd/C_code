#include<iostream>
using namespace std;
int stack[100005],top=-1;
bool exec=true;
void push(int x){
	top++;
	stack[top]=x;
}
void pop(){
	if(top>-1){
		top--;
//		return stack[top+1];
	}
	else {
		cout<<"impossible!"<<endl;
		exec=false;
		return;
	}
}
int a,tmp;
int main(){
	cin>>a;
	for(int i=1;i<=a;i++){
		if(!exec) return 0;
		cin>>tmp;
		if(tmp==1){
			cin>>tmp;
			push(tmp);
			tmp=0;
		}
		if(tmp==2){
			pop();
			tmp=0;
		}
	}
	if(top>=0) cout<<stack[top];
	else cout<<"impossible!"<<endl;
	return 0;
}
