#include<iostream>
#include<cstdio>
using namespace std;
int bod[110][2010];
int sum[110];
int m,n,i;
int ans=0;
int main(){
	freopen("meal.in","r",stdin);
	freopen("meal.out","w",stdout);
	cin>>m>>n;
	for(i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>bod[i][j];
			sum[i]+=bod[i][j];
		}
	}
	if(m>=2)for(i=0;i<m;i++)for(int j=0;j<n;j++)for(int k=i+1;k<m;k++)ans+=bod[i][j]*(sum[k]-bod[k][j]);
	if(m==3){
		for(i=0;i<m;i++)
		for(int j=0;j<n;j++)
		for(int k=i+1;k<m;k++)
		for(int o=0;o<m;o++){
			if(o==j)continue;
			for(int q=k+1;q<n;q++)ans+=bod[i][j]*bod[k][o]*(sum[q]-bod[q][j]-bod[q][o]);	
		}
		
	}
	cout<<ans;
}
