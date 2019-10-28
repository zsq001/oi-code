#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
typedef double db;
const int N=10;

int n;
int x[N],y[N];

namespace pt1{
	db ans;
	void cal(){
		
	}
	void solve(){
		
	}
}

int main(){
	freopen("protect","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d",&x[i],&y[i]);
	if(n==3)pt1::solve();
	else pt2::solve();
	return 0;
}
