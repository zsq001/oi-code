#include "cstdio"
#include "iostream"

using namespace std ;
typedef long long QAQ ;
const int maxN = 1e5 + 1e3 ;

int A[ maxN ] , B[ maxN ] ;
QAQ Ans ; 

inline int INPUT ( ) {
        int x = 0 , f = 1 ; char ch = getchar ( ) ;
        while ( ch < '0' || '9' < ch ) { if( ch == '-' ) f = -1 ; ch = getchar ( ) ; }
        while ( '0' <= ch && ch <= '9' ) { x = ( x << 1 ) + ( x << 3 ) + ch - '0' ; ch = getchar ( ) ; }
        return x * f ;   
}

int main ( ) {
        freopen ( "match.in" , "r" , stdin ) ; freopen ( "match.out" , "w" , stdout ) ;
        int N = INPUT ( ) , M = INPUT ( ) , X = INPUT ( ) , Y = INPUT ( ) ;
        for ( int i=1 ; i<=N ; ++i ) A[ i ] = INPUT ( ) ;
        for ( int i=1 ; i<=M ; ++i ) B[ i ] = INPUT ( ) ;
        int t1 = 1 , t2 = 1 ; 
        while ( true ) {
                int L = A[ t1 ] - X ; int R = A[ t1 ] + Y ; 
                while ( t1 <= N && t2 <= M ) {
                        if ( B[ t2 ] < L ) ++t2 ; 
                        else if ( B[ t2 ] > R ) {++t1 ;break ;}
                        else if ( L <= B[ t2 ] && B[ t2 ] <= R ) {++ t1 ; ++ t2 ;++ Ans ; break ; }
                }
                if ( t1 > N || t2 > M ) break ; 
        }
        cout << Ans << endl ; 
        return 0 ; 
}
