#include <stdio.h>
int main()
{
    int a[200000],i,j,t,n;
    for(i=0;i<200000;i++)
        a[i]=0;  //��ʼ��Ϊ0
    	scanf("%d",&n);          
    for(i=1;i<=n;i++)  //ѭ������5����
    {
        scanf("%d",&t);  //��ÿһ������������t��
        a[t]++;  //���м���
    }
    for(i=0;i<200000;i++)  //�����ж�a[0]~a[10]
        for(j=1;j<=a[i];j++)  //�����˼��ξʹ�ӡ����
            printf("%d ",i);
    getchar();getchar();
    //�����getchar();������ͣ�����Ա�鿴�������������
    //Ҳ������system("pause");��������
    return 0;
}
