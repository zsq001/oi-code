#include <cstdio>

inline int Min( int a, int b ) { return a < b? a: b; }

int a, ans = 0x7fffffff;

int main() {
	freopen( "box.in", "r", stdin );
	freopen( "bf.out", "w", stdout );

	scanf( "%d", &a );
	for( int i = 1; i <= a; i ++ ) {
		if( a % i != 0 )
			continue;
		for( int j = 1; j <= a; j ++ ) {
			if( a % ( i * j ) != 0 ) 
				continue;
			int tmp = a / ( i * j );

			ans = Min( ans, 2 * ( i * j + i * tmp + j * tmp ) );
		}
	}
	printf( "%d", ans );

	fclose( stdin );
	fclose( stdout );
	return 0;
}
