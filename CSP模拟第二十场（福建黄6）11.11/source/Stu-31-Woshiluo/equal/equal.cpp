#include <cstdio>

inline void swap( int &a, int &b ) { int tmp = a; a = b; b = tmp; }

const int N = 1e5 + 1e2;

int n, m;

// Graph Start
// // Edge Start 
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
// // Edge End
int fa[N], dep[N], dis[N], son[N], mson[N], top[N], id[N], _id[N], id_cnt;
void dfs1( int now, int la ) {
	fa[now] = la; dep[now] = dep[la] + 1;
	son[now] = 1;

	for( int i = ehead[now]; i; i = e[i].next ) {
		if( e[i].to == la ) 
			continue;
                dis[ e[i].to ] = dis[now] + 1;
		dfs1( e[i].to, now );
		son[now] += son[ e[i].to ];
		if( son[ e[i].to ] > son[ mson[now] ] ) 
			mson[now] = e[i].to;
	}
}

void dfs2( int now, int la ) {
	id[now] = ++ id_cnt;
	_id[ id_cnt ] = now;
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

int lca( int from, int to ) {
	while( top[from] != top[to] ) {
		if( dep[ top[from] ] < dep[ top[to] ] )
			swap( from, to );
		from = fa[ top[from] ];
	}
	return dep[from] < dep[to]? from: to;
}

int find_fa( int now, int depth ) {
	while( dep[ top[now] ] > depth )
		now = fa[ top[now] ];
	return _id[ id[now] - ( dep[now] - depth ) ];
}
// Graph End

int main() {
	freopen( "equal.in", "r", stdin );
	freopen( "equal.out", "w", stdout );

	scanf( "%d", &n );
	for( int i = 1, u, v; i < n; i ++ ) {
		scanf( "%d%d", &u, &v );
		add_edge( u, v );
		add_edge( v, u );
	}

	dfs1( 1, 0 );
	dfs2( 1, 0 );
	
	scanf( "%d", &m );
	for( int i = 1, u, v; i <= m; i ++ ) {
		scanf( "%d%d", &u, &v );
		// dep[v] >= dep[u]
		if( dep[u] > dep[v] )
			swap( u, v );
		int tmp = lca( u, v );
		int _dis = dis[u] + dis[v] - dis[tmp];
		if( u == v )
			printf( "%d\n", n );
		if( _dis & 1 ) {
			printf( "%d\n", 0 );
			continue;
		}
		else {
			_dis >>= 1;
			int wanted_dep = dep[v] - _dis, to_u, to_v;
			if( wanted_dep == tmp ) {
				to_u = find_fa( u, wanted_dep + 1 ), to_v = find_fa( v, wanted_dep + 1 );
				printf( "%d\n", n - son[to_u] - son[to_v] );
			}
			else {
				to_v = find_fa( v, wanted_dep + 1 ); 
				printf( "%d\n", son[ fa[to_v] ] - son[to_v] );
			}
		}
	}
	fclose( stdin );
	fclose( stdout );
	return 0;
}
