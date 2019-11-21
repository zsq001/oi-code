#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

int n,m,ans=0,dish=0;
int a[110][2010];
const int qm=998244353;

int main(){
	ios::sync_with_stdio(false);
	freopen("meal.in","r",stdin);
	freopen("meal.out","w",stdout);
	cin>>n>>m;
	for(register int i=1;i<=n;i++){
	  for(register int j=1;j<=m;j++){
		  cin>>a[i][j];
		  if(a[i][j]){
			  dish++;
			  dish%=qm;
			}
		}
	}
	cout<<dish%qm;
	return 0;
}
