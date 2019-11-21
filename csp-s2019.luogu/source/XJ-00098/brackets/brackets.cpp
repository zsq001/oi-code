#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define maxn 500005
#define ll long long

int read(){
	int ret=0;char ch=getchar();
	while(ch<'0'||ch>'9') {ch=getchar();}
	while(ch<='9'&&ch>='0') {
		ret=(ret<<3)+(ret<<1)+(ch&15);
		ch=getchar();
	}
	return ret;
}

int n,cnt,head[maxn],ans[maxn],s[maxn],r,a[maxn];

struct node{
	int v,next;
}e[maxn<<1];

void add(int u,int v){
	e[++cnt].v=v;
	e[cnt].next=head[u];
	head[u]=cnt;
}

void dfs(int x,int fx){
	for(int v,i=head[x];i;i=e[i].next){
		if(e[i].v==fx) continue;
		v=e[i].v;
		ans[v]=ans[x];
		if(r&&a[v]==0){
			r--;
			ans[v]++;
			dfs(v,x);
			r++;
		}else if(a[v]==1){
			++r;
			dfs(v,x);
			r--;
		}else {
			dfs(v,x);
		}
	}
}

int main(){
	freopen("brackets.in","r",stdin);
	freopen("brackets.out","w",stdout);
	scanf("%d",&n);
	char cc=getchar();
	while(cc!='('&&cc!=')') cc=getchar();
	a[1]=(cc=='(');
	for(int i=2;i<=n;i++){
		scanf("%c",&cc);
		a[i]=(cc=='(')?1:0;
	}
	int fa;
	for(int i=2;i<=n;i++){
		scanf("%d",&fa);
		add(fa,i);
		add(i,fa);
	}
	if(a[1]) s[++r]=1;
	dfs(1,0);
	int aaa=0;
	for(int i=1;i<=n;i++){
		aaa^=i*ans[i];
	}
	printf("%d",aaa);
	return 0;
}
//50
//))()(())((((()))))))((())))()))((()(()((((((())())
//1 2 1 2 2 6 6 6 6 10 10 10 7 13 13 10 13 15 18 18 20 17 19 10 25 26 27 25 25 25 31 29 30 34 25 34 29 25 30 39 38 41 34 36 35 43 44 25 44


