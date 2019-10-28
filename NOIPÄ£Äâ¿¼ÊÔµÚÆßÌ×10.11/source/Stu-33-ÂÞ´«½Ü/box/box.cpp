#include <cstdio>
#include <cmath>

#include <algorithm>

inline int Min( int a, int b ) { return a < b? a: b; }

const int sqrt_N = 2e5 + 10;

int a;
long long ans = (1LL << 60);
int b[ sqrt_N ], bcnt;

void calc( int now ) {
	int _a = now;
	int tmp = a / _a;

	int res = 0x7fffffff;
	for( int i = 1; i * i <= tmp; i ++ ) {
		if( tmp % i == 0 )
			res = Min( res, ( i + ( tmp / i ) ) );
	}
	long long t = 2LL * ( 1LL * now * res + tmp );
	if( t < ans )
		ans = t;
}

int main() {
	freopen( "box.in", "r", stdin );
	freopen( "box.out", "w", stdout );

	scanf( "%d", &a );

	for( int i = 1; i * i * i <= a; i ++ ) {
		if( a % i == 0 ) {
			calc( i );
			calc( a / i );
		}
	}

	printf( "%lld\n", ans );
	
	fclose( stdin );
	fclose( stdout );
	return 0;
}
