#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>
#include <math.h>
#define ll long long
using namespace std;
ll n,k,cnt,to[1000010],first[1000010],next[1000010];
char a[1000010],str[1000010],v[1000010];
void add(int u,int v){
	++cnt;
	to[cnt]=v;
	next[cnt]=first[u];
	first[u]=cnt;
}
bool check(int l,int r){
	ll ch=0;
	for(int i=l;i<=r;i++){
		if(a[i]=='(') ch++;
		if(a[i]==')') ch--;
		if(ch<0) return false;
	}		
	if(ch==0) return true;
	return false;
}
ll res;
ll lena;
void dfs(int x){
	for(int i=first[x];i;i=next[i]){
		ll t=to[i];
		lena++;
		a[lena]=str[t];
		ll k=0;
		for(int j=1;j<=lena;j++)
			for(int b=j;b<=lena;b++)
				if(check(j,b)) k++;
		if(!res) res=(t*k);
		else res=res^(t*k);
		if(!v[t]) {
			v[t]=1;
			dfs(t);
			v[t]=0;
		}
		lena--;
	}
}
int main(){
	freopen("brackets.in","r",stdin);
	freopen("brackets.out","w",stdout);
	scanf("%lld",&n);
	char c;
	while(c=getchar()){
		if(c=='('||c==')')
			str[++cnt]=c;
		if(cnt>=n) break;
	}
	cnt=0;
	for(int i=1;i<n;i++){
		ll fa;
		scanf("%lld",&fa);
		add(fa,i+1);
	}
	lena++;
	a[lena]=str[1];
	dfs(1);
	printf("%lld",res);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
