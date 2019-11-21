#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
int cnt[2000000],to[2000000],head[2000000],next[2000000],a[2000000],fa[2000000];
int tot,n,ANS;
char ch;
void add(int x,int y){
	to[++tot]=y;
	next[tot]=head[x];
	head[x]=tot;
}
void dfs(int x,int dep,int ansb){
	if(a[x])dep++;
	else	dep--;	
	int ocnt=0,flag=0;
	if(dep>=0){
		if(a[x]==0){
			flag=1;
			ocnt=cnt[dep];
			cnt[dep]++;
			ansb+=cnt[dep];
			cnt[dep+1]=0;
		}
	}
	else{
		dep=0;
		cnt[0]=0;
	}
	ANS^=x*ansb;
	for(int i=head[x];i;i=next[i]){
		dfs(to[i],dep,ansb);
	}
	if(flag)cnt[dep]=ocnt;
}
int main(){
	freopen("brackets.in","r",stdin);
	freopen("brackets.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		ch=0;
		while(ch!='('&&ch!=')'){
			scanf("%c",&ch);
			a[i]=(ch=='(');
		}
	}
	for(int i=2;i<=n;i++)scanf("%d",&fa[i]),add(fa[i],i);
	dfs(1,0,0);
	printf("%d",ANS);
}
