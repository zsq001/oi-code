#include <cstdio>

const int N = 2e5 + 10;

int n, cnt;
int a[N];
int ans[2];

int main() {
	freopen( "square.in", "r", stdin );
	freopen( "square.out", "w", stdout );
	scanf( "%d", &n );
	for( int i = 1; i <= n; i ++ ) {
		scanf( "%d", &a[i] );
		ans[ i & 1 ] += a[i];
	}
	if( ans[0] > ans[1] ) {
		int tmp = ans[0] - ans[1];
		for( int i = 1; i <= n; i ++ ) {
			if( ( i & 1 ) == 0 ) {
				if( a[i] == tmp ) 
					cnt ++;
			} 
		}
	}
	else {
		int tmp = ans[1] - ans[0];
		for( int i = 1; i <= n; i ++ ) {
			if( ( i & 1 ) == 1 ) {
				if( a[i] == tmp ) 
					cnt ++;
			}
		}
	}
	printf( "%d", cnt );
	fclose( stdin );
	fclose( stdout );
	return 0;
}
