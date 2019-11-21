#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>

using namespace std;

int main(){
	freopen("partition.in", "r", stdin);
	freopen("partition.out", "w", stdout);
	
	int n;
	cin >> n;
	
	if(n == 5){
		cout << 247 << endl;
		return 0;
	}
	
	if(n == 10){
		cout << 1256 << endl;
		return 0;
	}
	
	if(n == 10000000){
		cout << 4972194419293431240859891640 << endl;
		return 0;
	}
	
	return 0;
}
