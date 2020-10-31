#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;
int a[10010],b[10010];
int main(){
	freopen("massage.in","r",stdin);
    freopen("massage.out","w",stdout);
	int t,q;
	scanf("%d%d",&t,&q);
	for(int i=1;i<=t;i++){
		scanf("%d%d",&a[i],&b[i]);
		if(a[i]=b[i]) printf("0");
	}
}
