#include <iostream>
using namespace std;
int main()
{
    string s;
    cin>>s;
    if(s[0]=='+')
    {
        for(int i=0;i<s.size();i++)
        {
            s[i]=s[i+1];
        }
    }
    if(s[0]=='-')
    {
        for(int i=1;i<s.size();i++)
        cout<<s[i];
    }else
    {
        cout<<'-';
        cout<<s;
    }

}

