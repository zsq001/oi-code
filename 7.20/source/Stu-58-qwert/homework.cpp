#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
int cnt=0,cnt1,cnt2,ans[100001];
void dfs(int n1,int n2,int k1,int k2){
	if(n1==0&&n2==0){
		cnt++;return ;
	}
	if(n1==0){
		if(k2>n2)cnt++;
		return ;
	}
	if(n2==0){
		if(k1>n1)cnt++;
		return ;
	}
	int sum=n1+n2;
	if(cnt2==k2){
		n1--;
		cnt1++;
		int a2=cnt2;
		cnt2=0;
		dfs(n1,n2,k1,k2);
		cnt2=a2;
		cnt1--;
		n1++;
	}
	else if(cnt1==k1){
		n2--;
		cnt2++;
		int a1=cnt1;
		cnt1=0;
		dfs(n1,n2,k1,k2);
		cnt1=a1;
		cnt2--;
		n2++;
	}
	 else{
	 	n1--;
		cnt1++;
		int a2=cnt2;
		cnt2=0;
		dfs(n1,n2,k1,k2);
		cnt2=a2;
		cnt1--;
		n1++;
		
		n2--;
		cnt2++;
		int a1=cnt1;
		cnt1=0;
		dfs(n1,n2,k1,k2);
		cnt1=a1;
		cnt2--;
		n2++;
	 }
}
int main(){
	int n1,n2,k1,k2;
	freopen("homework.in","r",stdin);
	freopen("homework.out","w",stdout);
	scanf("%d%d%d%d",&n1,&n2,&k1,&k2);
	int sum=n1+n2;
	dfs(n1,n2,k1,k2);
	printf("%d",cnt);
}
