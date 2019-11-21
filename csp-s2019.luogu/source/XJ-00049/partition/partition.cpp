#include <cstdio>

#include <vector>
#include <iostream>

inline int Max( int a, int b ) { return a > b? a: b; }
inline long long squ( long long a ) { return a * a; }
inline void chk_min( long long &a, long long b ) { if( b < a ) a = b; }

const int N = 5100;
const int long long MAX = 4e18;

struct node {
	int rig, j; 
	long long ans;
} q[ ( N * N ) >> 1 ];

int n, type;
int a[N];
int q_cnt, tmp_cnt;
long long ans, _min[N], sum[N];

int main() {
	freopen( "partition.in", "r", stdin );
	freopen( "partition.out", "w", stdout );

	scanf( "%d%d", &n, &type );
	ans = MAX + 1;
	for( int i = 1; i <= n; i ++ ) {
		scanf( "%d", &a[i] );
		sum[i] = sum[ i - 1 ] + ( 1LL * a[i] );
		_min[i] = MAX + 1LL;
	}
	_min[0] = MAX + 1LL;
	q[ ++ q_cnt ] = (node) { 0, 0, 0 };
	for( int i = 1; i <= n; i ++ ) {
		for( int k = 1; k <= q_cnt; k ++ ) {
			long long tmp = sum[i] - sum[ q[k].rig ];
			if( tmp >= sum[ q[k].rig ] - sum[ Max( q[k].rig - q[k].j - 1, 0 ) ] ) {
				if( q[k].ans + squ(tmp) > MAX )
					continue;
				chk_min( _min[ i - q[k].rig - 1 ], q[k].ans + squ(tmp) );
			}
		}
		long long less = MAX + 1LL;
		for( int j = 0; j <= i; j ++ ) {
			if( _min[j] <= MAX ) {
				if( i == n ) 
					chk_min( ans, _min[j] );
				if( _min[j] < less ) {
					q[ ++ q_cnt ] = (node){ i, j, _min[j] };
					less = _min[j];
				}
				_min[j] = MAX + 1LL;
			}
		}
	}
	
//	printf( "%lld", ans );
	std::cout << ans;

	fclose( stdin );
	fclose( stdout );
	return 0;
}
