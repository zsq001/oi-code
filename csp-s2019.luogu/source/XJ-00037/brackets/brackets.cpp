#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <stack>
using namespace std;
stack <char> S;
struct edge{
	int u,v,next;
}e[2010];

int val[2010],vis[2010],a[2010];
int head[2010],cnt;
char c[500010];
char cs[500010];

void add(int u,int v) {
	e[++cnt].u = u;
	e[cnt].v = v;
	e[cnt].next = head[u];
	head[u] = cnt;
}
int main () {
	int n;
	freopen("brackets.in","r",stdin);
	freopen("brackets.out","w",stdout);
	scanf("%d",&n);
	scanf("%s",c);
	for (int i = 1; i < n ; i ++) {
		scanf("%d",&a[i]);
		add(a[i],i);
	}
	int ans = 0;
	cs[0] = c[0];
	for (int i = 0; i < n; i ++) {
		cs[i] = c[i];
		int sum = 0;
		int l = strlen(cs);
		for (int j = 0; j < l; j ++) {
			int flag = 0;
			if (cs[j] == '(') 
				S.push(cs[j]);
			else if (!S.empty() && cs[j] == ')') {
				S.pop();
				sum ++;					
			}
			else {
				flag = 1;
			}
			if (S.empty() && flag == 0) sum++;
		}
		ans = ans ^ (sum * (i+1));
	}
	printf("%d",ans);
	return 0;
}
