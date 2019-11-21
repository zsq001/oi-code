#include <cstdio>
#include <cmath>
#include <stack>
#include <iostream>
using namespace std;
unsigned long long N, K;
stack<unsigned long long> P;
long long F(unsigned long long x){
	if (x == 0)
		return 0;
	if (x == 1)
		return 1;
	unsigned long long temp = x, cil = 1;
	while (temp > 0){
		temp /= 2;
		cil *= 2;
	}
	return F(cil - 1 - x) + cil/2 ;
}
void Print(unsigned long long K){
	int cnt = 0;
	while (K > 0){
		P.push(K&1);
		K >>= 1;
		cnt++;
	}
	for (int i = N-cnt; i > 0; i--)
		P.push(0);
	while (!P.empty()){
		cout << P.top();
		P.pop();
	}
	return;
}
int main(){
	freopen("code.in", "r", stdin);
	freopen("code.out", "w", stdout);
	cin >> N >> K;
	Print(F(K));
	return 0;
}
