#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define maxn (510)

using namespace std;

struct node {
	int a, b;
	node(int a=0,int b=0):a(a),b(b) {}
}no[maxn], po[maxn];

struct edge{
	edge *next;
	int v;
	edge():next(NULL) {}
} *head[maxn], E[maxn*maxn];

int Cat, Dog, n, n1, n2, E_cnt, ans;
int occupy[maxn];
bool vis[maxn];

inline void Addedge(int u,int v) {
	edge *p = &E[++E_cnt];
	p->v = v;
	p->next = head[u];
	head[u] = p;
}

bool Dfs(int u) {
	if(vis[u]) return false;
	vis[u] = true;
	for(edge *i=head[u]; i; i=i->next) {
		if(occupy[i->v]==0 || Dfs(occupy[i->v])) {
			occupy[i->v] = u;
			return true;	
		}	
	}	
	return false;
}
int main() {
	freopen("catvsdog.in","r",stdin);
	freopen("catvsdog.out","w",stdout);

	int a, b;
	char t1, t2;
	scanf("%d %d %d\n",&Cat,&Dog,&n);
	for(int i=1; i<=n; i++) {
		scanf("%c%d %c%d\n",&t1,&a,&t2,&b);
		if(t1=='C') no[++n1] = node(a,b);
		else po[++n2] = node(a,b);
	}
	for(int i=1; i<=n1; i++) {
		for(int j=1; j<=n2; j++) {
			if(no[i].a==po[j].b || no[i].b==po[j].a) {
				Addedge(i,j);
			}
		}	
	}
	memset(occupy,0,sizeof(occupy));
	for(int i=1; i<=n1; i++) {
		memset(vis,false,sizeof(vis));
		if(Dfs(i)) ans++;
	}
	printf("%d\n",n-ans);

	fclose(stdin);
	fclose(stdout);
	return 0;
}

