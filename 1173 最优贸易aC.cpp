#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
struct RE
  {
  	int to,next;
  }bian1[500010],bian2[500010];
int num=0,last1[100010]={0},last2[100010]={0};
int mn[100010],mx[100010];
int dui[1000010];
bool vis[100010];
int n,m,w[100010];
void add1(int a,int b)
  {
  	num++;
  	bian1[num].to=b;
  	bian1[num].next=last1[a];
  	last1[a]=num;
  }
void add2(int a,int b)
  {
  	bian2[num].to=b;
  	bian2[num].next=last2[a];
  	last2[a]=num;
  }
void spfa1()
  {
  	memset(vis,0,sizeof(vis));
  	memset(mn,127/2,sizeof(mn));
  	mn[1]=w[1];dui[1]=1;vis[1]=1;
  	int head=1,tail=1,x,y,i,j;
  	while (head<=tail)
  	  {
  	  	x=dui[head];
  	  	head++;
  	  	for (i=last1[x];i;i=bian1[i].next)
  	  	  {
  	  	  	y=bian1[i].to;
  	  	  	if (w[y]<mn[y]||mn[x]<mn[y])
  	  	  	  {
  	  	  	  	mn[y]=min(w[y],mn[x]);
  	  	  	  	if (!vis[y])
  	  	  	  	  {
  	  	  	  	  	vis[y]=1;
  	  	  	  	  	dui[++tail]=y;
				  }
			  }
		  }
		vis[x]=0;
	  }
  }
void spfa2()
  {
  	memset(vis,0,sizeof(vis));
  	memset(mx,0,sizeof(mx));
  	mx[n]=w[n];dui[1]=n;vis[n]=1;
  	int head=1,tail=1,x,y,i,j;
  	while (head<=tail)
  	  {
  	  	x=dui[head];
  	  	head++;
  	  	for (i=last2[x];i;i=bian2[i].next)
  	  	  {
  	  	  	y=bian2[i].to;
  	  	  	if (w[y]>mx[y]||mx[x]>mx[y])
  	  	  	  {
  	  	  	  	mx[y]=max(w[y],mx[x]);
  	  	  	  	if (!vis[y])
  	  	  	  	  {
  	  	  	  	  	vis[y]=1;
  	  	  	  	  	dui[++tail]=y;
				  }
			  }
		  }
		vis[x]=0;
	  }
  }
int main()
  {
  	scanf("%d%d",&n,&m);
  	int i,j,a,b,c;
  	for (i=1;i<=n;i++) scanf("%d",&w[i]);
  	for (i=1;i<=m;i++)
  	  {
  	  	scanf("%d%d%d",&a,&b,&c);
  	  	add1(a,b);
  	  	add2(b,a);
  	  	if (c==2)
  	  	  {
  	  	  	add1(b,a);
  	  	  	add2(a,b);
		  }
	  }
	spfa1();spfa2();
	int ans=0;
	for (i=1;i<=n;i++)
	  ans=max(mx[i]-mn[i],ans);
    printf("%d",ans);
    return 0;
  }

