#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdio.h>
#include<cstring>
using namespace std;
int n,i,x=0,y=0;
long long int ans=0;
char a;
int main(){
	freopen("brackets.in","r",stdin);
	freopen("brackets.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%c",&a);
		if(a=='('){
			x++;
		}else{
			y++;
		}if(x<y){
			ans+=(ans)xor(i*x);
		}else{
			ans+=(ans)xor(i*y);
		}
	}cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
