#include <stdio.h>
char c[17], last, la[3];
int i, j, k, l=1;
int main()

{

    for(i=1;i<=16;i++)
    {
        c[i] = getchar();
        getchar();
    }
    last = c[1];
    printf("%c",c[1]);
    for(i=2;i<=16;i++)
    {
        if(c[i] != last)
        {
            if(l != 1)
                printf("%d",l);
                l = 0; last = c[i]; printf("%c",c[i]);
        }
        if(c[i] == last)
        {
            l++;
        }
    }
    if(l>1)
        printf("%d",l);
    printf(" ");
    la[1] = c[1];
    la[2] = c[2];
    l = 1;
    printf("%c%c",c[1],c[2]);
    for(i=3;i<=15;i+=2)
    {
        if(c[i] != la[1] || c[i=1] != la[2])
        {
            if(l!=1)
                printf("%d",1);
            l=0;
            la[1] = c[i];
            la[2] = c[i+1];
            printf("%c%c",c[i],c[i+1]);
        }
        if(c[i] == la[1] && c[i+1] == la[2])
        {
            l++;
        }
    }
    if(l>1)
        printf("%d",l);

}

