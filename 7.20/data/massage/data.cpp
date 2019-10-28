#include<bits/stdc++.h>
using namespace std;
int prime[12000],tot;
bool isprime(int n){
	for(int i = 2; i*i <= n;i++)
		if(n%i==0)return 0;
	return 1;
}
void getprime(){
	for(int i = 1000; i <= 9999; i++){
		if(isprime(i))prime[++tot] = i;
	}
}
int main(){
	srand(time(0));
	getprime();
	int T = 100,Q = 1;
	printf("%d %d\n",T,Q);
	while(T--){
		int A = prime[rand()%tot+1];
		int B = prime[rand()%tot+1];
		printf("%d %d\n",A,B);
	}
}
