#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<windows.h>
#include<time.h>
using namespace std;

bool vis[31];
int main(){
	freopen("ticket.in","w",stdout);
	srand(time(0));
	int n=15;
	int m=rand()%26+1;
	printf("%d %d\n",n,m);
	int t;
	for(int i=1;i<=n;i++){
		t=rand()%26;
		while(vis[t])t=rand()%26;
		printf("%c ",'a'+t);
		vis[t]=1;
	}
	return 0;
}
