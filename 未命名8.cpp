#include<queue>
#include<iostream>
#include<string>
#include<set>
using namespace std;
struct node
{
int step;
string s;
node(int step=0,string s=""):step(step),s(s){}
};
set<string>c;
queue<node>q;
string st,end,a[7],b[7];
int n=1,ans=-1;
int main()
{
cin>>st>>end;
node start(0,st);
q.push(start);
c.insert(start.s);
while(cin>>a[n]>>b[n])n++;
n--;
while(!q.empty())
{
node ing=q.front();
q.pop();
if(ing.s==end&&ing.step<=10)
{
ans=ing.step;
break;
}
if(ing.step>10)break;
for(int i=1;i<=n;i++)
{
for(int j=0;j<ing.s.length();j++)
int v=ing.s.find(a[i],j);
   if(v>=0)
   {
   	node in=ing;
   in.s.replace(v,a[i].length(),b[i]);
in.step++; 
   	   if(!c.count(in.s))
{
q.push(in);
   	       c.insert(in.s);
}
   	}
}
}
}
if(ans!=-1)cout<<ans;
else cout<<"NO ANSWER!";
}

