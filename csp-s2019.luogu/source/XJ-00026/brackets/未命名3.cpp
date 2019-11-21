#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
int a[2000],c[2000];
int main(){
	int i,n,s=0;
	freopen("brackets.in","r",stdin);
	freopen("brackets.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)
	  scanf("%c",&a[i]);
	for(i=1;i<=n-1;i++){
	  scanf("%d",c[i]);
	  s=s+a[i]^c[i];
    }
    cout<<s;
}
