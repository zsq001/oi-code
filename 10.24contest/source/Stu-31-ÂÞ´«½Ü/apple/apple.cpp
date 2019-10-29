#include <cstdio>

#include <queue>

const int N = 5e4 + 1e2;

int n, k;

// Edge Start 
struct edge {
	int to, next;
} e[ N << 1 ];
int ehead[N], ecnt; 
inline void add_edge( int now, int to ) {
	ecnt ++;
	e[ecnt].to = to;
	e[ecnt].next = ehead[now];
	ehead[now] = ecnt;
}

struct node {
	int now, val;
	bool operator< ( const node &b )const { 
		if( this -> val == b.val )
			return this -> now > b.now;
		return this -> val < b.val; 
	}
};
// Edge End

int son[N], mson[N], fa[N], ans;
bool vis[N];

std::priority_queue<node> q;

void dfs( int now, int la ) {
	fa[now] = la; son[now] = 1;
	for( int i = ehead[now]; i; i = e[i].next ) {
		if( e[i].to == la ) 
			continue;
		dfs( e[i].to, now );
		if( son[ e[i].to ] > son[ mson[now] ] ) 
			mson[now] = e[i].to;
		if( son[ e[i].to ] == son[ mson[now] ] )
			mson[now] = mson[now] < e[i].to? mson[now]: e[i].to;
	}
	son[now] += son[ mson[now] ];
}

void get_mson( int now ) {
	vis[now] = true;
	for( int i = ehead[now]; i; i = e[i].next ) {
		if( e[i].to == fa[now] || e[i].to == mson[now] ) 
			continue;
		q.push( (node){ e[i].to, son[ e[i].to ] } );
	}
	if( mson[now] == 0 ) 
		printf( "%d\n", now - 1 );
	else 
		get_mson( mson[now] );
}

int main() {
	freopen( "apple.in", "r", stdin );
	freopen( "apple.out", "w", stdout );

	scanf( "%d%d", &n, &k );
	k ++;
	for( int i = 1, v; i < n; i ++ ) {
		scanf( "%d", &v );
		v ++;
		add_edge( i + 1, v );
		add_edge( v, i + 1 );
	}

	vis[k] = true;

	dfs( k, 0 );

	for( int i = ehead[k]; i; i = e[i].next ) 
		q.push( (node){ e[i].to, son[ e[i].to ] } );

	printf( "%d\n", k - 1 );
	while( !q.empty() ) {
		node top;
		while( !q.empty() ) {
			top = q.top();
			q.pop();
			if( vis[ top.now ] == false )
				break;
		}
		get_mson( top.now );
	}

	fclose( stdin );
	fclose( stdout );
	return 0;
}
