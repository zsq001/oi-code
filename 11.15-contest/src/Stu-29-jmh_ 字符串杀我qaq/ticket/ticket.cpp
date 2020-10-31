#include<cstdio>
#include<algorithm>
using namespace std;
#define check(x) ((x=='a') || (x=='e') || (x=='i') || (x=='o') || (x=='u'))


int l,c;
char s[30];
int f[30];
char ans[30],cnt;

bool cmp(char a,char b){
	return (int)(a-'a')<(int)(b-'a');
}


void dfs(int x,int o,int fu){
	ans[o]=s[x];
	if(cnt>=25000) exit(0);
	if(f[x]+fu < 2) return;
	if(o==l){
		if(fu<2) return ;
		for(int i=1;i<=l;i++){
			printf("%c",ans[i]);
		}
		printf("\n");
		cnt++;
		return ;
	}
	for(int i=x+1;i+l-o-1<=c && i<=c && f[i]+fu>=2;i++){
		
		if(check(s[i]) && fu==-1) dfs(i,o+1,0);
		else if(check(s[i]) && fu!=-1) dfs(i,o+1,fu);
		else if(!check(s[i]) && fu==-1) dfs(i,o+1,fu);
		else if(!check(s[i]) && fu!=-1) dfs(i,o+1,fu+1);
	}
}





int main()
{
	freopen("ticket.in","r",stdin);
	freopen("ticket.out","w",stdout);
	scanf("%d %d",&l,&c);
	for(int i=0;i<c;i++){
		scanf("%c ",&s[i]);
	}
	scanf("%c",&s[c]);
	sort(s+1,s+1+c,cmp);
	for(int i=c;i>=1;i--){
		f[i]=f[i+1];
		if(!check(s[i])) f[i]++;
	}
	for(int i=1;i+l-1<=c;i++){
		if(check(s[i])) dfs(i,1,0);
		else dfs(i,1,-1);
	}
	
	return 0;
}
/*
4 6
a t c i s w

*/



