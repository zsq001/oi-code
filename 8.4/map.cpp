#include <map>
#include <cstdio>
#include <string>
using namespace std;

map <string,int> score;

int main(void)
{
	score["rxz"]=0;
	score["ks"]=1000;
	
	printf("%d\n",score["rxz"]);
	printf("%d\n",score["ks"]);
	
	
	return 0;
} 
