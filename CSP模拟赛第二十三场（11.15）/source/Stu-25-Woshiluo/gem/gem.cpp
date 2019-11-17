#include <cstdio>
#include <cstring>

inline int Max( int a, int b ) { return a > b? a: b; }

int n, m, ans;
int a[1100], f[1100][2];
// 0 buy

int main() {
	freopen( "gem.in", "r", stdin );
	freopen( "gem.out", "w", stdout );
	
	scanf( "%d%d", &n, &m );
	for( int i = 1; i <= n; i ++ ) {
		scanf( "%d", &a[i] );
	}
	int op, l, r, x, y;
	while( m -- ) {
		scanf( "%d", &op );
		if( op == 1 ) {
			scanf( "%d%d", &l, &r );
			memset( f, 0, sizeof(f) ); ans = 0;
			for( int i = l; i <= r; i ++ ) {
				f[i][0] = -a[i];
				for( int j = l; j < i; j ++ ) {
					f[i][0] = Max( f[i][0], f[j][1] - a[i] );
					f[i][1] = Max( f[i][1], f[j][0] + a[i] );
				}
				ans = Max( ans, Max( f[i][0], f[i][1] ) );
			}
			printf( "%d\n", ans );
		}
		else {
			scanf( "%d%d%d%d", &l, &r, &x, &y );
			for( int i = l; i <= r; i ++ ) {
				a[i] = x;
				x += y;
			}
		}
	}
	
	printf( "%d", ans );
	
	fclose( stdin );
	fclose( stdout );
	return 0;
}
