#include <cstdio>
//#include <cstring>
#include <algorithm>

inline int Min( int a, int b ) { return a < b? a: b; }

const int N = 110;

int ans, n, jok;
int a[N];

int main() {
	freopen( "poker.in", "r", stdin );
	freopen( "poker.out", "w", stdout );
	
	scanf( "%d%d", &n, &jok );
	for( int i = 1; i <= n; i ++ )
		scanf( "%d", &a[i] );

	std::sort( a + 1, a + n + 1 ) ;
	
	if( jok >= a[2] - a[1] )
		ans += a[2] - a[1], jok -= a[2] - a[1];

	ans += Min( a[1] * 2, jok );
	
	for( int i = 3; i <= n; i ++ )
		ans = Min( ans, a[i] );
		
	printf( "%d\n", ans );
	
	fclose( stdin );
	fclose( stdout );
	return 0;
}
