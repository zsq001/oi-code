#include <iostream>
#include <cmath>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

int main(int argc, char** argv) {
	int n ;
	long long k  ,result; 
	
	int a[100] ;
	int flag ; 
	//freopen("code.in");
	//freopen(code.out);
	cin>>n>>k;
	result =  pow(2 , n-1);
	if(  k <= result)
		flag = 1;
	else
	{
		flag = 0;
		k = k - result ;
	} 
		
	
	for( int i = n ; i > 0 ; i--)
	{
		if(flag == 1)
		{
			if( k % 2 == 0 )
				a[i] = 1;
			else
				a[i] = 0;
				
		}
		else
		{
			if( k % 2 == 0 )
				a[i] = 0;
			else
				a[i] = 1;
		}
		k=(k+1)/2;
			
	}
	for( int i = 1 ; i <= n ; i ++ )
		cout<< a[i] ;
	return 0;
}
