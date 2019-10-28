#include<ctime>
#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
	int x=time(0);
	while(1)
{
	
	if(x!=time(0))
		{
			cout<<time(0)<<endl;
			x=time(0);
		
		}
}
	return 0;
}
