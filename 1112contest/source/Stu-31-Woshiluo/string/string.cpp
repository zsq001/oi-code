#include <cstdio>

inline int Min( int a, int b ) { return a < b? a: b; }
inline void chk_min( int &a, int b ) { if( b < a ) a = b; }

const int N = 2e5 + 10;
const int INF = N;

int T;

int n;
int next[N];
char s[N], ns[N];

void readin() { scanf( "%d%s", &n, s + 1 ); }

void work() {
	int p = 0, ans = INF; next[1] = 0;
	for( int i = 2; i <= n; i ++ ) {
		while( p && s[ p + 1 ] != s[i] )
			p = next[p];
		if( s[ p + 1 ] == s[i] ) 
			p ++;
		next[i] = p;
	}
	chk_min( ans, n - next[n] );
	for( int o = 1; o <= n; o ++ ) {
		int tmp = 0;
		for( int j = 1; j <= n; j ++ ) {
			if( j == o )
				continue;
			ns[ ++ tmp ] = s[j];
		}
		p = next[1] = 0;
		for( int i = 2; i <= tmp; i ++ ) {
			while( p && ns[ p + 1 ] != ns[i] ) 
				p = next[p];
			if( ns[ p + 1 ] == ns[i] )
				p ++;
			next[i] = p;
		}
		chk_min( ans, n - 1 - next[ n - 1 ] );
	}
	printf( "%d\n", ans );
}

int main() {
	freopen( "string.in", "r", stdin );
	freopen( "string.out", "w", stdout );

	scanf( "%d", &T );
	while( T -- ) {
		readin();
		work();
	}

	fclose( stdin );
	fclose( stdout );
	return 0;
}
