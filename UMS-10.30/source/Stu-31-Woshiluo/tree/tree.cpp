#include <cstdio>

const int N = 1e5 + 1e4;

inline void swap( int &a, int &b ) { int tmp = a; a = b; b = tmp; }

int n, m;
int _init_val[N];

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

// Graph Start 
int fa[N], son[N], mson[N], dep[N], top[N], id[N], _id[N], id_cnt;
void dfs1( int now, int la ) {
	fa[now] = la; son[now] = 1; 
	dep[now] = dep[la] + 1;
	for( int i = ehead[now]; i; i = e[i].next ) {
		if( e[i].to == la ) 
			continue;
		dfs1( e[i].to, now );
		son[now] += son[ e[i].to ];
		if( son[ e[i].to ] > son[ mson[now] ] ) 
			mson[now] = e[i].to;
	}
}

void dfs2( int now, int la ) {
	id[now] = ++ id_cnt; _id[ id_cnt ] = now;
	if( top[now] == 0 ) 
		top[now] = now;
	if( mson[now] == 0 ) 
		return ;
	top[ mson[now] ] = top[now];
	dfs2( mson[now], now );
	for( int i = ehead[now]; i; i = e[i].next ) {
		if( e[i].to == la || e[i].to == mson[now] ) 
			continue;
		dfs2( e[i].to, now );
	}
}
// Graph End

// Segment Tree Start 
long long tree[ N << 2 ], lazy[ N << 2 ];
inline void push_up( int now ) { tree[now] = tree[ now << 1 ] + tree[ now << 1 | 1 ]; }
inline void push_down( int now, int lson, int rson ) {
	if( lazy[now] ) {
		tree[ now << 1 ] += 1LL * lazy[now] * lson;
		tree[ now << 1 | 1 ] += 1LL * lazy[now] * rson;
		lazy[ now << 1 ] += lazy[now];
		lazy[ now << 1 | 1 ] += lazy[now];
		lazy[now] = 0;
	}
}
void query_add( int from, int to, long long val, int now = 1, int left = 1, int rig = n ) {
	if( from <= left && rig <= to ) {
		tree[now] += val * ( rig - left + 1 );
		lazy[now] += val;
		return ;
	}
	int mid = ( left + rig ) >> 1;
	push_down( now, mid - left + 1, rig - mid );
	if( from <= mid ) 
		query_add( from, to, val, now << 1, left, mid );
	if( to > mid ) 
		query_add( from, to, val, now << 1 | 1, mid + 1, rig );
	push_up( now );
}
long long query_sum( int from, int to, int now = 1, int left = 1, int rig = n ) {
	if( from <= left && rig <= to ) 
		return tree[now];
	int mid = ( left + rig ) >> 1; 
	long long res = 0;
	push_down( now, mid - left + 1, rig - mid );
	if( from <= mid )
		res += query_sum( from, to, now << 1, left, mid );
	if( to > mid ) 
		res += query_sum( from, to, now << 1 | 1, mid + 1, rig );
	return res;
}
void build_tree( int now, int left, int rig ){
	if( left == rig ) {
		tree[now] = _init_val[ _id[left] ];
		return ;
	}
	int mid = ( left + rig ) >> 1;
	build_tree( now << 1, left, mid );
	build_tree( now << 1 | 1, mid + 1, rig );
	push_up( now );
}
// Segment Tree End

void add_subtree( int now, long long val ) { query_add( id[now], id[now] + son[now] - 1, val ); }

long long query( int from, int to = id[1] ) {
	long long res = 0;
	while( top[from] != top[to] ) {
		if( dep[ top[from] ] < dep[ top[to] ] ) 
			swap( from, to );
		res += query_sum( id[ top[from] ], id[from] );
		from = fa[ top[from] ];
	}
	if( dep[from] < dep[to] )
		swap( from, to );
	res += query_sum( id[to], id[from] );
	return res;
}

int main() {
	freopen( "tree.in", "r", stdin );
	freopen( "tree.out", "w", stdout );

	scanf( "%d%d", &n, &m );
	for( int i = 1; i <= n; i ++ ) {
		scanf( "%d", &_init_val[i] );
	}	
	for( int i = 1, u, v; i < n; i ++ ) {
		scanf( "%d%d", &u, &v );
		add_edge( u, v );
		add_edge( v, u );
	}

	dfs1( 1, 0 );
	dfs2( 1, 0 );
	build_tree( 1, 1, n );

	int op, x, y;
	while( m -- ) {
		scanf( "%d", &op );
		if( op == 1 ) {
			scanf( "%d%d", &x, &y );
			query_add( id[x], id[x], y );
		}
		else if( op == 2 ) {
			scanf( "%d%d", &x, &y );
			add_subtree( x, y );
		}
		else {
			scanf( "%d", &x );
			printf( "%lld\n", query( x ) ) ;
		}
	}

	fclose( stdin );
	fclose( stdout );
	return 0;
}
