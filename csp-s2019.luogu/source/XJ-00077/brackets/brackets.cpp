#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;
string a;
int f[100000];
int g(int pp){
	int j=0,tot=0;
	for(int i=1;i<=pp;i++){
		if(a[i-1]=='(') j=j+1;
		if(a[i-1]==')') {
			if(j>0){j=j-1;tot++;
			}
		}
	}
	return tot;
}
int main(){
	freopen("brackets.in","r",stdin);freopen("brackets.out","w",stdout);
	int n,ff=0,ans=0;
	int i;
	scanf("%d",&n);
	cin>>a;
	for(i=2;i<=n;i++){
		scanf("%d",&f[i]);
	}
	f[1]=1;
	ans=1*g(1);
	for(i=2;i<=n;i++){
		int ll=i*g(i);
		ans=ans^ll;
	}
	cout<<ans;
	fclose(stdin);fclose(stdout);
	return 0;
}
