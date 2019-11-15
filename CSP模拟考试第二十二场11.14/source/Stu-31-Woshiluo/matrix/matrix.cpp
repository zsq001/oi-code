#include <cstdio>

const int NM = 1e5 + 1e3;
const int N = 1e4 + 1e2;
const int Q = 1e6 + 1e3;

int n, m, q, ecnt;
int ans[NM];

struct node {
	int val, next, pre;
} e[ NM << 1 ];
int left_head[N], top_head[N];

struct _ask {
	int op, x, y;
} ask[Q];

inline int hash( int x, int y ) { return ( x - 1 ) * m + y; }

int main() {
	freopen( "matrix.in", "r", stdin );
	freopen( "matrix.out", "w", stdout );
	scanf( "%d%d%d", &n, &m, &q );
	
	// init_edge
	for( int i = 1; i <= n; i ++ ) {
		left_head[i] = ecnt + 1;
		for( int j = 1; j <= m; j ++ ) {
			++ ecnt;
			e[ecnt] = (node) { j, ecnt + 1, ecnt - 1 };
		}
		e[ecnt].next = e[ left_head[i] ].pre = 0;
	}

	for( int i = 1; i <= m; i ++ ) {
		top_head[i] = ecnt + 1;
		for( int j = 1; j <= n; j ++ ) {
			++ ecnt;
			e[ecnt] = (node) { j, ecnt + 1, ecnt - 1 };
		}
		e[ecnt].next = e[ top_head[i] ].pre = 0;
	}

	// Readin query
	for( int i = 1; i <= q; i ++ ) {
		scanf( "%d%d%d", &ask[i].op, &ask[i].x, &ask[i].y );
	}

	// Work

	for( int o = q; o; o -- ) {
		int x = ask[o].x, y = ask[o].y;
		if( ask[o].op == 1 ) {
			int cur = left_head[x];
			while( cur ) {
				int tmp = n * m + ( e[cur].val - 1 ) * n + ask[o].x, val = e[cur].val;
				ans[ hash( x, val ) ] = y;
				e[ e[cur].pre ].next = e[cur].next;
				e[ e[cur].next ].pre = e[cur].pre;
				e[ e[tmp].pre ].next = e[tmp].next;
				e[ e[tmp].next ].pre = e[tmp].pre;
				if( cur == left_head[x] )
					left_head[x] = e[cur].next;
				if( tmp == top_head[val] ) 
					top_head[val] = e[tmp].next;
				cur = e[cur].next;
			}
		}
		else {
			int cur = top_head[ ask[o].x ];
			while( cur ) {
				int val = e[cur].val; int tmp = hash( val, x );
				ans[tmp] = ask[o].y;
				e[ e[cur].pre ].next = e[cur].next;
				e[ e[cur].next ].pre = e[cur].pre;
				e[ e[tmp].pre ].next = e[tmp].next;
				e[ e[tmp].next ].pre = e[tmp].pre;
				if( cur == top_head[x] )
					top_head[x] = e[cur].next;
				if( tmp == left_head[val] ) 
					left_head[val] = e[tmp].next;
				cur = e[cur].next;
			} 
		}
	}

	int cnt = 1;
	for( int i = 1; i <= n; i ++ ) {
		for( int j = 1; j <= m; j ++ ) {
			printf( "%d ", ans[ cnt ++ ] );
		}
		printf( "\n" );
	}

	fclose( stdin );
	fclose( stdout );
	return 0;
}
