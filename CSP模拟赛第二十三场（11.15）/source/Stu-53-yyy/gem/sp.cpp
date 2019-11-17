#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<windows.h>
#include<time.h>
using namespace std;

int main(){
	freopen("gem.in","w",stdout);
	srand(time(0));
	int n=rand()%100+10;
	int m=rand()%n+1;
	printf("%d %d\n",n,m);
	for(int i=1;i<=n;i++)
		printf("%d ",rand()%100+100);
	puts("");
	for(int i=1;i<=m;i++){
		int r=rand()%n+1;
		int l=rand()%r+1;
		printf("1 %d %d\n",l,r);
	}
	return 0;
}
