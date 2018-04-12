#include<iostream>

#include<cstring>

using namespace std;

char str[2000010];

char zhan[2000010];

int n,h,q=0;

bool judge()

{

q=0;

int len=strlen(str);

for (int i=0;i<=len-1;i++){

if ((str[i]=='{'&&(zhan[q]=='{')||(str[i]=='['&&(zhan[q]=='{'||zhan[q]=='['))||((str[i]=='(')&&zhan[q]!='<')||(str[i]=='<')) ||(q==0&&(str[i]=='{'||str[i]=='['||str[i]=='('||str[i]=='<'))) zhan[++q]=str[i];


else if ((zhan[q]=='{'&&str[i]=='}')||(zhan[q]=='['&&str[i]==']')||(zhan[q]=='('&&str[i]==')')||(zhan[q]=='<'&&str[i]=='>'))q--;

else return false;

}

if (q)return false;else return true;

}

int main()

{

cin>>n;

for (int i=1;i<=n;i++){

cin>>str;

if(judge())cout<<"YES";else cout<<"NO";

cout<<endl;

}

return 0;

}
