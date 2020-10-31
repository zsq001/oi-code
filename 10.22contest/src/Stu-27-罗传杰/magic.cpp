#include <cstdio>

const int mod = 1e9 + 7;

int ksm( int a, int p ) {
	int res = 1;
	while( p ) {
		if( p & 1 )
			res = ( 1LL * res * a ) % mod;
		a = ( 1LL * a * a ) % mod;
		p >>= 1;
	}
	return res;
}

int n;

int main() {
	freopen( "magic.in", "r", stdin );
	freopen( "magic.out", "w", stdout );
	scanf( "%d", &n );
	printf( "%d", ( ( ( ( ( ( 1LL * ksm( 3, n + 1 ) ) - 1LL ) * ksm( 2, mod - 2 ) ) % mod ) + mod ) % mod ) );
	fclose( stdin );
	fclose( stdout );
	return 0;
}
