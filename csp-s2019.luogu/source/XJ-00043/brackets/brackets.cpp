#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int n;
char qaq[100010];
int fa[100010];
int ans[100010];
int zuo=0,you=0;
int dfs(int st,int ed){
	if(fa[ed]==1){
		if(qaq[ed]=='(') zuo++;
		else you++;
			if(zuo!=0&&you!=0)
			{
				if(zuo==you) return zuo;
				else return abs(zuo-you);
				}
			else return 0;
	
	}
		
	else{
		if(qaq[ed]=='(') zuo++;
		else you++;
		ed=fa[ed];
		return dfs(1,ed);
	}
}
int main(){
	freopen("brackets.in","r",stdin);
	freopen("brackets.out","w",stdout);
	scanf("%d\n",&n);
	for(int i=1;i<=n;++i)
		scanf("%c",&qaq[i]);
	if(qaq[1]=='(')	zuo=1,you=0;
	else you=1,zuo=0;
	for(int j=2;j<=n;++j){
		scanf("%d",&fa[j]);
	}
	for(int k=2;k<=n;++k){
		ans[k]=k*dfs(1,k);
//	printf("%d\n",ans[k]);
		if(qaq[1]=='(') zuo=1,you=0;
		else you=1,zuo=0;
	}
	int ans1=ans[2]^0;
	for(int q=3;q<=n;++q)
	ans1=ans1^ans[q];
	printf("%d",ans1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

