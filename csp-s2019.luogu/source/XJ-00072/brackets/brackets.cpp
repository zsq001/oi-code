#include<bits/stdc++.h>
using namespace std;
int n,k,ans;
char str[4040];
int cnt,first[4040],f[4040];
struct node{
	int to,next;
}edge[4040];
char stk[4040];
int top,fa[4040],vis[4040];
void add(int u,int v){
	edge[++cnt].to = v;
	edge[cnt].next = first[u];
	first[u]=cnt;
}
char stkk[4040],topp;
int check(int l,int r,int x){
	topp = 0;int i = l;
	while(i<=r){
		stkk[++topp] = stk[i];
		i++;
		if(top-1>0&&stkk[topp]==')'&&stkk[topp-1]=='(')topp-=2;
	}
	if(topp)return 0;
	else return 1;
}

void calc(int x){
	int ccnt = 0;
	if(str[x]=='('){
		ans^=f[fa[x]]*x;
		f[x] = f[fa[x]];
//		printf("%d %d\n",x,f[x]);
		return ;
	}
	for(int l = 1; l < top; l++){
		for(int r = l+1; r<=top; r++){
			ccnt+=check(l,r,x);
		}
	}
	f[x] = ccnt;
	ans^=ccnt*x;
//	printf("%d %d\n",x,ccnt);
}

void dfs(int x){
	calc(x);
	for(int i = first[x];i;i = edge[i].next){
		int y = edge[i].to;
		if(vis[y])continue;
		stk[++top] = str[y];
		vis[y]=1;
		dfs(y);vis[y]=0;
		top--;
	}
}

int main(){
	freopen("brackets.in","r",stdin);
	freopen("brackets.out","w",stdout);
	scanf("%d",&n);
	scanf("%s",str+1);
	for(int i = 2; i <= n; i++){
		int a;
		scanf("%d",&a);
		fa[i] = a;
		add(a,i);
	}stk[++top] = str[1];
	dfs(1);printf("%d",ans);
}
