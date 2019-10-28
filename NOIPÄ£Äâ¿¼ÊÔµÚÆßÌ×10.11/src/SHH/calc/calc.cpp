#include "cstdio"
#include "cstring"
#include "algorithm"
#include "fstream"
#include "iostream"
#include "sstream"
#include "cstdlib"
#include "cctype"

using namespace std ;
const int maxN = 2e3 + 1e2 ; 
typedef long long QAQ ;

char s[ maxN ] ;
int Judge[ maxN ][ maxN ] ;
int f[ maxN ] ;

inline void Init ( const int n ) {
        for ( int i=0 ; i<n ; ++i ) Judge[ i ][ i ] = true ;
        for(int i=0 ; i<n ; ++i ) {
                for(int L=-1 ; i-L>=0 && i+L<n ; ++L ) {
                        if ( s [ i - L ] != s [ i + L ] ) break;
                        else Judge[ i - L ][ i + L ] = true ; 
                }
                for(int L=-1 ; i-L>=0 && i+L+1<n ; ++L ) {
                        if ( s [ i - L ] != s [ i + L + 1 ] ) break;
                        else Judge[ i - L ][ i + L + 1 ] = true ;
                }
        }
}
int main ( ) {
        freopen ( "calc.in" , "r" , stdin ) ; freopen ( "calc.out" , "w" , stdout ) ;
        scanf ( "%s" , s ) ;int N = strlen ( s ) ;
        Init ( N ) ; 
        f[ 0 ] = 1 ;
        for ( int i=1 ; i<=N-1 ; ++i ) {
                f[ i ] = f[ i - 1 ] ;
                for ( int j=0 ; j<=i ; ++j ) if ( Judge[ j ][ i ] ) ++ f[ i ] ; 
        } 
        unsigned long long Ans = 0 ; 
        for ( int i=1 ; i<N ; ++i ) 
                for ( int j=i ; j<N ; ++j ) 
                        if ( Judge[ i ][ j ] )Ans += f[ i - 1 ] ;
        cout << Ans << endl ;
        return 0 ; 
} 
