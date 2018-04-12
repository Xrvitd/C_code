#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;
int t,n,ha,ti;
struct re
{
    int x,h;
    
};
struct re a[24],q[100001][24];
int s[10001]={0};
bool  dui[54]={0};
bool  san[54]={0};
int step[100001]={0};
void copy(int ii,int jj)
{
    for(int i=1;i<=n;i++)
    {
        q[ii][i].x=q[jj][i].x;
        q[ii][i].h=q[jj][i].h;
    }
}
bool camp(struct re xx,struct re y)
{
    if(xx.x>y.x) return 0;
    return 1;
}
int shun(struct re p[24])
{
    int f[24]={0},c;
    for(int i=1;i<=n;i++)
    {
        f[i]=1;
    }
    c=1;

    for(int i=2;i<=n;i++)
    {
        if(p[i].x==0||p[i].x==2||p[i].x==1)
        {
            continue;
        }
        if(p[i].x-1==p[i-1].x)
        {
            int ll=f[i];
            f[i]=max(f[i],f[i-1]+1);
            if(f[i]==ll)
            {
                c=i;
            }
        }
        else
        {
            c=i;
            f[i]=f[i-1];
        }
        
    }
    return c;
}
int shun1(struct re p[24])
{
    int f[24]={0},c;
    for(int i=1;i<=n;i++)
    {
        f[i]=1;
    }
    for(int i=2;i<=n;i++)
    {
        if(p[i].x==0||p[i].x==2||p[i].x==1)
        {
            continue;
        }
        if(p[i].x-1==p[i-1].x||(p[i-1].x==13&&p[i].x==1))
        {
            int ll=f[i];
            f[i]=max(f[i],f[i-1]+1);
        }
        else
        {
            f[i]=f[i-1];
        }
        
        
    }
    return f[n];
}
bool win(int x)
{
    if(s[x]==0)
    {
        return 1;
        
    }
    return 0;
}
int main()
{
    cin>>t>>n;
    for(int ii=1;ii<=t;ii++)
    {
        memset(dui,0,sizeof(dui));
        memset(s,0,sizeof(s));
        memset(step,0,sizeof(step));
        for(int i=1;i<=n;i++)
        {
            cin>>a[i].x>>a[i].h;
        }
        ha=0;ti=1;
        sort(a+1,a+1+n,camp);
        for(int i=1;i<=n;i++)
         {
        q[1][i].x=a[i].x;
        q[1][i].h=a[i].h;
        }
        s[1]=n;
        step[1]=0;
        bool kk=0;
        
        while(ha<=ti)
        {
            ha++;
            
            if(kk)
            {
                break;
            }
            //cout<<s[ha]<<" ";
            int sh[14]={0};
            for(int i=1;i<=s[ha];i++)
            {
                sh[q[ha][i].x]++;
            }
            for(int i=1;i<=s[ha];i++)
            {
                if(sh[i]==2)
                {
                    dui[i]=1;
                }
            }
            if(shun1(q[ha])>=5)
            {
                ti++;step[ti]=step[ha]+1;
                copy(ti,ha);
                s[ti]=s[ha];
                
                for(int i=shun(q[ha]);i<shun(q[ha])+shun1(q[ha]);i++)
                {
                    q[ti][i].x=15;
                    q[ti][i].h=5;
                }
                s[ti]-=shun1(q[ha]);
                sort(q[ti]+1,q[ti]+1+s[ti],camp);
                if(win(ti))
                {
                    cout<<step[ti];
                    kk=1;break;
                }
            }
            for(int i=1;i<=13;i++)
            {
                if(sh[i]==4)
                {
                    ti++;step[ti]=step[ha]+1;
                    copy(ti,ha);
                    s[ti]=s[ha];
                    for(int j=1;j<=s[ha];j++)
                    {
                        if(q[ha][j].x==i)
                        {
                            q[ti][j].x=15;
                            q[ti][j].h=5;
                        }
                    }
                    s[ti]-=4;
                    sort(q[ti]+1,q[ti]+1+s[ti],camp);
                    if(win(ti))
                {
                    cout<<step[ti];
                    kk=1;break;
                }
                if(s[ha]>=6)
                    for(int k=1;k<=s[ha];k++)
                    {
                        if(sh[q[ha][k].x]>=3)
                        continue;
                        for(int o=1;o<=s[ha];o++)
                        {
                            if(sh[q[ha][o].x]>=3)
                            continue;
                            ti++;step[ti]=step[ha]+1;
                            copy(ti,ha);
                            s[ti]=s[ha];
                    for(int j=1;j<=s[ha];j++)
                    {
                        if(q[ha][j].x==i)
                        {
                            q[ti][j].x=15;
                            q[ti][j].h=5;
                        }
                    }
                    q[ti][k].x=15;
                            q[ti][k].h=5;q[ti][o].x=15;
                            q[ti][o].h=5;
                    s[ti]-=6;
                    sort(q[ti]+1,q[ti]+1+s[ti],camp);
                    if(win(ti))
                {
                    cout<<step[ti];
                    kk=1;break;
                }
                        }
                    }
                }
                if(sh[i]==3&&s[ha]>3)
                {
                    for(int j=1;j<=s[ha];j++)
                    {
                        if(sh[q[ha][j].x]==2&&s[ha]>5)
                        {
                        ti++;
                        step[ti]=step[ha]+1;
                        copy(ti,ha);
                        s[ti]=s[ha];
                    for(int ji=1;ji<=s[ha];j++)
                    {
                        if(q[ha][ji].x==i)
                        {
                            q[ti][ji].x=15;
                            q[ti][ji].h=5;
                        }
                    }
                    int xxx=q[ti][j].x;
                    q[ti][j].x=15;
                    q[ti][j].h=5;
                    for(int k=1;k<=s[ha];k++)
                    {
                        if(sh[q[ha][k].x]==xxx)
                        {
                            q[ti][k].x=15;
                    q[ti][k].h=5;
                        }
                    }
                    s[ti]-=5;
                    sort(q[ti]+1,q[ti]+1+s[ti],camp);
                    if(win(ti))
                {
                    cout<<step[ti];
                    kk=1;break;break;
                }    
                        }
                        if(sh[j]>=3)
                        continue;
                    ti++;
                    step[ti]=step[ha]+1;
                    copy(ti,ha);
                    s[ti]=s[ha];
                    for(int jj=1;jj<=s[ha];jj++)
                    {
                        if(q[ha][jj].x==i)
                        {
                            q[ti][jj].x=15;
                            q[ti][jj].h=5;
                        }
                    }
                    q[ti][j].x=15;
                    q[ti][j].h=5;
                    s[ti]-=4;
                    sort(q[ti]+1,q[ti]+1+s[ti],camp);
                    if(win(ti))
                {
                    cout<<step[ti];
                    kk=1;break;
                }
                        
                    }
                }
                if(sh[i]==2)
                {
                    ti++;step[ti]=step[ha]+1;
                    copy(ti,ha);
                    s[ti]=s[ha];
                    int xx=i;
                    for(int j=1;j<=s[ha];j++)
                    {
                        if(q[ha][j].x==i)
                        {
                            q[ti][j].x=15;
                            q[ti][j].h=5;
                        }
                    }
                    s[ti]-=2;
                    if(dui[xx-1])
                    step[ti]--;
                    sort(q[ti]+1,q[ti]+1+s[ti],camp);
                    if(win(ti))
                {
                    cout<<step[ti];
                    kk=1;break;
                }
                }
            }
            int wa=0,ax,bx;
            for(int i=1;i<=s[ha];i++)
            {
                if(q[ha][i].x==0)
                {
                    ti++;
                    step[ti]=step[ha]+1;
                    copy(ti,ha);
                    s[ti]=s[ha];
                    if(wa==0)
                    {
                        ax=i;
                    }else
                    {
                        bx=i;
                    }
                            q[ti][i].x=15;
                            q[ti][i].h=5;
                    
                    
                    s[ti]-=1;
                    
                    sort(q[ti]+1,q[ti]+1+s[ti],camp);
                    if(win(ti))
                {
                    cout<<step[ti];
                    kk=1;break;
                }
                wa++;
                }
            }
            if(wa==2)
            {
                    ti++;
                    step[ti]=step[ha]+1;
                    copy(ti,ha);
                    s[ti]=s[ha];
                    q[ti][ax].x=15;
                    q[ti][ax].h=5;
                    q[ti][bx].x=15;
                    q[ti][bx].h=5;
                    s[ti]-=2;
                    sort(q[ti]+1,q[ti]+1+s[ti],camp);
                    
                    if(win(ti))
                    {
                    cout<<step[ti];
                    kk=1;break;
                    }
            }
            for(int i=1;i<=s[ha];i++)
            {
                    ti++;
                    step[ti]=step[ha]+1;
                    copy(ti,ha);
                    s[ti]=s[ha];
                    q[ti][i].x=15;
                    q[ti][i].h=5;
                    s[ti]-=1;
                    sort(q[ti]+1,q[ti]+1+s[ti],camp);
                    if(win(ti))
                    {
                    cout<<step[ti];
                    kk=1;break;
                    }
            }
        }
        cout<<endl;
    }

    return 0;
}
