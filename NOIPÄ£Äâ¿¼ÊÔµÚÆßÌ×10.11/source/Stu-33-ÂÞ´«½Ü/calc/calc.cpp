#include <cstdio>
#include <cstring>

const int N = 2100;

struct seg {
	int left, rig;
} a[ N * N ];

int seg_cnt, len;
int sum_rig[N];
char str[N];
long long ans;

int main() {
	freopen( "calc.in", "r", stdin );
	freopen( "calc.out", "w", stdout );
	scanf( "%s", str + 1 );
	len = strlen( str + 1 );

	// len % 2 == 1 
	for( int i = 1, left, rig; i <= len; i ++ ) {
		left = rig = i;
		while( str[left] == str[rig] ) {
			a[ ++ seg_cnt ] = (seg) {left, rig};
			left --, rig ++;
			if( left <= 0 || rig > len )
				break;
		}
	}

	// len % 2 == 0 
	for( int i = 1, left, rig; i < len; i ++ ) {
		left = i, rig = i + 1;
		while( str[left] == str[rig] ) {
			a[ ++ seg_cnt ] = (seg) {left, rig};
			left --, rig ++;
			if( left <= 0 || rig > len )
				break;
		}
	}

	for( int i = 1; i <= seg_cnt; i ++ ) {
		sum_rig[ a[i].rig ] ++;
	}

	for( int i = 1; i <= len; i ++ ) { 
		sum_rig[i] += sum_rig[ i - 1 ];
	}

	for( int i = 1; i <= seg_cnt; i ++ ) {
		ans += 1LL * sum_rig[ a[i].left - 1 ];
	}

	printf( "%lld\n", ans );

	fclose( stdin );
	fclose( stdout );
}
