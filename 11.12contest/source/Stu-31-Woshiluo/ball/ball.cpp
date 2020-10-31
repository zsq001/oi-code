#include <cstdio>

const long long MAX = 1e18;

int n;
long long res;
long long f[110];
char s[110];

int main() {
	freopen( "ball.in", "r", stdin );
	freopen( "ball.out", "w", stdout );

	scanf( "%d", &n );
	scanf( "%s", s );
	f[1] = 1;
	for( int i = 2; i <= n; i ++ ) {
		f[i] = ( f[ i - 1 ] << 1LL ) | 1LL;
	}
	for( int i = 0; i < n; i ++ ) {
		if( s[i] == 'B' ) {
			res += f[ i + 1 ] - f[i];
			if( res > MAX ) {
				printf( "-1\n" );
			}
		}
	}
	printf( "%lld\n", res );

	fclose( stdin );
	fclose( stdout );
	return 0;
}
