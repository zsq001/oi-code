#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long LL;

LL V, v, S(1000000000000LL);

int main() {
	freopen("box.in","r",stdin);
	freopen("box.out","w",stdout);
	
	cin >> V;
	for(LL a=1; a*a*a<=V; a++) {
		if(V%a != 0) continue;
		v = V / a;
		for(LL b=a; b*b<=v; b++) {
			if(v%b != 0) continue;
			LL c = v / b;
			S = min ( S , 2 * (a*b + b*c + c*a) );
		}
	}
	
	cout << S << endl;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
