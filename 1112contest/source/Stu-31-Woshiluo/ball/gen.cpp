#include <cstdio>
#include <cstdlib>
#include <ctime>

int n;

int main() {
	freopen( "ball.in", "w", stdout );
	srand( time(0) );
	n = rand() % 20 + 1;
	printf( "%d\n", n );
	for( int i = 1; i <= n; i ++ ) {
		int tmp = rand() % 2;
		if( tmp ) 
			putchar( 'R' );
		else
			putchar( 'B' );
	}
}
