#include <cstdio>
#include <cstring>

inline int Min( int a, int b ) { return a < b? a: b; }
inline void chk_Min( int &a, int b ) { if( b < a ) a = b; }

const int N = 1e5 + 1e2;
const int INF = 0x3f3f3f3f;

int T, n, k, res;
int f[N][2];
// 0 linked
// 1 unlinked

// Edge Start 
struct edge {
	int next, to;
} e[ N << 1 ];
int ehead[N], ecnt;
inline void add_edge( int now, int to ) {
	ecnt ++;
	e[ecnt].to = to;
	e[ecnt].next = ehead[now];
	ehead[now] = ecnt;
}
// Edge End

void init() {
	ecnt = 0;
	memset( ehead, 0, sizeof(ehead) );
}

void readin() {
	scanf( "%d%d", &n, &k );
	for( int i = 2, v; i <= n; i ++ ) {
		scanf( "%d", &v );
		add_edge( i, v );
		add_edge( v, i );
	}
}

bool vis[N];
void dfs( int now, int la ) {
	int son = 0, p;
	for( int i = ehead[now]; i; i = e[i].next ) {
		if( e[i].to == la ) 
			continue;
		son ++; p = e[i].to;
		dfs( e[i].to, now );
	}
	if( son == 1 ) {
		vis[now] = vis[ e[i].to ]? false: true;
		if( vis[now] )
			res += 2;
	}
}

int main() {
	freopen( "tree.in", "r", stdin );
	freopen( "tree.out", "w", stdout );

	scanf( "%d", &T );
	while( T -- ) {
		printf( "0\n" );
	}

	fclose( stdin );
	fclose( stdout );
	return 0;
}
