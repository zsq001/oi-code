#include<stdio.h>
#include<string.h>
char a[2010];
int b[5000000][2],t=0;
int len,s;
void check(int x,int y){
	int i=x,j=y;
	while(x<y){
		if(a[x]!=a[y]){
			return;
		}
		x++;y--;
	}
	t++;
	b[t][0]=i;b[t][1]=j;
}
int main(){
	freopen("calc.in","r",stdin);
	frepoen("calc.out","w",stdout);
	scanf("%s",a);
	len=strlen(a);
	s+=len*(len-1)/2;
    int i,j,k;
	for(k=1;k<=len-1;k++){
		for(i=0;i+k<=len-1;i++){
			check(i,i+k);
		}
	}
	for(i=1;i<=t;i++){
		s+=len-1-b[i][1];
		s+=b[i][0];
		for(j=1;j<=t;j++){
			if(i==j||b[i][1]>=b[j][0])continue;
			s++;
		}
	}
	printf("%d",s);
}

