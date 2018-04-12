#include <iostream>  
#include <cstring>  
#include <cstdio>  
#include <cstdlib>  
using namespace std;  
  
#define MAXN 10010  
#define MAXM 100010  
  
struct Edge  
{  
      int v, next;    
}edge[MAXM];    //�߽������   
  
int first[MAXN], stack[MAXN], DFN[MAXN], Low[MAXN], Belong[MAXM];  
// first[]ͷ�������,stack[]Ϊջ,DFN[]Ϊ���Ѵ������飬Belong[]Ϊÿ���������Ӧ��ǿ��ͨ�����������   
// Low[u]Ϊu������u�������������׷�ݵ�������ջ�н��Ĵ����   
int instack[10010];  // instack[]Ϊ�Ƿ���ջ�еı������   
int n, m, cnt, scnt, top, tot;  
  
void init()  
{  
    cnt = 0;  
    scnt = top = tot = 0;    //��ʼ����ͨ������ţ������������ջ��ָ��Ϊ0   
    memset(first, -1, sizeof(first));  
    memset(DFN, 0, sizeof(DFN));   //��������Ĵ���������Ϊ0��ͬʱ���Ե��Ƿ���ʵ�����ʹ��   
}  
  
void read_graph(int u, int v) //�����ڽӱ�   
{  
     edge[tot].v = v;  
     edge[tot].next = first[u];  
     first[u] = tot++;  
}  
  
void Tarjan(int v)       //Tarjan�㷨������ͼ��ǿ��ͨ����   
{  
     int min, t;  
     DFN[v] = Low[v] = ++tot;    //cntΪʱ���  
     instack[v] = 1;    //�����ջ��   
     stack[top++] = v;      //��ջ   
     for(int e = first[v]; e != -1; e = edge[e].next)  
     {   //ö��v��ÿһ����   
           int j = edge[e].v;   //v���ڽӵı�   
           if(!DFN[j])  
           {   //δ������   
               Tarjan(j);    //����������   
               if(Low[v] > Low[j]) Low[v] = Low[j];  // ���½��v���ܵ������С������   
           }  
           else if(instack[j] && DFN[j] < Low[v])  
           {   //���j�����ջ��,   
               Low[v] = DFN[j];  
           }  
     }  
     if(DFN[v] == Low[v])  
     {     //����ڵ�v��ǿ��ͨ�����ĸ�   
           scnt++;   //��ͨ������ż�1   
           do  
           {  
               t = stack[--top];   //��ջ   
               instack[t] = 0;   //��ǲ���ջ��   
               Belong[t] = scnt;   //��ջ���t����cnt��ŵ�ǿ��ͨ����   
           }while(t != v);  //ֱ����v��ջ���˳�   
     }  
}  
  
void solve()  
{  
     for(int i = 1; i <= n; i++)   //ö��ÿ����㣬������ͨ����  
        if(!DFN[i])  //δ������   
           Tarjan(i);  //����i������ͨ����   
}  
  
int main()  
{  
    while(scanf("%d%d",&n,&m) && (n || m))  
    {  
        init();  
        while(m--)  
        {  
            int u, v;  
            scanf("%d%d", &u, &v);  
            read_graph(u, v);  
        }  
        solve();     //��ǿ��ͨ����   
        //if(scnt == 1) printf("Yes\n");  //ֻ��һ��ǿ��ͨ������˵����ͼ������㶼�ɴ�  
        //else printf("No\n");  
        cout<<scnt; 
    }  
    return 0;  
}  
