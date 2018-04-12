#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXO=100010;
struct RE
  {
  	int from,to,l,next,pos,key;
  }bian1[MAXO]={0},bian2[MAXO]={0};
int top=0;
int last[MAXO]={0};
struct RR
  {
  	int fa,v,h;
  }dian[MAXO]={0};
  
int father[MAXO];
bool vis[MAXO]={0},f[MAXO]={0};
int find(int a)
  {
  	return father[a]==a?a:father[a]=find(father[a]);
  }
void add(int a,int b,int c)
  {
  	top++;
  	bian2[top].from=a;
  	bian2[top].to=b;
  	bian2[top].l=c;
  	bian2[top].next=last[a];
  	last[a]=top;
  	bian2[top].key=top%2==0?top/2:(top+1)/2;
  }
bool cmp(RE a,RE b)
  {
  	return a.l>b.l;
  }
int n,m,q,mino;
void dfs(int d,int h)
  {
    dian[d].h=h;
    vis[d]=1;
  	for (int i=last[d];i;i=bian2[i].next)
  	  {
		int e=bian2[i].to;
  	  	if (f[bian2[i].key]&&!vis[e])
  	  	  {
  	  	  	dian[e].fa=d;
  	  	  	dian[e].v=bian2[i].l;
  	  	  	dfs(e,h+1);
		  }
	  }
  }
void jump(int &d,int h)
  {
  	for (int i=1;i<=h;i++) mino=min(dian[d].v,mino),d=dian[d].fa;
  }
int main()
  {
  	cin>>n>>m;
  	for (int i=1;i<=m;i++) 
	  {
	  	scanf("%d%d%d",&bian1[i].from,&bian1[i].to,&bian1[i].l);
	  	bian1[i].pos=i;
	  	add(bian1[i].from,bian1[i].to,bian1[i].l);
	  	add(bian1[i].to,bian1[i].from,bian1[i].l);
	  }
  	sort(bian1+1,bian1+m+1,cmp);
  	for (int i=1;i<=n;i++) father[i]=i,dian[i].fa=i;
  	int num=0;
  	for (int i=1;i<=m;i++)
  	  {
  	  	int a=bian1[i].from,b=bian1[i].to;
  	  	if (find(a)!=find(b)) father[find(a)]=find(b),num++,f[bian1[i].pos]=1;
  	  	if (num==n-1) break;
	  }
	for (int i=1;i<=n;i++)
	  if (!vis[i])
	    dfs(1,1); 
	cin>>q;
	int a,b;
	while (q--)
	  {
	  	scanf("%d%d",&a,&b);
	  	mino=MAXO;
	  	if (find(a)!=find(b)) cout<<"-1\n";
	  	else 
	  	  {
	  	  	if (dian[a].h<dian[b].h) jump(b,dian[b].h-dian[a].h);
	  	  	else jump(a,dian[a].h-dian[b].h);
	  	  	while (a!=b)
	  	  	  {
	  	  	  	mino=min(dian[a].v,mino);
	  	  	  	mino=min(dian[b].v,mino);
	  	  	  	a=dian[a].fa;
	  	  	  	b=dian[b].fa;
			  }
			printf("%d\n",mino);
		  }
	  }
	return 0;
  } 
