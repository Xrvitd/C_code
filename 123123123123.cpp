#include <iostream>
#include<cstdlib> 
using namespace std;
 const int the_number = 333;
class p
{
	private:
		double num[the_number];
	public:
		p(){cout<<"����ʵ������ʼ��ϣ����������ݣ��м���Ϊ������"<<endl;} ;
		double get_num(int i){
			return num[i];
		};
		void set_num(double _num,int n)
		{
			num[n]=_num;	
		};
	
};
int main() {

	cout<<"���ָ�����";
	//cin>>the_number;
	p tong; 
	system("pause");
	return 0; 
}
