#include <cstdio>

int n;
char s[110];
long long res;

int main() {
	freopen( "ball.in", "r", stdin );
	freopen( "bf.out", "w", stdout );

	scanf( "%d", &n );
	scanf( "%s", s );

	while(1) {
		int i;
		for( i = 0; i < n; i ++ ) 
			if( s[i] == 'B' )
				break;
		if( i == n )
			break;
		res ++;
		for( ; i >= 0; i -- ) {
			if( s[i] == 'B' ) 
				s[i] = 'R';
			else 
				s[i] = 'B';
		}
	}

	printf( "%lld\n", res );

	fclose( stdin );
	fclose( stdout );
	return 0;
}
