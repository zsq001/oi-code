#include<bits/stdc++.h>
using namespace std;

int n,vis[2010],stk[2010],top,ans[2010];
struct NNDE{
	int v;
	int id;
}a[2010],b[2010];
struct NODE{
	int x,y;
}EDGE[2010];
int cnt,first[2010];
bool cmp(NNDE x,NNDE y){
	return x.v<y.v;
}
bool cmmmp(NNDE *x){
	for(int i = 1; i <= n; i++){
		if(x[i].id<ans[i])return 1;
		else if(x[i].id>ans[i])return 0;
	}
	return 1;
}

void work(){
	memcpy(b,a,sizeof a);
	for(int i = 1; i <= top; i++){
		swap(b[EDGE[stk[i]].x].v,b[EDGE[stk[i]].y].v);
	}
	sort(b+1,b+1+n,cmp);
	if(cmmmp(b))for(int i =1; i <= n; i++)ans[i]=b[i].id;
}

void dfs(int num){
	if(num==n){
		work();
	}
	for(int i = 1; i <= n; i++){
		if(vis[i])continue;
		stk[++top] = i;
		vis[i]=1;
		dfs(num+1);
		vis[i]=0;top--;
	}
}
void init(){
	memset(ans,0x3f,sizeof ans);
	memset(vis,0,sizeof ans);
	top=0;
}
int T;
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		init();
		scanf("%d",&n);
		if(n<=10){
			for(int i = 1; i <= n; i++){
				scanf("%d",&a[i].v);a[i].id = i;
			}
			for(int i = 1; i < n; i++){
				int x,y;
				scanf("%d%d",&x,&y);
				EDGE[i].x = x;
				EDGE[i].y = y;
			}
			dfs(0);
		}
		for(int i = 1; i <= n; i++)printf("%d ",ans[i]);
		puts("");
	}
}
