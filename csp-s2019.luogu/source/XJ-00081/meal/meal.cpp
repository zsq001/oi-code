/* 
*  CSP-S2 2019 AFO祭 
*  NOIP/CSP Goodbye!
*  2016.12 - 2019.11 (NOIP2017-J, NOIP2018-S, CSP-S 2019)
*  spinmry@(HBSYZX->BTEZ)   
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

//define
const int maxn = 100 + 5;
const int maxm = 2000 + 5;
struct node{
	int u, v, w, next;
}e[maxn*maxm];
//u:方法 v:食材 w:菜种类 
//v范围 [n+1, n+m+1] 
int tot, head[maxn*maxm], n, m, vis_count[maxn + maxm], m_blocked[maxn + maxm];
int ans, max_vis = 0;

inline __attribute__((__always_inline__)) void 
addedge(int u, int v, int w){
	e[++tot] = (node){u, v, w, head[u]};
	head[u] = tot;
}

//main
int main(){
	ios::sync_with_stdio(false);
	freopen("meal.in", "r", stdin);
	freopen("meal.out", "w", stdout);
	cin >> n >> m;
	
	for(register int i = 1; i <= n; ++i){
		for(register int j = 1; j <= m; ++j){
			int tmp;cin >> tmp;
			if(tmp != 0){
				addedge(i, j + n, tmp);
			}
		}
	}
	
	for(register int k = 1; k <= n; ++k){
		max_vis = k >> 1;int now = 0;
		for(register int i = 1; i <= n; ++i){
			
		}
	}
	
	return 0;
} 
