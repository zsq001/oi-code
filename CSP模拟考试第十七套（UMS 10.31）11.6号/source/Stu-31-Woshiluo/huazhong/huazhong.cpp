#include <cstdio>

#include <stack>
#include <vector>

const int N = 1e6 + 1e1;
const int mod = 1e9 + 7;

inline int add( int a, int b ) { a += b; if( a >= mod ) a -= mod; return a; }
inline void add_eq( int &a, int b ) { a += b; if( a >= mod ) a -= mod; }
inline int mul( int a, int b ) { return ( 1LL * a * b ) % mod; }
inline void mul_eq( int &a, int b ) { a = ( 1LL * a * b ) % mod; }

int n, ans;

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
// Edge End

int f[N], res[N], ex[N], son[N];

void dfs( int now, int la ) {
	f[now] = res[now] = 1;
	std::stack<int> st;
	std::vector<int> sum, _sum;
	_sum.push_back(1), sum.push_back(1);
	for( int i = ehead[now]; i; i = e[i].next ) {
		if( e[i].to == la ) 
			continue;
		son[now] ++;
		st.push( e[i].to );
		dfs( e[i].to, now );
		mul_eq( res[now], f[ e[i].to ] );
		sum.push_back( res[now] );
		_sum.push_back( res[now] );
	}
	if( st.size() == 0 )
		return ;
	_sum[ st.size() + 1 ] = sum[0] = 1;
	while( !st.empty() ) {
		int top = st.top();
		_sum[ st.size() ] = mul( _sum[ st.size() + 1 ], f[top] );
		st.pop();
	}
	int p = 1; 
	for( int i = ehead[now]; i; i = e[i].next ) {
		if( e[i].to == la ) 
			continue;
		ex[ e[i].to ] = mul( sum[ p - 1 ] , _sum[ p + 1 ] );
		p ++;
	}
	f[now] = mul( res[now], 2 );
}

void dfs2( int now, int la, int _res ) {
	add_eq( ans, mul( mul( res[now], _res ), 2 ) );
	for( int i = ehead[now]; i; i = e[i].next ) {
		if( e[i].to == la ) 
			continue;
		int tmp; 
		if( now == n / 3 + 1 && son[now] == 1 )
			tmp = mul( ex[ e[i].to ], _res );
		else 
			tmp = mul( mul( ex[ e[i].to ], _res ), 2 );
		dfs2( e[i].to, now, tmp );
	}
}

int main() {
	freopen( "huazhong.in", "r", stdin );
	freopen( "huazhong.out", "w", stdout );

	scanf( "%d", &n );
	for( int i = 1, u, v; i < n; i ++ ) {
		scanf( "%d%d", &u, &v );
		add_edge( u, v );
		add_edge( v, u );
	}

	dfs( n / 3 + 1, 0 );
	dfs2( n / 3 + 1, 0, 1 );
	
	printf( "%d", ans );

	fclose( stdin );
	fclose( stdout );
	return 0;
}
