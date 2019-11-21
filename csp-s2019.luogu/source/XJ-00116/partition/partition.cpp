#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#define inf 0x7ffffff
#define ll unsigned long long
using namespace std;
 
ll a[40000010];
ll n;
ll ans;
bool type;


int main(){
	freopen("partition.in","r",stdin);
	freopen("partition.out","w",stdout);
	cin >> n >> type;
	for(ll i = 1;i <= n;i++)
		cin >> a[i];
	a[0] = inf;
	a[n + 1] = inf;
	for(ll i = 2;i <= n;i++){
		if(a[i] < a[i - 1]){
			if(a[i - 1] < a[i + 1]){
				if(a[i - 1] + a[i] <= a[i + 1]){
					a[i] += a[i - 1];
					a[i - 1] = 0;
//					cout << a[i] << " " << 1 << " ";
				}
				else{
					a[i + 1] += a[i];
//					cout << a[i + 1] << " " << 2 << " ";
					a[i] = 0;
				}
			}
			else{
				a[i + 1] += a[i];
//				cout << a[i + 1] << " " << 3 << " ";
				a[i] = 0;
			}
			i++; 
		}
	}
	for(ll i = 1;i <= n;i++){
//		cout << a[i] << " "; 
		ans += a[i] * a[i];
	}
		
	cout << ans;
	return 0;
}
