#include <stdio.h>
#include <stdlib.h>
# include <time.h>
int a[100001],n;//����ȫ�ֱ�����������������Ҫ���Ӻ�����ʹ��
void quicksort(int left,int right)
{
    int i,j,t,temp;
    if(left>right)
       return;

    temp=a[left]; //temp�д�ľ��ǻ�׼��
    i=left;
    j=right;
    while(i!=j)
    {
                   //˳�����Ҫ��Ҫ�ȴ��ұ߿�ʼ��
                   while(a[j]>=temp && i<j)
                            j--;
                   //�����ұߵ�
                   while(a[i]<=temp && i<j)
                            i++;
                   //�����������������е�λ��
                   if(i<j)
                   {
                            t=a[i];
                            a[i]=a[j];
                            a[j]=t;
                   }
    }
    //���ս���׼����λ
    a[left]=a[i];
    a[i]=temp;

    quicksort(left,i-1);//����������ߵģ�������һ���ݹ�Ĺ���
    quicksort(i+1,right);//���������ұߵ� ��������һ���ݹ�Ĺ���
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

