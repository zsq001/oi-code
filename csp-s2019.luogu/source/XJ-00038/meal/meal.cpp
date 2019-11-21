#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
int n,m,ans=0,ans1[5005],f[5005],a[205][1005],flag=1;
int main(){
	freopen("meal.in","r",stdin);
	freopen("meal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	if(n==2){
		for(int i=1;i<=m;i++)
			for(int j=1;j<=m;j++){
				if(j==i)continue;
				ans+=a[1][i]*a[2][j];
			}
	}
	else {
		for(int T=2;T<=n;T++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++){
					f[j]=1;
					ans1[j]=a[i][j];
					for(int k=i+1;k<=n;k++){
						for(int l=1;l<=m;l++){
							f[l]++;
							if(f[l]>T/2){
								f[l]--;
								continue;
							}
							ans1[l]=(a[k][l]*ans1[l]);
							flag++;
							f[l]--;
							if(flag==T){
								ans+=ans1[l];
								flag--;
							}	
						}
					}
					f[j]=0;
					flag=1;
				}
			}	
		}	
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

