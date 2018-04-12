#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define N 1000010
#define F fa[x][i-1]
using namespace std;
struct point{
    int v,next;
}edge[2*N];
int n,m,num=0,maxn,minn,ans;
int head[N],a[N],de[N],fa[N][20],ma[N][20],mi[N][20],cq[N][20],ch[N][20];
bool vis[N]={0};
int in(){
    int x=0; char ch=getchar();
    while (ch<'0' || ch>'9') ch=getchar();
    while (ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
    return x;
}
void add(int u,int v){
    edge[++num].v=v; edge[num].next=head[u]; head[u]=num;
}
int lca(int x,int y){
    if (de[x]<de[y]) swap(x,y);
    int k=de[x]-de[y];
    for (int i=0; i<=18; i++)
        if (k&(1<<i)) x=fa[x][i];
    for (int i=18; i>=0; i--)
        if (fa[x][i]!=fa[y][i])
            x=fa[x][i],y=fa[y][i];
    if (x==y) return x;
    return fa[x][0];
}
void dfs(int x){
    vis[x]=true;
    for (int i=1; i<=18; i++){
        if (de[x]<(1<<i)) break;
        fa[x][i]=fa[F][i-1];
        ma[x][i]=max(ma[x][i-1],ma[F][i-1]);
        mi[x][i]=min(mi[x][i-1],mi[F][i-1]);
        cq[x][i]=max(max(cq[x][i-1],cq[F][i-1]),ma[F][i-1]-mi[x][i-1]);
        ch[x][i]=max(max(ch[x][i-1],ch[F][i-1]),ma[x][i-1]-mi[F][i-1]);
    }
    for (int i=head[x]; i; i=edge[i].next){
        int v=edge[i].v;
        if (vis[v]) continue;
        fa[v][0]=x; de[v]=de[x]+1;
        ma[v][0]=max(a[x],a[v]); mi[v][0]=min(a[x],a[v]);
        cq[v][0]=a[x]-a[v]; ch[v][0]=a[v]-a[x];
        dfs(v);
    }
}
void work(int x,int y){
    maxn=0,minn=0x7fffffff,ans=0;
    int ff=lca(x,y),k;
//  cout<<x<<"  "<<y<<"  "<<ff<<"  "<<endl;
    k=de[x]-de[ff];
//  cout<<k<<endl;
    if (k>0){
        for (int i=0; i<=18; i++)
            if (k&(1<<i)){
                ans=max(ans,max(cq[x][i],ma[x][i]-minn));
                minn=min(minn,mi[x][i]); x=fa[x][i];
//              cout<<ans<<"   "<<minn<<endl;
            }
    }
    k=de[y]-de[ff];
//  cout<<k<<endl;
    if (k>0){
        for (int i=0; i<=18; i++)
            if (k&(1<<i)){
                ans=max(ans,max(ch[y][i],maxn-mi[y][i]));
                maxn=max(maxn,ma[y][i]); y=fa[y][i];
//              cout<<ans<<"   "<<maxn<<endl;
            }
    }
    ans=max(ans,maxn-minn);
}
int main(){
    n=in();
    for (int i=1; i<=n; i++) a[i]=in();
    for (int i=1; i<n; i++){
        int u=in(),v=in();
        add(u,v),add(v,u);
    }
    fa[1][0]=1; dfs(1);
    m=in();
    while (m--){
        int x=in(),y=in();
        work(x,y);
        printf("%d\n",ans);
    }
    return 0;
}
