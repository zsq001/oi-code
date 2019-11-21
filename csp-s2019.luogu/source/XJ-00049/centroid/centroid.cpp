#include <cstdio>
#include <cstring>

#include <iostream>

inline int Max( int a, int b ) { return a > b? a: b; }

const int N = 3e5 + 1e2;

int T;
int n;
bool flag_edge;

// Edge Start 
struct edge {
	int to, next;
} e[ N << 1 ];
int ehead[N], ecnt;
inline void add_edge( int now, int to ) {
	ecnt ++;
	e[ecnt].to = to;
	e[ecnt].next = ehead[now];
	ehead[now] = ecnt;
}
// Edge End

inline void init() {
	ecnt = flag_edge = 0;
	memset( ehead, 0, sizeof( ehead ) );
}

void readin() {
	scanf( "%d", &n );
	for( int i = 1, u, v; i < n; i ++ ) {
		scanf( "%d%d", &u, &v );
		add_edge( u, v );
		add_edge( v, u );
	}
}

namespace sub_bf {
	bool vis[ N << 1 ];
	int rt, mson[N], son[N];
	long long ans;
	void dfs( int now, int la ) {
		son[now] = 1;
		for( int i = ehead[now]; i; i = e[i].next ) {
			if( vis[i] || e[i].to == la ) 
				continue;
			dfs( e[i].to, now );
			son[now] += son[ e[i].to ];
		}
	}
	void dfs2( int now, int la ) {
		for( int i = ehead[now]; i; i = e[i].next ) {
			if( vis[i] || e[i].to == la ) 
				continue;
			dfs2( e[i].to, now );
			mson[now] = Max( mson[now], son[ e[i].to ] );
		}
		mson[now] = Max( mson[now], son[rt] - son[now] );
		if( mson[now] <= ( son[rt] >> 1 ) )
			ans += 1LL * now;
		
	}
	void work() {
		ans = 0;
		for( int i = 1; i <= ecnt; i += 2 ) {
			vis[i] = vis[ i + 1 ] = true;
			memset( son, 0, sizeof(son) );
			memset( mson, 0, sizeof(mson) );
			rt = e[i].to;
			dfs( e[i].to, 0 );
			dfs2( e[i].to, 0 );
			rt = e[ i + 1 ].to;
			dfs( e[ i + 1 ].to, 0 );
			dfs2( e[ i + 1 ].to, 0 );
			vis[i] = vis[ i + 1 ] = false;
		}
		std::cout << ans << std::endl;
	}
}

namespace sub_edge {
	void work() {}
}

int main() {
	freopen( "centroid.in", "r", stdin );
	freopen( "centroid.out", "w", stdout );

	scanf( "%d", &T );
	while( T -- ) {
		init();
		readin();
		if( flag_edge ) 
			sub_edge::work();
		else 
			sub_bf::work();
	}

	fclose( stdin );
	fclose( stdout );
	return 0;
}
