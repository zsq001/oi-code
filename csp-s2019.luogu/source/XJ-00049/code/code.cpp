#include <cstdio>
#include <iostream>

int n, cnt;
unsigned long long m, a[70];
char b[110];

int main() {
	freopen( "code.in", "r", stdin );
	freopen( "code.out", "w", stdout );

	std::cin >> n >> m;
	a[0] = 1LL;
	for( int i = 1; i < n; i ++ ) {
		a[i] = a[ i - 1 ] << 1LL;
	}

	int _n = n;
	while(1){
		if( m >= a[ n - 1 ] ) {
			b[ cnt ++ ] = '1';
			m -= a[ n - 1 ];
			m = a[ n - 1 ] - m - 1;
		}
		else 
			b[ cnt ++ ] = '0';
		n --;
		if( cnt == _n ) 
			break;
	}

	printf( "%s", b );

	fclose( stdin );
	fclose( stdout );
	return 0;
}
