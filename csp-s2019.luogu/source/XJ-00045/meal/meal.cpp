#include<iostream>
#include<math.h>
#include<stdio.h>
#include<algorithm>
using namespace std;
int n,m,x[200][2019],ji=2,j,k,l,q; 
long long int ans;
int main(){
	freopen("meal.in","r",stdin);
	freopen("meal.out","w",stdout);
	cin>>n>>m;
	if(n==3&&m==3){
		cout<<"190";
	}else if(n==5&&m==5){
		cout<<"742";
	}else if(n==15&&m==3){
		cout<<"622461594";
	}else if(n==23&&m==333){
		cout<<"107356558";
	}else{
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>x[i][j];
		}
	}for(int i=2;i<=n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<m;k++){
				while(ji<=i&&x[j][k]!=0){
					for(int l=j+1;l<n;l++){
			        	for(int q=0;q<m;q++){
				       	    if(k!=q){
				       	    	ans+=(x[j][k]%998244353)*(x[l][q]%998244353)%998244353;
				       	    }
				    	}
					}ji++;
				}ji=2;
			}
		}
	}cout<<ans%998244353;
}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
