#include<bits/stdc++.h>
using namespace std;
stack<int>a;
char b;
long long yyy[1000001],v[1000001];
long long ans = 0;
int main(){

	freopen("brackets.in","r",stdin);
	freopen("brackets.out","w",stdout);
	int n;
	int sum = 0;
	
	cin >> n;
	while(n-- ) {
		cin >> b;
		sum ++;
		if(b == '(') {
			a.push(b);
		}
		if(b == ')' &&!a.empty()) {
			while(!a.empty()){
				a.pop();
			}
			yyy[sum] += 1;
		}
		ans = ans ^ (sum * yyy[sum]);
	}
	
	cout << ans << endl;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
