#include <cstdio>
#include <cstdlib>

#include <algorithm>

int n, m, _m, cnt;
char a[30], b[30];
bool vis[210];

void dfs( int dep, int st, bool y, bool p1, bool p2 ) {
	if( dep == n ) {
		if( y && p1 && p2 ) {
			printf( "%s\n", b );
			cnt ++;
		}
		if( cnt > 25000 )
			exit(0);
		return ;
	}
	for( int i = st; i <= m; i ++ ) {
		b[dep] = a[i];
		dfs( dep + 1, i + 1,
			( y || vis[ a[i] ] ),
			( p1 || ( vis[ a[i] ] == false ) ), ( p2 || ( p1 && vis[ a[i] ] == false ) ) );
		b[dep] = 0;
	}
}

int main() {
	freopen( "ticket.in", "r", stdin );
	freopen( "ticket.out", "w", stdout );
	
	vis['a']= vis['e'] = vis['i'] = vis['o'] = vis['u'] = true;
	scanf( "%d%d", &n, &_m );
	m = 1;
	for( int i = 1; i <= _m; i ++ ) {
		scanf( "%s", &a[m] );
		if( a[m] >= 'a' && a[m] <= 'z' )
			m ++;
	}
	m --;
	
	std::sort( a + 1, a + m + 1 );
	
	dfs( 0, 1, false, false, false );
	
	fclose( stdin );
	fclose( stdout );
	return 0;
}
