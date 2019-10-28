#include "cstdio"
#include "algorithm"
#include "iostream"
#include "fstream"
#include "sstream"
#include "cmath"
#include "cstdlib"

using namespace std ;
typedef long long QAQ ;
const QAQ INF = 2147483647 ;

QAQ min_val = INF ; 

inline QAQ gmin ( const QAQ x , const QAQ y ) { return x > y ? y : x ; }

int main ( ) {
        QAQ N , n ; 
        freopen ( "box.in" , "r" , stdin ) ;
        freopen ( "box.out" , "w" , stdout ) ;
        cin >> N ; 
        n = ( QAQ ) cbrt ( ( QAQ ) N ) ;
        for ( QAQ i=1 ; i<=n ; ++i ) 
                for ( QAQ j=1 ; j<= ( QAQ ) sqrt ( ( QAQ ) ( N / i ) ) ; ++j ) 
                        if ( !( N % i ) && !( N % j ) && !( N % ( N / i / j ) ) ) min_val = gmin ( min_val , ( i * j + ( N / j ) + ( N / i ) ) << 1 ) ; 
        cout << min_val << endl ; 
        fclose ( stdin );fclose ( stdout ) ;
        return 0 ; 
} 
