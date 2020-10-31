#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n,m,x,y,z;
	freopen("make.in","r",stdin);
	freopen("calabash10.in","w",stdout);
	scanf("%d%d",&n,&m);
	srand(time(0));
	printf("%d %d\n",n,m);
	for(int i=2;i<=m+1;i++){
		if(i<=n){
			x=rand()%(i-1)+1;
			y=i;
		}
		else{
			y=rand()%(n-1)+2;
			x=rand()%(y-1)+1;
		}
		z=rand()%1000+1;
		printf("%d %d %d\n",x,y,z);
	}
	return 0;
}
