#include<bits/stdc++.h>
int a[105][2005];
int n,m,ans_meal=0;

int meal_K(int x,int y){
	int jishu=0;
	for(int i=x+1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(j==y) continue;
			jishu+=a[x][y]*a[i][j];
		}	
	}
	return jishu;
}

using namespace std;
int main(){
	freopen("meal.in","r",stdin);
	freopen("meal.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
		cin>>a[i][j];
		}	
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
		ans_meal+=(meal_K(i,j)%998244353);
		}	
	}
	printf("%d",ans_meal);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
