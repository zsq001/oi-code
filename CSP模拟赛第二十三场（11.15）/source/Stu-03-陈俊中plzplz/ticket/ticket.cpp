#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int l,c,le[30],step,use[30];
char str[20];

void dfs(int ans,int ans1,int ans2)
{
	if(step>=25000) return ;
	if(ans==l+1)
	{
		if(ans1>=1&&ans2>=2)
		{
			step++;
			for(int i=1;i<=l;i++)
			{
				printf("%c",str[use[i]]);
			}
			printf("\n");
		}
		return ;
	}
	for(int i=use[ans-1]+1;i<=c;i++)
	{
		if(!le[i])
		{
			le[i]=1;
			use[ans]=i;
			if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u')
				dfs(ans+1,ans1+1,ans2);
			else dfs(ans+1,ans1,ans2+1);
			le[i]=0;
		}
	}
}

//a->1 e->5 i->9 o->15 u->21
int main()
{
	freopen("ticket.in","r",stdin);
	freopen("ticket.out","w",stdout);
	scanf("%d%d\n",&l,&c);
	for(int i=1;i<=c;i++) 
	{
		scanf("%c",&str[i]);
//		le[i]=ch-96;
		if(i<c) scanf(" ");
	}
	sort(str+1,str+1+c);
	dfs(1,0,0);
//	for(int i=1;i<=c;i++)
//	printf("%d ",le[i]);
	return 0;
}
