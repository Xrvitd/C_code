#include <iostream>
#include<cstdlib> 
using namespace std;
 const int the_number = 333;
class p
{
	private:
		double num[the_number];
	public:
		p(){cout<<"对象实例化初始完毕，请输入内容，中间间隔为‘，’"<<endl;} ;
		double get_num(int i){
			return num[i];
		};
		void set_num(double _num,int n)
		{
			num[n]=_num;	
		};
	
};
int main() {

	cout<<"数字个数：";
	//cin>>the_number;
	p tong; 
	system("pause");
	return 0; 
}
