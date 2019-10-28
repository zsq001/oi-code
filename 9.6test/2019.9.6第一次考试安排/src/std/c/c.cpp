#include <cstdio>
#include <algorithm>
#include <iostream>
#include<map>
using namespace std;
#define MAXN 90100
#define MAXM 311

int n,m,ans;
int x[MAXM][MAXM];
int v[MAXN], tot[MAXN], cost[MAXN];

map<int, int>mp;

bool check(int a,int b,int c) {
    if(a >= b || a >= c || b >= c || a <= 0 || b <= 0 || c <= 0) return 0;
    if(x[ans][1] == a && x[ans][2] == b && x[ans][3] == c) return 0;
    ans++;
    x[ans][1] = a;
	x[ans][2] = b;
	x[ans][3] = c;
    return 1;
}

bool getx() {
    bool flag = 0;
    memset(cost, 0, sizeof(cost));
    cost[ mp[ x[ans][1] + x[ans][2] ] ]++;
    cost[ mp[ x[ans][1] + x[ans][3] ] ]++;
    cost[ mp[ x[ans][2] + x[ans][3] ] ]++;

    int now = 3;

    for(int i = 4; i <= n && !flag; i++) {
        while(tot[mp[v[now]]]-cost[mp[v[now]]] == 0) now++;
        x[ans][i] = v[now] - x[ans][1];
        for(int j = 1; j < i; j++) {
        	int now_t = x[ans][i] + x[ans][j];
            int pos = mp[now_t];
            cost[pos]++;
            if(cost[pos] > tot[pos]) flag = 1;
        }
    }
    return flag;
}

int main() {
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
    scanf("%d", &n);
    m = n * (n - 1) / 2;
    for(int i = 1; i <= m; i++)
    scanf("%d", &v[i]);
    sort(v + 1, v + m + 1);
    for(int i = 1; i <= m; i++) {
        if(!mp[v[i]]) mp[v[i]] = i;
        tot[mp[v[i]]]++;
    }
    
    int t1 = v[1], t2 = v[2];
    for(int i = 3, a, b, c; i <= n; i++) {
        b = (v[i] - t2 + t1) / 2;
        c = v[i] - b; a = t1 - b;
        if(check(a, b, c)) ans -= getx();
    }
    printf("%d\n", ans);
    for(int i = 1; i <= ans; i++) {
        for(int j = 1; j <= n; j++) printf("%d ", x[i][j]);
        printf("\n");
    }
    return 0;
}
