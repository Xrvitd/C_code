#include<stdio.h>
#define maxn 10010
int n,m,ans=0;
int map[maxn][maxn];
int count[maxn]={0};
void topsort()
{
	int i,t;
	int stack[maxn],top=-1;
	for(i=1;i<=n;i++)
	    if(count[i]==0)
	    stack[++top]=i;
    while(top>-1)                       //ջ�ǿս���ѭ��
    {
    	t=stack[top--];
    	ans++;
    	for(i=1;i<=n;i++)
    	    if(map[t][i]&&--count[i]==0)//���¸õ�����ȣ���Ϊ0����ջ
    	    {
    	    	stack[++top]=i;
    	    }
    }
}

int main()
{
	scanf("%d%d",&n,&m);
	int i,a,b;
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&a,&b);
		map[a][b]=1;    
		count[b]++;	//�������
	}
	topsort();
	if(ans<n)printf("T_T\n%d",n-ans);
	else printf("o(��_��)o");
	return 0;
}
