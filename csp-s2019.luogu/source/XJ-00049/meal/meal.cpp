#include <cstdio>

const int N = 110;
const int K = 2100;
const int mod = 998244353;

inline int pow_2( int now ) { return 1 << now; }
inline int full_bit( int now ) { return ( 1 << now ) - 1; }

inline void add_eq( int &a, int b ) { a += b; if( a >= mod ) a -= mod; }
inline int mul( int a, int b ) { return ( 1LL * a * b ) % mod; }

int n, m, ans;
int a[N][K];

namespace sub_m_eq2 {
	const int _N = 410;
	int f[_N][_N][_N];
	void work() {
		for( int j = 1; j <= n; j ++ ) {
			add_eq( f[1][j][1], a[j][1] );
		}
		for( int i = 2; i <= n; i ++ ) {
			int _max = i / 2;
			for( int j = i; j <= n; j ++ ) {
				for( int k = 1; k < j; k ++ ) {
					for( int l = 1; l <= i; l ++ ) {
						if( l + 1 <= _max && i - l - 1 <= _max )
							add_eq( f[i][j][ l + 1 ], mul( f[ i - 1 ][k][l], a[j][1] ) );
						if( i - l <= _max && l <= _max ) 
							add_eq( f[i][j][l], mul( f[ i - 1 ][k][l], a[j][2] ) );
					}
				}
				for( int l = 1; l <= _max; l ++ ) {
					add_eq( ans, f[i][j][l] );
				}
			}
		}
		printf( "%d\n", ans );
	}
}

int main() {
	freopen( "meal.in", "r", stdin );
	freopen( "meal.out", "w", stdout );

	scanf( "%d%d", &n, &m );
	for( int i = 1; i <= n; i ++ ) {
		for( int j = 1; j <= m; j ++ ) {
			scanf( "%d", &a[i][j] );
		}
	}

	if( m == 2 ) 
		sub_m_eq2::work();
	else 
		printf( "0" );

	fclose( stdin );
	fclose( stdout );
	return 0;
}
