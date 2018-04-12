#include <stdio.h>
#include <stdlib.h>
# include <time.h>
int a[100001],n;//定义全局变量，这两个变量需要在子函数中使用
void quicksort(int left,int right)
{
    int i,j,t,temp;
    if(left>right)
       return;

    temp=a[left]; //temp中存的就是基准数
    i=left;
    j=right;
    while(i!=j)
    {
                   //顺序很重要，要先从右边开始找
                   while(a[j]>=temp && i<j)
                            j--;
                   //再找右边的
                   while(a[i]<=temp && i<j)
                            i++;
                   //交换两个数在数组中的位置
                   if(i<j)
                   {
                            t=a[i];
                            a[i]=a[j];
                            a[j]=t;
                   }
    }
    //最终将基准数归位
    a[left]=a[i];
    a[i]=temp;

    quicksort(left,i-1);//继续处理左边的，这里是一个递归的过程
    quicksort(i+1,right);//继续处理右边的 ，这里是一个递归的过程
}
int main()
{

    int x,i;

    srand(1); 
    for (x=1; x<=10; x++)
            {a[x]=rand();
             printf("%d ",a[x]); }
    printf("\n");



    quicksort(1,10);

    for(i=1;i<=10;i++)
    {printf("%d ",a[i]);}
    return 0;
}

