#include <cstdio>

const int N = 100000 + 10;

int n, m, x, y, ans;
int a[N], b[N];

int main() {
	freopen( "match.in", "r", stdin );
	freopen( "match.out", "w", stdout );
	scanf( "%d%d%d%d", &n, &m, &x, &y );
	for( int i = 1; i <= n; i ++ ) {
		scanf( "%d", &a[i] );
	}
	for( int i = 1; i <= m; i ++ ) {
		scanf( "%d", &b[i] );
	}

	int p1 = 1, p2 = 1;
	while( p1 <= n && p2 <= m ) {
		if( a[p1] - x <= b[p2] && b[p2] <= a[p1] + y ) {
			ans ++;
			p1 ++; p2 ++;
		}
		else if( b[p2] < a[p1] - x )
			p2 ++;
		else 
			p1 ++;

	}

	printf( "%d", ans );
	
	fclose( stdin );
	fclose( stdout );
	return 0;
}
