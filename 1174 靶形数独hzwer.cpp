#include<iostream>
#include<cstdio>
#include<ctime>
#define searchnext(x,y) y==9? search(x+1,1):search(x,y+1)
using namespace std;
bool r[10][10],l[10][10],s[10][10];//行，列，小九宫格 
int a[10][10],b[10][10];
int ans=-1,score;
int getscore(int x,int y,int k)
{
	if(x==5&&y==5)return 10*k;
	else if(x>=4&&x<=6&&y>=4&&y<=6)return 9*k;
	else if(x>=3&&x<=7&&y>=3&&y<=7)return 8*k;
	else if(x>=2&&x<=8&&y>=2&&y<=8)return 7*k;
	else return 6*k;
}
bool fillin(int x,int y,int k)
{
	if(r[x][k])return 0;
	if(l[y][k])return 0;
	if(s[(x-1)/3*3+(y-1)/3+1][k])return 0;
	b[x][y]=k;
	r[x][k]=l[y][k]=s[(x-1)/3*3+(y-1)/3+1][k]=1;
	score+=getscore(x,y,k);
	return 1;
}
void del(int x,int y,int k)
{
	b[x][y]=0;
	r[x][k]=l[y][k]=s[(x-1)/3*3+(y-1)/3+1][k]=0;
}
void search(int x,int y)
{
    if(clock()>1000)return;
	if(x==10&y==1){
		ans=max(ans,score);
		return;}
	if(b[x][y])searchnext(x,y);
	else 
		for(int i=1;i<=9;i++)
		{
			int t=score;
			if(fillin(x,y,i))
			{
				searchnext(x,y);
				del(x,y,i);
				score=t;
			}
		}
}
int main()
{
	for(int i=1;i<=9;i++)
		for(int j=1;j<=9;j++)
		{
			scanf("%d",&a[i][j]);
			if(a[i][j])fillin(i,j,a[i][j]);
		}
    search(1,1);
    printf("%d",ans);
	return 0;
}
