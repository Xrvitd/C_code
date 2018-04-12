#include<stdio.h>
int i,j,k;
typedef struct
{
	int lpu,lsh,rpu,rsh;
}RE; 
RE b,t;
int v[4][4][4][4]={0};
int compere(RE a)
{
	if(v[a.lsh][a.lpu][a.rsh][a.rpu]==1)
	{
		return 1;
	}
	return 0;
}
int over(RE a)
{
	if(a.lpu>a.lsh||a.rpu>a.rsh)
    {
    	return 1;
    } 
    return 0;
}
void save(RE a)
{
	v[a.lsh][a.lpu][a.rsh][a.rpu]=1;
}
void copy(RE a,RE c)
{
	a.lpu=c.lpu;
	a.lsh=c.lsh;
	a.rpu=c.rpu;
	a.rsh=c.rsh;
}
void dfs(RE a)
{
	if(over(a)==1)
	{
		return;
	}
	if(a.lsh>=2)
	{
		copy(t,a);
		t.lsh-=1;t.rsh+=1;
		if(compere(t)==0)
		{
			save(t);
			dfs(t);
		}
		dfs()
	}
	
}
int main()
{
	b.lpu=3;
	b.lsh=3;
	b.rpu=0;
	b.rsh=0;
	dfs(b);
}
