#include <stdio.h>
int yuan,fu,ans=0,l,c;
int prin[20],letble[50],vis[50];
char str[50];
void dfs(int dep)
{
	if(dep>l)
	{
		yuan=0;fu=0;
		for(int i=1;i<=l;i++)
		{
			if(str[prin[i]]=='a'||str[prin[i]]=='e'||str[prin[i]]=='i'||str[prin[i]]=='o'||str[prin[i]]=='u')yuan++;
			else fu++;
		}
		if(yuan>=1&&fu>=2&&ans<=25000)
		{
			for(int i=1;i<=l;i++)
				printf("%c",str[prin[i]]);
			puts("");
			ans++;
		}
		return ;
	}
	for(int i=prin[dep-1]+1;i<=c;i++)
	{
		prin[dep]=i;
		dfs(dep+1);
		prin[dep]=0;
	}
}
int main()
{
	int cnt=0;
	char x;
	freopen("ticket.in","r",stdin);
	freopen("ticket.out","w",stdout);
	scanf("%d%d\n",&l,&c);
	scanf("%c",&x);
	letble[x-96]++;
	for(int i=2;i<=c;i++)
	{
		scanf(" %c",&x);
		letble[x-96]++;
	}
	for(int i=1;i<=26;i++)
		if(letble[i])str[++cnt]=i+96;
	dfs(1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
