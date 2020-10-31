#include<stdio.h>
#include<algorithm>
using namespace std;
int l,c,acc;
char z,a[30],ans[20];
void dfs(int now,int nowl,int num)
{
	if(acc>=25000)return;
	if(nowl==l)
	{
		if(num>=1&&l-num>=2)
		{
			for(int i=1;i<=l;i++)
				printf("%c ",ans[i]);
			printf("\n");
			acc++;
		}
		return;
	}
	for(int i=now+1;i<=c;i++)
	{
		ans[nowl+1]=a[i];
		if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u')dfs(i,nowl+1,num+1);
		else                                                     dfs(i,nowl+1,num);
	}
}
int main()
{
	freopen("ticket.in","r",stdin);
	freopen("ticket.out","w",stdout);
	scanf("%d%d",&l,&c);
	for(int i=1;i<=c;i++)
		scanf("%c%c",&z,&a[i]);
	sort(a+1,a+c+1);
	dfs(0,0,0);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
