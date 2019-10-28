#include<bits/stdc++.h>
using namespace std;
int n,mix[500],summix,maxmix,sum,ans[500][350],countt;
int main () {
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	cin>>n;
	for(int i=1;i<=(n*(n-1))/2;i++){
		cin>>mix[i];
		summix+=mix[i];
		maxmix=max(mix[i],mix[i-1]);
	}
	sum=summix/3;
	if(n==3){
		for(int i1=maxmix;i1>=1;i1--){
			for(int i2=i1-1;i2>=1;i2--){
				for(int i3=i2-1;i3>=1;i3--){
					if(i1+i2+i3==sum){
						countt++;
						ans[countt][1]=i1;
						ans[countt][2]=i2;
						ans[countt][3]=i3;
					}
				}
			}
		}
	}
	if(n==4){
		for(int i1=maxmix;i1>=1;i1--){
			for(int i2=i1-1;i2>=1;i2--){
				for(int i3=i2-1;i3>=1;i3--){
					for(int i4=i3-1;i4>=1;i4--){
						if(i1+i2+i3+i4==sum){
							countt++;
							ans[countt][1]=i1;
							ans[countt][2]=i2;
							ans[countt][3]=i3;
							ans[countt][4]=i4;
						}
					}
				}
			}
		}
	}
	cout<<countt<<endl;
	for(int i=1;i<=countt;i++){
		for(int j=n;j>=1;j--){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

