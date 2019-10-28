#include <cstdio>
#include <cstdlib>

const int N = 3100;

int n, m;
int map[N][N], dep[N][N];
int dx[4] = { 0, 0, +1, -1 };
int dy[4] = { +1, -1, 0, 0 };
bool vis[N][N];

void dfs( int x, int y, int depth) {
	vis[x][y] = true;
	dep[x][y] = depth;
	for( int i = 0; i < 4; i ++ ) {
		int tx = x + dx[i];
		int ty = y + dy[i];
		if( tx <= 0 || ty <= 0 || tx > n || ty > m  )
			continue;
		if( map[tx][ty] != map[x][y] )
			continue;
		
		if( vis[tx][ty] ) {
			if( depth - dep[tx][ty] + 1 >= 4 ) {
				printf( "Yes" );
				exit(0);
			}
		}
		else 
			dfs( tx, ty, depth + 1 );
	}
}

int main() {
	freopen( "chess.in", "r", stdin );
	freopen( "chess.out", "w", stdout );
	scanf( "%d%d", &n, &m );
	int x, y;
	x = y = 1;
	char c;
	while( c = getchar() ) {
		if( c <= 0 ) 
			break;
		if( c >= 'A' && c <= 'Z' ) {
			map[x][y] = c -'A' + 1;
			y++;
			if( y > m ) 
				y = 1, x ++;
		}
	}
	
	for( int i = 1; i <= n; i ++ ) {
		for( int j = 1; j <= m; j ++ ) {
			if( vis[i][j] == false ) {
				dfs( i, j, 0 );
			}
		}
	}
	printf( "No" );
	fclose( stdin );
	fclose( stdout );
	return 0;
}
