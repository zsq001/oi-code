#include <cstdio>
#include <cstring>

#include <queue>
#include <algorithm>

inline int Min( int a, int b ) { return a < b? a: b; }
inline int Max( int a, int b ) { return a > b? a: b; }

const int N = 300;
const int INF = 0x3f3f3f3f;

int n, m, Q;
int dis[N], f[N][N], fin_dis[N][N];
bool used[N];

struct node {
	int val, id;
} a[N];
bool cmp( node _a, node _b ) { return _a.val < _b.val; }

// Edge Start 
struct edge {
	int next, to, val;
} e[ N * N ];
int ehead[N], ecnt;
inline void add_edge( int now, int to, int val ) {
	ecnt ++;
	e[ecnt].to = to;
	e[ecnt].val = val;
	e[ecnt].next = ehead[now];
	ehead[now] = ecnt;
}
// Edge End

struct _dis {
	int now, dis;
	bool operator< ( const _dis &b ) const { return this -> dis > b.dis; }
};
bool vis[N];

void dij( int now ) {
	std::priority_queue<_dis> q;
	memset( dis, 0x3f, sizeof( dis ) );
	memset( vis, 0, sizeof( vis ) );
	dis[now] = 0;
	q.push( (_dis){ now, 0 } );
	while( !q.empty() ) {
		_dis top = q.top(); q.pop();
		if( vis[ top.now ] )
			continue;
		vis[ top.now ] = true;
		for( int i = ehead[ top.now ]; i; i = e[i].next ) {
			if( dis[ top.now ] + e[i].val < dis[ e[i].to ] ) {
				dis[ e[i].to ] = dis[ top.now ] + e[i].val;
				if( vis[ e[i].to ] == false )
					q.push( (_dis){ e[i].to, dis[ e[i].to ] } );
			}
		}
	}
}

int main() {
	freopen( "roadtoll.in", "r", stdin );
	freopen( "roadtoll.out", "w", stdout );

	scanf( "%d%d%d", &n, &m, &Q );
	memset( fin_dis, 0x3f, sizeof( fin_dis ) );
	for( int i = 1; i <= n; i ++ ) {
		scanf( "%d", &a[i].val );
		a[i].id = i;
	}
	for( int i = 1, u, v, w; i <= m; i ++ ) {
		scanf( "%d%d%d", &u, &v, &w );
		if( f[u][v] == 0 || f[u][v] > w ) 
			f[u][v] = f[v][u] = w;
	}

	std::sort( a + 1, a + n + 1, cmp );
	
	for( int i = 1; i <= n; i ++ ) {
		used[ a[i].id ] = true;
		for( int j = 1; j <= n; j ++ ) {
			if( used[j] && f[ a[i].id ][j] ) {
				add_edge( a[i].id, j, f[ a[i].id ][j] );
				add_edge( j, a[i].id, f[ a[i].id ][j] );
			}
		}

		dij( a[i].id );

		for( int j = 1; j <= n; j ++ ) {
			if( dis[j] < INF ) 
				fin_dis[ a[i].id ][j] = fin_dis[j][ a[i].id ] = Min( fin_dis[ a[i].id ][j], dis[j] + a[i].val );
			for( int k = j + 1; k <= n; k ++ ) {
				if( dis[k] < INF )
					fin_dis[j][k] = fin_dis[k][j] = Min( fin_dis[j][k], dis[j] + dis[k] + a[i].val );
			}
		}
	}

	int s, t;
	while( Q -- ) {
		scanf( "%d%d", &s, &t );
		printf( "%d\n", fin_dis[s][t] );
	}

	fclose( stdin );
	fclose( stdout );
	return 0;
}
