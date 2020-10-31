#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#define maxn 100010
using namespace std;
typedef unsigned long long ll;
const ll base=76;
ll n,ans,Hash[maxn];
char s[maxn];
void insert(int x){
	int len=strlen(s+1);
	ll t=1;
	for(int i=1;i<=len;++i){
		Hash[x]+=t*(s[i]-'0');
		t*=base;
	}
}
bool query(int x){
	for(int i=1;i<x;++i) if(Hash[x]==Hash[i]) return true;
	return false;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;++i){
		scanf("%s",s+1);
		insert(i);
		if(!query(i)) ans++;
	}
	cout<<ans<<endl;
	return 0;
}
