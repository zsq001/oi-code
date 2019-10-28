#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct Pos
{
	int a;
	int pos;
	bool used;
}p[200020];
Pos pp[200020];

int ans=0;

bool cmp(Pos x,Pos y)
{
	return x.a>y.a;
}

int n,m;
int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&p[i].a);
		p[i].pos=i;
		p[i].used=false;
	}
	if(n<=m*2)
	{
		printf("error\n");
		return 0;
	}
	memcpy(pp,p,sizeof(p));
	sort(pp+1,pp+1+n,cmp);
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(!p[pp[i].pos].used&&!p[pp[i].pos+1].used&&!p[pp[i].pos-1].used)
		{
			ans+=pp[i].a;
			p[pp[i].pos].used=true;
			cnt++;
		}
		if(cnt>=m) break;
	}
	if(cnt>=m)printf("%d\n",ans);
	else printf("error");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
