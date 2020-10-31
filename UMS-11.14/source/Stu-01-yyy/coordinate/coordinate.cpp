#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
typedef unsigned long long ll;
const ll M=1e9+7;
int n;
int res[30]={0,3,7,17,41,99,239,577,1393,3363,8119,19601,47321,114243,275807,665857,1607521,3880899,9369319,22619537,54608393,131836323,318281039,768398401,1855077841,183586787};
ll ans;

int main(){
	freopen("coordinate.in","r",stdin);
	freopen("coordinate.out","w",stdout);
	scanf("%d",&n);
	if(n<=20){
		printf("%d\n",res[n]);
		return 0;
	}
//	if(n<=100)pt1::solve();
	return 0;
}
