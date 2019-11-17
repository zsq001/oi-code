#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
int l,c,cnt,a[30],t[30];
bool yuan[27] = {0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0};
void dfs(int pre,int y,int len)
{
	if(len > l)
	{
		if(y < 1 || l - y < 2) return;
		for(int i = 1;i <= l;i ++)
		{
			printf("%c",t[i] + 'a' - 1);
		}
		puts("");
		++cnt;
		if(cnt > 25000) exit(0);
		return;
	}
	for(int i = pre+1;i <= c;i ++)
	{
		t[len] = a[i];
		if(yuan[a[i]]) dfs(i,y+1,len+1);
		else dfs(i,y,len+1);
	}
}

int main()
{
	freopen("ticket.in","r",stdin);
	freopen("ticket.out","w",stdout);
	scanf("%d %d\n",&l,&c);
	for(int i = 1;i <= c;i ++)
	{
		char ch;
		ch = getchar();
		getchar();
		a[i] = ch - 'a' + 1;
//		if(yuan[a[i]]) printf("%d ",(a[i] +'a' - 1));
	}
	sort(a+1,a+c+1);
	dfs(0,0,1);
	return 0;
}
