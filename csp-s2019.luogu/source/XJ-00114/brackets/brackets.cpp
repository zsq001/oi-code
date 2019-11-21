#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
char s[500005], ss[500005];
struct Edge{
	int next, to;
}edge[500005];
int head[500005], tot = 0, l[500005], r[500005], suml = 0, sumr = 0, ll[500005], sumll = 0, anss;
long long ans;
void add_edge(int u, int v){
	edge[++tot].next = head[u];
	edge[tot].to = v;
	head[u] = tot;
}
long long calc(int x){
	long long fact = 1, fact2 = 1, ans = 0;
	for (int i = 1;i <= x / 2ll;i++){
		fact *= (x - i + 1ll); fact2 *= i;
		ans += fact / fact2;
	} ans = ans * 2ll + 1ll;
	if (!(x % 2ll)) ans -= fact / fact2;
	return ans;
}
void work(int tmp){
	int tmpp = ans, tmp2 = 0;
	for (int i = 1;i <= tmp;i++){
		int t = i;
		while (i < tmp && ll[i] + 2 == ll[i + 1]) i++;
		l[++tmp2] = ll[t]; r[tmp2] = ll[i] + 1; ans += calc(i - t + 1);
	}
	int flag = 0;
	for (int i = 1;i <= tmp2;i++) if (ss[l[i] - 1] == '(' && ss[r[i] + 1] == ')') l[i]--, r[i]++, flag = 1;
	if (!flag) return ;
	memcpy(ll, l, sizeof(l)); memset(l, 0, sizeof(l)); memset(r, 0, sizeof(r)); work(tmp2);
}
void dfs(int x, int step){
	for (int i = head[x];i;i = edge[i].next){
		int y = edge[i].to; ss[step] = s[y];
		memset(ll, 0, sizeof(ll)); memset(l, 0, sizeof(l)); memset(r, 0, sizeof(r));
		int tmp = 0; ans = 0;
		for (int i = 1;i < step;i++) if (ss[i] == '(' && ss[i + 1] == ')') ll[++tmp] = i;
		work(tmp); anss ^= (y * ans);
		dfs(y, step + 1);
	}
}
int main(){
	freopen("brackets.in", "r", stdin);
	freopen("brackets.out", "w", stdout);
	int n; scanf("%d\n", &n);
	gets(s + 1);
	for (int i = 2;i <= n;i++){
		int fa; scanf("%d", &fa);
		add_edge(fa, i);
	}
	ss[1] = s[1]; dfs(1, 2);
	printf("%d", anss);
	return 0;
}
