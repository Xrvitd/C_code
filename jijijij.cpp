#include <stdio.h>
int main(){
	int a[10];
	int i;
	int x,y,z;
	for(i=0;i<10;i++){
		scanf("%d",&a[i]);
	}
	/*遍历数组赋值*/
	for(x=0;x<10;x++){
		for(y=x+1;y<10;y++){
			for(z=0;z<10;z++){
				if(a[x]+a[y]==a[z])
				printf("%d+%d=%d\n",a[x],a[y],a[z]);
				/*利用三重循环求符合条件*/
			}
		}
	}
	return 0;
}

