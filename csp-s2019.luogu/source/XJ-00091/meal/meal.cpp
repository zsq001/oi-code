#include<cstdio>
#include<iostream>
long long P=998244353ll;
int n,m,a[111][2010],mk[111],used[2010],cai,lcai,ca1,ca2;
long long ANS,ans;
void sol(){
	ans=1;
	for(int i=1;i<=n;i++){
		if(mk[i]==1)ans=(ans*a[i][1])%P;
		else if(mk[i]==2)ans=(ans*a[i][2])%P;
	}
	ANS=(ANS+ans)%P;
}
void dfs2(int x){
	if(x+ca1+ca2>n+1)return;
	if(ca1==0&&ca2==0)return sol();
	if(ca1){
		mk[x]=1;
		ca1--;
		dfs2(x+1);
		ca1++;
		mk[x]=0;
	}
	if(ca2){
		ca2--;
		mk[x]=2;
		dfs2(x+1);
		ca2++;
		mk[x]=0;
	}
	dfs2(x+1);	
}
void calc2(){
	for(cai=1;cai<=(n/2);cai++){
		ca1=ca2=cai;
		for(int i=1;i<=n;i++)mk[i]=0;
		dfs2(1);
	}		
}

void calc(int ff){
	if(ff>n)return;
	if(mk[ff]){
		for(int i=1;i<=m;i++)if(used[i]<(cai/2)){
			int oans=ans;
			ans=(ans*a[ff][i])%P;
			used[i]++;
			if(ff!=lcai)calc(ff+1);
			else{
				ANS=(ANS+ans)%P;
			}
			used[i]--;
			ans=oans;
		}
	}
	else{
		calc(ff+1);
	}
}
void dfs(int ff){
	if(ff>n){
		//printf(".");
		ans=1;
		if(cai<=1)return;
		return calc(1);
	}
	int ol=lcai;
	mk[ff]=1;
	cai++;
	lcai=ff;
	dfs(ff+1);
	mk[ff]=0;
	cai--;
	lcai=ol;
	dfs(ff+1);
}
int  main(){
	freopen("meal.in","r",stdin);
	freopen("meal.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	if(m==2){
		calc2();
	}
	else{
		dfs(1);
	}
	printf("%lld",ANS);
	return 0;
}
