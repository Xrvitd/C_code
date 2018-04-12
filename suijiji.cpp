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
	/*让系统取随机数*/
	printf("%d\n",cai);
	cishu++;
	if(cai!=shu){
	/*第一次验证*/
		for(;;){
			getchar();
			scanf("%c",&daxiao);
			/*取消回车，读取输入字符*/
			if(daxiao=='a'){
				max=cai;
				cai=(min+cai)/2;
				cishu++;
				if(cai==shu) break;
				/*猜数正确才跳出循环*/
			}
			if(daxiao=='b'){
				min=cai;
				cai=(max+cai)/2;
				cishu++;
				if(cai==shu) break;
			}
			/*循环采取二分法缩小范围*/
			printf("%d\n",cai);
			/*输出每次猜测值*/
		}
	}
	printf("猜对了！共用%d步",cishu);
	/*输出统计的次数*/
	return 0;
}

