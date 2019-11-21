#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<vector>
#include<stdio.h>
using namespace std;
int n;
char brackets[500010];
vector<int>v[500010];
int weight[500010];
int dw[500010];
long long ans=0;
char s[500010];
int nums[500010];
int top=0;
int lx[500010];
//int sumleft=0;
void solve(int from,int nowa){
	/*
	if(brackets[nowa-1]=='('){
		dw[nowa]=dw[from];
		if(brackets[from-1]=='(')
		sumleft++;
		else sumleft=1;
	}
	else if(brackets[nowa-1]==')'){
		if(sumleft>0){
			sumleft--;
			if(sumleft==0){
				lx++;
				dw[nowa]=dw[from]+(lx-1);
			}
			else{
				dw[nowa]=dw[from];
			}
		}
		else{
			lx=0;
			dw[nowa]=dw[from];
		}
	}*/
	
	if(s[top]=='('&&brackets[nowa-1]==')'){
		top--;
		weight[nowa]=weight[from]+1;
		dw[nowa]=dw[from];
		if(brackets[from-1]=='('){
			lx[nowa]=lx[nums[top+1]]+1;
			dw[nowa]+=(lx[nowa]-1);
		}
		else{
			lx[nowa]=lx[nums[top+1]];
		}
		ans=ans^(nowa*(weight[nowa]+dw[nowa]));
	}
	else{
		dw[nowa]=dw[from];
		top++;
		s[top]=brackets[nowa-1];
		nums[top]=nowa;
		if(brackets[nowa-1]=='('){
			if(s[top-1]=='(')lx[nowa]=0;
			else lx[nowa]=lx[nums[top-1]];
		}
		else{
			lx[nowa]=0;
		}
		weight[nowa]=weight[from];
		ans=ans^(nowa*(weight[nowa]+dw[nowa]));
	}
	for(int i=0;i<v[nowa].size();i++){
		solve(nowa,v[nowa][i]);
	}
	if(weight[nowa]>weight[from]){
		top++;
		s[top]=brackets[from-1];
	}
}

int main(){
	freopen("brackets.in","r",stdin);
	freopen("brackets.out","w",stdout);
	scanf("%d",&n);
	scanf("%s",&brackets);
	int fa;
	for(int i=2;i<=n;i++){
		scanf("%d",&fa);
		v[fa].push_back(i);
	}
	solve(1,1);
	printf("%lld",ans);
	return 0;
}
