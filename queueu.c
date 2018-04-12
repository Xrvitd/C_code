#include<stdio.h>
int arr[2001];
int head=1,tail=0,n;//head 是一个变量，表示队首元素是哪个，tail就是队伍的小尾巴~  
int dequeue() //队首元素出队（买到饭啦，就要走咯） 
{
	head++; //head +1 ，下一个同学再来买饭 
	return arr[head-1]; // 返回 刚刚买到饭的同学的编号 
}
void enqueue(int a) // 队尾元素加一 （又来人排队买饭了） 
{
	tail++; // 小尾巴边长了，tail +1 
	arr[tail]=a;// 队伍的最后一名同学就是刚刚来买饭的 
}
int main()
{
	while(1) 
	{
	    scanf("%d",&n); // 读入一个数 n  
	    if(n==1) // 我们用1 表示 队首的同学买到饭 
	    { 
	    	printf("%d\n",dequeue());//输出买到饭的同学 
	    }
	    if(n==2)// 我们用2 表示 新来了同学要买饭 
	    {
	    	scanf("%d",&n); //读入新来的同学的编号 
	    	enqueue(n);//新同学变为小尾巴~ 
	    }
	}
} 
