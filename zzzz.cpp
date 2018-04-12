#include<stdio.h>
int arr[2001];
int top=0,n;//head 是一个变量，表示队首元素是哪个，tail就是队伍的小尾巴~  
int dez() //栈顶元素出队（最上面的盘子被拿走了） 
{
	top--; //top-1 ，再拿就要拿下面一个盘子了
	 
	return arr[top+1]; // 返回 最上面的盘子的编号 
}
void enz(int a) // 栈顶元素加一 （又来盘子了） 
{
	top++; // 盘子堆又高了 
	arr[top]=a;// 最上面的盘子就是新来的哪个 
}
int main()
{
	while(1) 
	{
	    scanf("%d",&n); // 读入一个数 n  
	    if(n==1) // 我们用1 表示 最上面的盘子被拿走了~ 
	    {
	    	printf("%d\n",dez());//输出 
	    }
	    if(n==2)// 我们用2 表示 又来了一个盘子
	    {
	    	scanf("%d",&n); //读入新来的盘子的编号 
	    	enz(n);//新盘子变为最上面~ 
	    }
	}
} 
