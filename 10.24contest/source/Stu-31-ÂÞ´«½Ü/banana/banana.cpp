#include <cstdio>
#include <cstring>

#include <algorithm>

const int _N = 1e3 + 5;
const int _K = 2e4 + 5;
const int mod = 1e9 + 7;

inline void add( int &a, int b ) {
	a += b;
	if( a >= mod ) 
		a -= mod;
}

int T;
int n, k, d_cnt, m_num;
int f[_K], g[_K], d[_K], a[_N], id1[ _K >> 1 ], id2[ _K >> 1 ];

void sq( int now ) {
	d_cnt = 0;
	for( int i = 1; i * i <= k; i ++ ) {
		if( now % i == 0 ) {
			m_num = i;
			d[ ++ d_cnt ] = i;
			if( now / i != i )
				d[ ++ d_cnt ] = now / i;
		}
	}
}

void readin() {
	scanf( "%d%d", &n, &k );
	for( int i = 1; i <= n; i ++ ) {
		scanf( "%d", &a[i] );
	}
}

void init() {
	sq( k );
	memset( f, 0, sizeof(f) );
	memset( g, 0, sizeof(g) );
	std::sort( d + 1, d + d_cnt + 1 );
	for( int i = 1; i <= d_cnt; i ++ ) {
		if( d[i] <= m_num ) 
			id1[ d[i] ] = i;
		else 
			id2[ k / d[i] ] = i;
	}
}

inline int get_id( int now ) {
	if( now <= m_num )
		return id1[now];
	else
		return id2[ k / now ];
}

void dp() {
	f[1] = g[1] = 1;
	for( int i = 1; i <= n; i ++ ) {
		if( k % a[i] != 0 ) 
			continue;
		for( int j = 1; j <= d_cnt; j ++ ) {
			if( 1LL * d[j] * a[i] > k ) 
				break;
			if( g[j] == 0 || k % ( d[j] * a[i] ) != 0 ) 
				continue;
			if( int tmp = get_id( d[j] * a[i] ) )
				add( f[tmp], g[j] );
		}
		for( int j = 1; j <= d_cnt; j ++ ) {
			g[j] = f[j];
		}
	}
	printf( "%d\n", g[ d_cnt ] );
}

int main() {
	freopen( "banana.in", "r", stdin );
	freopen( "banana.out", "w", stdout );

	scanf( "%d", &T );
	while( T -- ) {
		readin();
		init();
		dp();
	}

	fclose( stdin );
	fclose( stdout );
	return 0;
}
