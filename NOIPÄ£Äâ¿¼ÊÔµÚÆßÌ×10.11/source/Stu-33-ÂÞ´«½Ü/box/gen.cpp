#include <ctime>
#include <cstdio>
#include <cstdlib>

int main() {
	int a;
	freopen( "box.in", "r", stdin );
	scanf( "%d", &a );
	freopen( "box.in", "w", stdout );
//	srand( time(0) );

	printf( "%d", a + 1 );
	if( a + 1 >= 10000 )
		return 1;
}
