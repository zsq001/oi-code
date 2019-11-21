#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;


int treeSearch()
{
	int a[2000][2] ;
	int b[2000] , index = 0 ;
	int n ;
	cin >> n ;
	for( int i = 1 ; i <= n ; i++ )
	{
		a[i][1] = 0 ;
		b[i] =0;
	}
	for( int i = 1 ; i <=  n ; i ++ )
	{
		int number ;
		cin>> number ;
		a[i][0] = number ;
		b[number] = i ;
		
	}
	for( int i = 1 ; i < n ; i++)
	{
		int start , end ;
		cin>> start >>end;
		a[end][1] = start ; 
	}
	
	
	for(int i = 1 ; i <= n ; i++)
	{
		int start_node , end_node ;
		end_node = b[i] ;
		
		while( a[end_node][1] != 0 )
		{
			int tmpValue = a[end_node][0] ;
			start_node = a[end_node][1] ;
			a[end_node][0] = a[start_node][0];
			a[start_node][0]= tmpValue ;
			a[end_node][1] = 0 ;
			b[a[end_node][0]] = end_node;
			b[a[start_node][0]] = start_node;
			end_node = start_node ;	
		}
	}
	
	
	for( int i = 1 ; i <= n ; i ++)
	{
		cout << a[b[i]][0] <<" ";
	}
}

int main(int argc, char** argv) {
	treeSearch();
	return 0;
}
