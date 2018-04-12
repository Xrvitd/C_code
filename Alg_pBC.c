#include<stdio.h>
#include<string.h>

int l[10010], r[10010];
int next[10010];

void swap(int *a ,int *b )
{
	int t;
	
	t=*a;
	*a=*b;
	*b=t;
	
	return ; 
}

void qsort(int l, int r , int *a, int *b)  //a[]为关键字 
{
	int x;
	int i,j;
	
	j=l-1;
	x=a[r];
	for (i=l;i<r;i++)
	if (x>a[i])
	{
		j++;
		swap(a+j,a+i);
		swap(b+j,b+i);
	}
	
	j++;
	swap(a+j,a+r);
	swap(b+j,b+r);
	
	if (j+1<r) qsort(j+1,r,a,b);
	if (j-1>l) qsort(l,j-1,a,b);
}
void main(void)
{
	int n,head,i;
	
	while (scanf("%d",&n)!=EOF)
	{
		l[0]=0;
		r[0]=0;
		for (i=1;i<=n;i++)
		{
			scanf("%d",l+i);
			scanf("%d",r+i);
			if (l[i]>=r[i]) swap(l+i,r+i);
		}
		
		qsort(1,n,r,l);
		
		head=1;
		for (i=1;i<n;i++) next[i]=i+1;   //数组模拟链表 
		next[n]=0;
		next[0]=0;
		
		int ans=0;
		while (head)                    //当还有线段，就循环 
		{
			ans++;                      //记录覆盖次数 
			
			int tkn=r[head];
	        int t=head;
	        
	        while (t)                    //线段覆盖 
	        {
	        	while (l[next[t]]>tkn)
	        	{
	        		tkn=r[next[t]];
	        		next[t]=next[next[t]];
	        	}
	        	
	        	t=next[t];
	        }
	        
	        head=next[head];
		}
		
		printf("%d\n",ans);
	} 

	return ;
}

