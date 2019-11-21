#include <cstdio> 
#include <cstring>

#include <algorithm>

const int N = 2100;

int T;
int n, m, in_cnt, one_cnt;
bool check_edge;
int in_deg[N], a[N];

// Edge Start 
struct edge{
	int to, next;
} e[ N << 1 ];

struct _edge {
	int now, to;
} _e[N];
int ehead[N], ecnt, _ecnt;
inline void add_edge( int now, int to ) {
	ecnt ++;
	_e[ ++ _ecnt ] = (_edge){now,to};
	e[ecnt].to = to;
	e[ecnt].next = ehead[now];
	ehead[now] = ecnt;
}

// Edge End

namespace bf {
	bool vis[N];
	int ans[N];
	void check() {
		bool flag, top;
		flag = top = false;
		for( int i = 1; i <= n; i ++ ) {
			if( top == false || a[i] < ans[i] ) {
				flag = true, top = true;
				break;
			}
			if( top == false && a[i] > ans[i] ) {
				return ;
			}
		}
		if( flag ) 
			for( int i = 1; i <= n; i ++ ) 
				ans[i] = a[i];
		
	}
	void dfs( int dep ) {
		if( dep == n - 1 ) {
			check();
			return ;
		}
		for( int i = 1; i < n; i ++ ) {
			if( vis[i] ) 
				continue;
			vis[i] = true;
			std::swap( a[_e[i].now], a[_e[i].to] );
			dfs( dep + 1 );
			std::swap( a[_e[i].now], a[_e[i].to] );
			vis[i] = false;
		}
	}
	void work() {
		for( int i = 1; i <= n; i ++ )
			ans[i] = n + 1;
		dfs(0);
		for( int i = 1; i <= n; i ++ ) 
			printf( "%d ", ans[i] );
		printf( "\n" );
	}
}

// namespace check_edge {
// 	void work() {
// 	}
// }

inline void init() {
	check_edge = one_cnt = ecnt = _ecnt = 0;
	memset( ehead, 0, sizeof(ehead) );
	memset( in_deg, 0, sizeof(in_deg) );
}

inline void readin() {
	scanf( "%d", &n );
	for( int i = 1, tmp; i <= n; i ++ ) {
		scanf( "%d", &tmp );
//		scanf( "%d", &a[i] );
		a[tmp] = i;
	}
	for( int i = 1, u, v; i < n; i ++ ) {
		scanf( "%d%d", &u, &v );
		in_deg[u] ++, in_deg[v] ++;
		add_edge( u, v );
		add_edge( v, u );
	}
	check_edge = true;
	for( int i = 1; i <= n; i ++ ) {
		if( in_deg[i] > 2 )  
			check_edge = false;
		if( in_deg[i] == 1 ) 
			one_cnt ++;
		if( one_cnt > 2 ) 
			check_edge = false;
	}
}

int main() {
	freopen( "tree.in", "r", stdin );
	freopen( "tree.out", "w", stdout );

	scanf( "%d", &T );
	while( T-- ) {
		init();
		readin();
//		if( flag_edge ) 
//			check_edge::work();
//		else 
		bf::work();
	}

	fclose( stdin );
	fclose( stdout );
	return 0;
}
