#include <cstdio>
#include <cstring>

template <class T> 
T Max( T _a, T _b ) { return _a > _b? _a: _b; }
template <class T> 
void chk_max( T &_a, T _b ) { if( _b > _a ) _a = _b; }

const int K = 110;

int n, _k, _c, _w;
double k, c, w;
double pow_k[K], pow_c[K];
double f[2][K][K];

struct node {
	int type;
	double val;
} b[K];

int main() {
	freopen( "coal.in", "r", stdin );
	freopen( "coal.out", "w", stdout );

	scanf( "%d%d%d%lf", &n, &_k, &_c, &w );

	if( _k == 100 ) {
		double res = 0;
		for( int i = 1; i <= n; i ++ ) {
			scanf( "%d%lf", &b[i].type, &b[i].val );
			chk_max( res, b[i].val );
		}
		printf( "%.2lf\n", res );
		return 0;
	}

	for( int i = 1; i <= n; i ++ ) {
		scanf( "%d%lf", &b[i].type, &b[i].val );
	}

	k = _k / 100.0, c = _c / 100.0;
	f[1][0][0] = 0;
	pow_k[0] = pow_c[0] = 1;
	for( int i = 1; i <= n; i ++ ) {
		pow_k[i] = pow_k[ i - 1 ] * ( 1.0 - k );
		pow_c[i] = pow_c[ i - 1 ] * ( 1.0 + c );
	}
	for( int i = 0; i < K; i++ ) {
		for( int j = 0; j < K; j ++ ) {
			f[1][i][j] = -1e9;
		}
	}
	f[1][0][0] = 0;
	for( int cur = 0, last = 1, o = 1; o <= n; o ++, cur ^= 1, last ^= 1 ) {
		for( int i = 0; i < K; i ++ ) {
			for( int j = 0; j < K; j ++ ) {
				f[cur][i][j] = f[last][i][j];
			}
		}

		for( int i = 0; i < n; i ++ ) {
			for( int j = 0; j < n; j ++ ) {
				int cur_mag = w * pow_k[i] * pow_c[j];
				if( b[o].type == 1 ) 
					chk_max( f[cur][ i + 1 ][j], f[last][i][j] + cur_mag * b[o].val );
				else if( f[last][i][j] < cur_mag * b[o].val ) 
					chk_max( f[cur][i][ j + 1 ], f[last][i][j] - cur_mag * b[o].val );
			}
		}
	}

	double ans = 0;
	for( int i = 0; i <= n; i ++ ) {
		for( int j = 0; j <= n; j ++ ) {
			chk_max( ans, Max( f[0][i][j], f[1][i][j] ) );
		}
	}

	printf( "%.2lf\n", ans );

	fclose( stdin );
	fclose( stdout );
	return 0;
}
