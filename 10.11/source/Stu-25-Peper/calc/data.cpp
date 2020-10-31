#include<stdio.h>
#include<algorithm>
#include<time.h>
using namespace std;
int main(){
	srand(time(0));
	freopen("calc.in","w",stdout);
	for(int i=1;i<=20;++i){
		int x=rand()%26+97;
		for(int j=1;j<=5;++j)
		printf("%c",x);
	}
}
 
