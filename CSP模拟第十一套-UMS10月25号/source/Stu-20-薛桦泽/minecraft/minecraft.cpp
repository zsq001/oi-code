#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

struct Code
{
	int x[4];
}node[100010];
int n,b,d,m,ans=0;

bool cmp(Code j,Code k)
{
	if(j.x[1]>k.x[1]) return j.x[1]<k.x[1];
	else if(j.x[1]==k.x[1]&&b>=2) return j.x[2]>k.x[2];
	else if(j.x[1]==k.x[1]&&j.x[2]==k.x[2]&&b==3) return j.x[3]>k.x[3];
}

int dis(int i,int j)
{
	if(b==1) return node[i+j].x[1]-node[i].x[1];
	if(b==2) 
	{
		int kk=node[i+j].x[2]-node[i].x[2];
		if(kk<0) return node[i+j].x[1]-node[i].x[1]-kk;
		else return node[i+j].x[1]-node[i].x[1]+kk;
	}
	if(b==3)
	{
		int kk1=node[i+j].x[2]-node[i].x[2];
		if(kk1<0) kk1=-kk1;
		int kk2=node[i+j].x[3]-node[i].x[3];
		if(kk2<0) kk2=-kk2;
		return node[i+j].x[1]-node[i].x[1]+kk1+kk2;
	}
}

int main()
{
	freopen("minecraft.in","r",stdin);
	freopen("minecraft.out","w",stdout);
	
	scanf("%d%d%d%d",&b,&n,&d,&m);
	if(d>=m)
	{
		printf("%d",n*(n-1)/2);
		return 0;
	}
	for(int i=1;i<=n;i++)
		for(int B=1;B<=b;B++)
			scanf("%d",&node[i].x[B]);
	sort(node+1,node+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		int j=1;
		while(i+j<=n) 
		{
			if(dis(i,j)<=d) ans++;
			j++;
		}
	}
	printf("%d",ans);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
