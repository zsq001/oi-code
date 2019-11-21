#include <cstdio>

const int N = 5e5 + 1e4;

int n;
long long res, _res[N], ans;
int fa[N], last[N], st[N], st_cnt;
char kuo[N];

struct _st{
	int now, i;
} df[N * 20];
int df_cnt;

// Edge Start 
struct edge {
	int to, next;
} e[N];
int ehead[N], ecnt;
inline void add_edge( int now, int to ) {
	ecnt ++;
	e[ecnt].to = to;
	e[ecnt].next = ehead[now]; 
	ehead[now] = ecnt;
}
// Edge End

void dfs( int now ) {
	if( now == 1 || kuo[now] == '(' )
		_res[now] = 0;
	else {
		int tmp = now;
		while( kuo[ fa[tmp] ] != '(' && tmp != 0 ) {
			st[ ++ st_cnt ] = fa[tmp];
			tmp = last[ fa[tmp] ];
		}
		st_cnt --;
		while( st_cnt > 1 ) {
			last[ st[ st_cnt - 1 ] ] = last[ st_cnt ];
			st_cnt --;
		}
		st_cnt = 0;
		if( tmp == 0 ) 
			_res[now] = 0;
		else {
			_res[now] ++;
			last[now] = fa[tmp];
			if( kuo[ fa[ fa[tmp] ] ] == ')' ) 
				_res[now] += _res[ fa[ fa[tmp] ] ];
		}
	}
	res += _res[now];
	if( now != 1 )
		ans ^= 1LL * now * res;
	for( int i = ehead[now]; i; i = e[i].next ) {
		dfs( e[i].to );
	}
	res -= _res[now];
}

int main() {
	freopen( "brackets.in", "r", stdin );
	freopen( "brackets.out", "w", stdout );

	scanf( "%d", &n );
	scanf( "%s", kuo + 1 );
	for( int i = 2, u; i <= n; i ++ ) {
		scanf( "%d", &u );
		fa[i] = u;
		add_edge( u, i );
	}

//	dfs(1);

	df[ ++ df_cnt ] = (_st){ 1, ehead[1] };
	while( df_cnt != 0 ) {
		_st &top = df[ df_cnt ];
		int now = top.now;
		if( top.i == ehead[now] ) {
			if( now == 1 || kuo[now] == '(' )
				_res[now] = 0;
			else {
				int tmp = now;
				while( kuo[ fa[tmp] ] != '(' && tmp != 0 ) {
					st[ ++ st_cnt ] = fa[tmp];
					tmp = last[ fa[tmp] ];
				}
				while( st_cnt > 1 ) {
					last[ st[ st_cnt - 1 ] ] = last[ st_cnt ];
					st_cnt --;
				}
				st_cnt = 0;
				if( tmp == 0 ) 
					_res[now] = 0;
				else {
					_res[now] ++;
					last[now] = fa[tmp];
					if( kuo[ fa[ fa[tmp] ] ] == ')' ) 
						_res[now] += _res[ fa[ fa[tmp] ] ];
				}
			}
			res += _res[now];
			if( now != 1 )
				ans ^= 1LL * now * res;
		}
		if( top.i != 0 ) {
			df[ ++df_cnt ] = (_st){ e[ top.i ].to, ehead[ e[ top.i ].to ] };
			top.i = e[ top.i ].next;
		}
		else {
			res -= _res[now];
			df_cnt --;
		}
	}

	printf( "%lld", ans );

	fclose( stdin );
	fclose( stdout );
	return 0;
}
