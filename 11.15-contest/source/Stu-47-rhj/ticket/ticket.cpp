#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int len,n,cnt,tot;
char s[30],ans[20];
bool vis[30],flag;
void print()
{
	for(int i=1;i<=len;++i)
		printf("%c",ans[i]);
	printf("\n"),++tot;
}
void dfs(int pos,int last,int cnt1,int cnt2)
{
	if(flag) return;
	if(pos>len)
	{
		if(cnt1<1||cnt2<2) return;
		print();
		if(tot>25000) flag=1;
		return;
	}
	if(last==n) return;
	if(cnt2<2)
	{
		if(len-pos+1<2-cnt2) return;
		else if(len-pos+1<2-cnt2+1-cnt1) return;
	}
	for(int i=last+1;i<=n;++i)
	{
		ans[pos]=s[i];
		if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u') dfs(pos+1,i,cnt1+1,cnt2);
		else dfs(pos+1,i,cnt1,cnt2+1);
	}
}
int main()
{
	freopen("ticket.in","r",stdin);
	freopen("ticket.out","w",stdout);
	scanf("%d%d",&len,&n);
	for(int i=1;i<=n;++i)
	{
		int ch[2];
		scanf("%s",ch);
		if(ch[0]>='A'&&ch[0]<='Z') ch[0]+='a'-'A';
		if(vis[ch[0]-'a']) continue;
		vis[ch[0]-'a']=1,s[++cnt]=ch[0];
	}
	sort(s+1,s+cnt+1);
	dfs(1,0,0,0);
	return 0;
}
