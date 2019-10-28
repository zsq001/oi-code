#include <cstdio>

#include <algorithm>

const int N = 510;

int a[N][ N << 1 ], next[N][ N << 1 ], b[N], t[N];

int n, m, p, acnt, ans;

int main() {
	freopen( "plate.in", "r", stdin );
	freopen( "plate.out", "w", stdout );
	
	scanf( "%d%d%d", &n, &m, &p );
	
	for( int i = 1; i <= n; i++ ) {
		for( int j = 1; j <= m; j ++ ) 
			scanf( "%d", &b[j] );
		std::sort( b + 1, b + m + 1 );
		for( int j = 1; j < m; j ++ ) 
			t[j] = b[ j + 1 ] - b[j];
		t[m] = b[1] + p + 1 - b[m];
		
		bool flag = false;
		for( int j = 1; j <= acnt; j ++ ) {
			int p1 = 0, p2 = 0;
			while( p2 <= ( 2 * m ) && p1 <= m ) {
				while( t[ p1 + 1 ] == a[j][ p2 + 1 ] && p1 < m  && p2 < ( 2 * m ) )
					p1 ++, p2 ++;
				if( p1 >= m ) {
					flag = true;
					ans ++;
					break;
				} 
				if(p2) 
					p2 = next[j][p2];
				else
					p1 ++;
			}
		}
		
		if( flag == false ) {
			acnt ++;
			for( int i = 1; i <= m; i ++ )
				a[acnt][i] = a[acnt][ i + m ] = t[i];
			int p1 = 1, p2 = 0; next[acnt][1] = 0;
			while( p1 <= ( 2 * m ) ) {
				if( a[acnt][ p1 + 1 ] == a[acnt][ p2 + 1 ] ) {
					p1 ++; p2 ++;
					next[acnt][p1] = p2;
				}
				else if( p2 == 0 ) 
					p1 ++;
				else 
					p2 = next[acnt][p2];
			}
		}

	}
	
	printf( "%d", ans );
	
	fclose( stdin );
	fclose( stdout );
	return 0;

}
