栈
后进先出
int a[100001];
int top=0;
快速幂
对于a n 将N表示成二进制。 提取非零位、
int  fast_pow(int a,int p)
{
	int ans=1;
	for(;p;p>>=1,a=a*a)
	{
		if(p&1)
			
			{
				ans=ans*a;
			}
	}
	return ans;
}
RMQ
a[n]   f[i][j]   从第I个开始，2的J次方长度的最大值
预处理：
对J从小到大。处理F[I][J]时  F[I][0-J-1]已经处理好了。
f[i][j]=max(f[i][j-1],f[i+2 j-1 ][j-1]);
查询：
令K等于区间长度；
k=log2(j-i+1);
结果=  max(f[i][k],f[j-2(k)+1][k]);
或：
开头末尾分别取K长度
并查集：
int find(int x)//无路径压缩
{
	if(fa[x]==x) return x;
	else return find (fa[x]);
}
int find(int x)
{
	return (fa[x]==x)? x:fa[x]=find(fa[x]);
}
食物链：
规定根节点类型为0   
int gcd(int a,int b)
{
	if(!b)
}

扩展欧几里得
ax+by=gcd(a,b)
边界:
同余
(a + b) % n = ((a % n) + (b % n)) % n
(a – b) % n = ((a % n) – (b % n) + n) % n(可能有负数)
ab % n = (a % n)(b % n) % n
除法不行
剩余系：对于一个正整数n，一个整数集模n所得的余数域。
如模7剩余系包括7个数字：0，1，2，3，4，5，6。

费马小定理（有前提）    long long 
int quick_pow(int a, int b, int p)
{ 
int ans = 1; 
for (; b; a = (a * a) % p, b >>= 1) 
if (b & 1) 
ans = (ans * a) % p;
return ans;
}
两个数a,b的最小公倍数lcm等于a*b/gcd(a,b)

code::blocks 





















