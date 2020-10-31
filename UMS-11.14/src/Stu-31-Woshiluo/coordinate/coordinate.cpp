#include <cstdio>
#include <cstring>

//const int N = 1e6 + 1e2;
const int mod = 1e9 + 7;

inline int add( int a, int b ) { a += b; return a >= mod? a - mod: a; }
inline int mul( int a, int b ) { return ( 1LL * a * b ) % mod; }

int n;
//int f[N];

struct mat {
	int f[2][2];
	mat() { memset( f, 0, sizeof(f) ); } 
	int* operator[] ( int now ) { return f[now]; }
	mat operator* ( mat b ) {
		mat res;
		for( int i = 0; i < 2; i ++ ) {
			for( int j = 0, tmp; j < 2; j ++ ) {
				tmp = 0;
				for( int k = 0; k < 2; k ++ ) {
					tmp = add( tmp, mul( f[i][k], b[k][j] ) );
				}
				res[i][j] = tmp;
			}
		}
		return res;
	}
}; 

mat ksm( mat a, int p ) {
	mat res;
	res[0][0] = res[1][1] = 1;
	while(p) {
		if( p & 1 ) 
			res = res * a;
		a = a * a;
		p >>= 1;
	}
	return res;
}

int main() {
	freopen( "coordinate.in", "r", stdin );
	freopen( "coordinate.out", "w", stdout );
	
	scanf( "%d", &n );
	if( n == 1 ) {
		printf( "3" );
		return 0;
	}
	if( n == 0 ) {
		printf( "1" );
		return 0;
	}

	mat a, b;
	a[0][0] = 3, a[0][1] = 1;
	b[0][1] = b[1][0] = 1, b[0][0] = 2;

	printf( "%d\n", ( a * ksm( b, n - 1 ) )[0][0] );

	fclose( stdin );
	fclose( stdout );
	return 0;
}
