#include<ctime>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>

using namespace std;

int get_rand(){
	return (rand()<<15)+rand();
}

int main(){
	freopen("matrix.in","w",stdout);
	
	srand(time(0));
	
	int n=rand()%500+300,m=rand()%500+300,q=rand()%100000+900000;
	
	if(rand()%2)
		m=min(m,100000/n);
	else
		n=min(n,100000/m);

	printf("%d %d %d\n",n,m,q);
	
	for(int i=1;i<=q;i++){
		int ord=rand()%2,col=get_rand();
		printf("%d ",ord+1);
		if(ord)
			printf("%d %d\n",get_rand()%m+1,col);
		else
			printf("%d %d\n",get_rand()%n+1,col);
	}
	
	return 0;
}
