#include <stdio.h>
#include <time.h> 
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cstdlib>
#include<string>
#include<bitset>
#include<iomanip>
#include<deque>
int main()
{
	int shu;
	int cai;
	int cishu=0;
	char daxiao;
	int min=1000,max=9999;
	scanf("%d",&shu);
	srand((unsigned int)time(NULL));
	cai=rand()%9000+1000;
	/*��ϵͳȡ�����*/
	printf("%d\n",cai);
	cishu++;
	if(cai!=shu){
	/*��һ����֤*/
		for(;;){
			getchar();
			scanf("%c",&daxiao);
			/*ȡ���س�����ȡ�����ַ�*/
			if(daxiao=='a'){
				max=cai;
				cai=(min+cai)/2;
				cishu++;
				if(cai==shu) break;
				/*������ȷ������ѭ��*/
			}
			if(daxiao=='b'){
				min=cai;
				cai=(max+cai)/2;
				cishu++;
				if(cai==shu) break;
			}
			/*ѭ����ȡ���ַ���С��Χ*/
			printf("%d\n",cai);
			/*���ÿ�β²�ֵ*/
		}
	}
	printf("�¶��ˣ�����%d��",cishu);
	/*���ͳ�ƵĴ���*/
	return 0;
}

