#include<bits/stdc++.h>
using namespace std;
#define maxn 10010
int a1[110][maxn],a2[110][maxn];
int main(){
//	freopen("massage.in","r",stdin);
//	freopen("massage.out","w",stdout);
	int n,op,sum=0,cnt;
	cin>>n>>op;
	for(int i=1;i;){
		for(int j=1;j<=4;j++){
			cin>>a1[i][j]>>a2[i][j];
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=5;++j){
			if(op==0){
				if(a1[i][j]>a2[i][j]) sum+=a1[i][j]-a2[i][j];
				else sum+=a2[i][j]-a1[i][j];
			
			}
		}
	}	
	for(int i=1;i<=n;++i){
		cout<<sum<<endl;
		
	}
//	for(int i=1;i<=n;++i){
//		for(int j=1;j<=5;++j){
//			cout<<a1[i][1]<<endl;
//		}
//	}
	return 0;
}
