#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int n,m,k,x,s,min1=0,min2=0;

struct  Skill {int a,b;}skill[100010];
struct Audiance {int c,d;}au[100010];

bool cmps(Skill w,Skill e) {return w.a<e.a;}
bool cmpa(Audiance w,Audiance e) {return w.c>e.c;}

void read()
{
	scanf("%d%d%d",&n,&m,&k);
	scanf("%d%d",&x,&s);
	for(int i=1;i<=m;i++)
		scanf("%d",&skill[i].a);
	for(int i=1;i<=m;i++)
		scanf("%d",&skill[i].b);
	for(int j=1;j<=k;j++)
		scanf("%d",&au[j].c);
	for(int j=1;j<=k;j++)
		scanf("%d",&au[j].d);
	return ;
}

int solve1(int xx,int nn,int ss)
{
	for(int i=1;i<=m;i++)
	{
		if(skill[i].b<ss) 
		{
			xx=skill[i].a;
			ss-=skill[i].b;
			break;
		}
	}
	for(int i=1;i<=k;i++)
	{
		if(au[i].d<ss) 
		{
			nn-=au[i].c;
			ss-=au[i].d;
			break;
		}
	}
	if(nn<=0) return min1;
	else return nn*xx;
}

int solve2(int xx,int nn,int ss)
{
	for(int i=1;i<=k;i++)
	{
		if(au[i].d<ss) 
		{
			nn-=au[i].c;
			ss-=au[i].d;
			break;
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(skill[i].b<ss) 
		{
			xx=skill[i].a;
			ss-=skill[i].b;
			break;
		}
	}
	if(nn<=0) return min2;
	else return nn*xx;
}

int main()
{
	freopen("sword.in","r",stdin);
	freopen("sword.out","w",stdout);
	read();
	sort(skill+1,skill+1+m,cmps);
	sort(au+1,au+1+k,cmpa);
	min1=solve1(x,n,s);
	min2=solve2(x,n,s);
	printf("%d",min(min1,min2));
	fclose(stdin);
	fclose(stdout);
	return 0;
}

