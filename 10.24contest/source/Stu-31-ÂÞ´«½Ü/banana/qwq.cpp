#include <cstdio>

#include <algorithm>

const int _N = 1e3 + 5;
const int _K = 2e4 + 5;
const int mod = 1e9 + 7;

inline void add( int &a, int b ) {
	a += b;
	if( a >= mod ) 
		a -= mod;
}

int T;
int n, k, d_cnt;
int f[_N][_K], d[_K], a[_N];

void sq( int now ) {
	d_cnt = 0;
	for( int i = 1; i * i <= k; i ++ ) {
		if( now % i == 0 ) {
			d[ ++ d_cnt ] = i;
			if( now / i != i )
				d[ ++ d_cnt ] = now / i;
		}
	}
}

void readin() {
	scanf( "%d%d", &n, &k );
	for( int i = 1; i <= n; i ++ ) {
		scanf( "%d", &a[i] );
	}
}

void init() {
	sq( k );
	for( int i = 0; i <= n; i ++ ) {
		for( int j = 0; j <= d_cnt; j ++ ) {
			f[i][j] = 0;
		}
	}
	std::sort( d + 1, d + d_cnt + 1 );
}

int find( int now ) {
	int left = 1, rig = d_cnt;
	while( left <= rig ) {
		int mid = ( left + rig ) >> 1;
		if( d[mid] == now )
			return mid;
		else if( d[mid] < now ) 
			left = mid + 1;
		else 
			rig = mid - 1;
	}
	if( d[ left - 1 ] == now ) 
		return left - 1;
	if( d[ left ] == now ) 
		return left;
	if( d[ left + 1 ] == now ) 
		return left + 1;
	return 0;
}

void dp() {
	f[0][1] = 1;
	for( int i = 1; i <= n; i ++ ) {
		for( int j = 1; j <= d_cnt; j ++ ) {
			add( f[i][j], f[ i - 1 ][j] );
			if( d[j] * a[i] > k ) 
				continue;
			if( f[ i - 1 ][j] == 0 ) 
				continue;
			int tmp = find( d[j] * a[i] );
			if(tmp)
				add( f[i][tmp], f[ i - 1 ][j] );
		}
	}
	printf( "%d\n", f[n][ d_cnt ] );
}

int main() {
	freopen( "banana.in", "r", stdin );
	freopen( "banana.out", "w", stdout );
	scanf( "%d", &T );
	while( T -- ) {
		readin();
		init();
		dp();
	}

	fclose( stdin );
	fclose( stdout );
}
