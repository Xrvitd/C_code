#include"array.h"
int a[10]={0},b[11]={1,4,1,1,23,3,51,25,125,12,5},c[21];

int main(int argc, char** argv) {
	cout<<"a���飺";
	 print(a,sizeof(a));cout<<endl;
	 cout<<"b���飺";
	 print(b,sizeof(b));cout<<endl;
	memset1(a,2,sizeof(a));
	cout<<"a�����ʼ��Ϊ2.\na: "; 
	print(a,sizeof(a));cout<<endl;
	cout<<"��a,b�ϲ�������c�У�\nc����:";
	hebing(a,sizeof(a),b,sizeof(b),c);
	print(c,sizeof(c));
	cout<<endl;
	cout<<"Ѱ��B������23��λ�ã�"; 
	cout<<find(b,sizeof(b),23);cout<<endl;
	cout<<"ɾ��b���������е�1��������-1���롣\nb����:";
	delete1(b,sizeof(b),1);
	print(b,sizeof(b));
	return 0;
}
