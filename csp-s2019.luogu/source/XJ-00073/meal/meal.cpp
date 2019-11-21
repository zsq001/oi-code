#include<bits/stdc++.h>
#define p 998244353
using namespace std;
long long int  ans3,ans2,n,m,a[105][2005];
//bool cheak(){
//	for(int po=1;po<=cnt;po++){
//		if(x==codx[po]&&y==cody[po]&&i==codi[po]&&j==codj[po]&&exx==codexx[po]&&exy==codexy[po]){
//			return false;
//		}
//		return true;
//	}
//}
int main () {
	freopen("meal.in","r",stdin);
	freopen("meal.out","w",stdout);
	cin>>n>>m;
	for(int ip=1;ip<=n;ip++){
		for(int jp=1;jp<=m;jp++){
			cin>>a[ip][jp];
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			cout<<a[i][j]<<" ";
//		}
//		cout<<endl;
//	}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){				if(a[i][j]==0){
							continue;
						}
				//make sure this point is programming
				for(int y=1;y<=n;y++){
					for(int x=1;x<=m;x++){
						if(a[y][x]==0){
							continue;
						}
						if(j!=x&&y!=i){
							ans2=(ans2+a[i][j]*a[y][x]);
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(a[i][j]==0){
							continue;
						}
				//make sure this point is programming
				for(int y=1;y<=n;y++){
					for(int x=1;x<=m;x++){
						if(a[y][x]==0){
							continue;
						}
						if(j!=x&&y!=i){
							for(int exy=1;exy<=n;exy++){
								for(int exx=1;exx<=m;exx++){
									if(a[exy][exx]==0){
										continue;
									}
									if(y!=exy&&i!=exy&&x!=exx&&j!=exx){
										ans3=(ans3+a[i][j]*a[y][x]*a[exy][exx]);
//										codx[++cnt]=x;
//										cody[cnt]=y;
//										codi[cnt]=i;
//										codj[cnt]=j;
//										codexx[cnt]=exx;
//										codexy[cnt]=exy;
										//cout<<exy<<" "<<exx<<endl;
									}
						}
					}
				}
			}
		}
	}
}
		cout<<(ans2/2+ans3/6)%p<<endl;
//		cout<<ans2<<" "<<ans2/2<<endl;
//		cout<<ans3<<" "<<ans3/6;
	return 0;
}
