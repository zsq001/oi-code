#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std; 

#define ll long long
#define RG register
#define pr pair<int,int>
#define mp(x,y) (make_pair(x,y))
#define MAXN 222200

inline int read() {
    RG int x = 0, t = 1;  
	RG char ch = getchar(); 
    while(ch < '0' || ch > '9') {if(ch == '-') t = -1; ch = getchar(); }
    
    while(ch <= '9' && ch >= '0') x = x * 10 + ch - 48, ch = getchar(); 
    return x * t; 
}

int nt[MAXN], lt[MAXN], n, m, a[MAXN], ans; 

priority_queue <pr> Q; 

int main() {
	freopen("a.in", "r", stdin); 
	freopen("a.out", "w", stdout); 
    n = read(); m = read();
    for(int i = 1; i <= n; ++i) a[i] = read();
    for(int i = 1; i < n; ++i) nt[i] = i + 1; nt[n] = 1;
    for(int i = 2; i <= n; ++i) lt[i] = i - 1; lt[1] = n;
    for(int i = 1; i <= n; ++i) Q.push(mp(a[i], i));
    if(m > n / 2) { puts("Error!"); return 0; }
    while(m)
    {
        pr u = Q.top(); Q.pop(); 
        int v = u.second;
        if(nt[lt[v]] != v) continue;
        a[v] = a[lt[v]] + a[nt[v]] - a[v];
        lt[v] = lt[lt[v]]; nt[v] = nt[nt[v]];
        nt[lt[v]] = v; lt[nt[v]] = v;
        Q.push(mp(a[v], v)); ans += u.first;
        --m;
    }
    printf("%d\n",ans); 
    return 0; 
}
