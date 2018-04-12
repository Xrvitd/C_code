#include"array.h"
int a[10]={0},b[11]={1,4,1,1,23,3,51,25,125,12,5},c[21];

int main(int argc, char** argv) {
	cout<<"a数组：";
	 print(a,sizeof(a));cout<<endl;
	 cout<<"b数组：";
	 print(b,sizeof(b));cout<<endl;
	memset1(a,2,sizeof(a));
	cout<<"a数组初始化为2.\na: "; 
	print(a,sizeof(a));cout<<endl;
	cout<<"将a,b合并，存入c中：\nc数组:";
	hebing(a,sizeof(a),b,sizeof(b),c);
	print(c,sizeof(c));
	cout<<endl;
	cout<<"寻找B数组中23的位置："; 
	cout<<find(b,sizeof(b),23);cout<<endl;
	cout<<"删除b数组中所有的1，其余用-1补齐。\nb数组:";
	delete1(b,sizeof(b),1);
	print(b,sizeof(b));
	return 0;
}
