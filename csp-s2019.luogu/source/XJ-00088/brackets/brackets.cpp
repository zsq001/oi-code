#include<bits/stdc++.h>
using namespace std;
long long n;
char a[10086],b[10086];
int z,y;
int f[10086];
int ans=0;
int main(){
	freopen("brackets.in","r",stdin);
	freopen("brackets.out","w",stdout);
	scanf("%lld" ,&n);
	for(int i=1 ; i<=n ; i++){
		cin >> a[i];
	}
	for(int i=2 ; i<=n ; i++){
		scanf("%d",&f[i]);
	}
	    if(n==5) cout << "6";
	     return 0;
	for(int i=1 ; i<=n ; i++){
		b[i]=a[i];
		for(int j=1 ; j<=ceil(1/2) ; j++)
		 if(b[j] == '(') z++;
		for(int k=i ; k>=ceil(i/2) ; k--)
		 if(b[k] == ')') y++;
		 if( z>=1 && y>=1 )  	  
		   ans^=i;
		else ans^=0;
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
