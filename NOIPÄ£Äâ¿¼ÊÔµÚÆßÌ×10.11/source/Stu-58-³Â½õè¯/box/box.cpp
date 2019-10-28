#include<bits/stdc++.h>
using namespace std;

int ans=2147483647;
int v,f[55][55][3026];

int main(){
	freopen("box.in","r",stdin);
	freopen("box.out","w",stdout);
	cin>>v;
	for(int i=1;i*i<=v;++i){
		for(int j=i;j*j<=v;++j){
			if(v%(i*j)!=0) continue;
			int k=v/(i*j);
			if(v%i!=0||v%j!=0) continue;
			f[i][j][k]=2*(i*j+i*k+j*k);
			ans=min(ans,f[i][j][k]);
		//	printf("%d %d %d %d\n",i,j,k,f[i][j][k]);
		}
	}
	cout<<ans<<endl;
	return 0;
}
