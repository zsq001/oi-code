#include <cstdio>
#include <cstring>

#include <queue>

const double eqs = 1e-6;
const double INF = 1e9;
const int N = 210;
const int M = 2100;

int n, m;

struct edge {
	int to, next;
	double val;
} e[M];
int ehead[N], ecnt;
inline void add_edge( int now, int to, double val ) {
	ecnt ++;
	e[ecnt].to = to;
	e[ecnt].next = ehead[now];
	e[ecnt].val = val;
	ehead[now] = ecnt;
}

double dis[N];
bool vis[N];

bool check( double mid ) {
	for( int i = 1; i <= n; i ++ )
		dis[i] = INF;
	memset( vis, 0, sizeof(vis) );
	std::queue<int> q;
	vis[1] = true; dis[1] = -mid;
	q.push(1);
	while( q.empty() == false ) {
		int top = q.front(); q.pop();
		for( int i = ehead[top]; i; i = e[i].next ) {
			if( dis[top] + e[i].val - mid < dis[ e[i].to ] ) {
				dis[ e[i].to ] = dis[top] + e[i].val - mid;
				if( vis[ e[i].to ] == false ) {
					vis[ e[i].to ] = true;
					q.push( e[i].to );
				}
			}
		}
		vis[top] = false;
	}

	return dis[n] <= eqs;
}

int main() {
	freopen( "calabash.in", "r", stdin );
	freopen( "calabash.out", "w", stdout );

	scanf( "%d%d", &n, &m );
	double rig;
	for( int i = 1, u, v, w; i <= m; i ++ ) {
		scanf( "%d%d%d", &u, &v, &w );
		add_edge( u, v, w );
		rig += w;
	}
	
	double left = 0, res = 0;
	while( rig - left >= eqs ) {
		double mid = ( left + rig ) / 2;
		if( check(mid) ) {
			res = mid; 
			rig = mid - eqs;
		}
		else {
			left = mid + eqs;
		}
	}

	printf( "%.4lf", res );

	fclose( stdin );
	fclose( stdout );
	return 0;
}
