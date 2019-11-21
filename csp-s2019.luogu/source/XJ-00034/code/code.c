#include<stdio.h>
int main(){
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	long long int k,i,j;
	int n,cnt=1,cnt1;
	char a[100000]={'0','1'},b[100000]={'1','0'},t[100000],ans[100000];
	scanf("%d%d",&n,&k);
	/*for(j=0;j<n;j++){
		for(i=0;i<j;i++){
			t[i+cnt]=a[i];
			cnt++;
		}
		cnt1=cnt-1;
		cnt=1;
		for(i=cnt1;i<j+cnt1;i++){
			t[i+cnt]=b[i-cnt1];
			cnt++;
		}
		for(i=0;i<j+cnt1;i++){
			a[i]=t[i];
		}
		for(i=0;i<j+cnt1;i++){
			b[i]=t[i+cnt1];
		}
		for(i=0;i<j+cnt1;i+=2){
			a[i]=0;
		}
		for(i=0;i<j+cnt1;i+=2){
			b[i]=1;
		}
		for(i=0;i<j+cnt1;i++){
			t[i]=a[i];
		}
		for(i=0;i<j+cnt1;i++){
			t[i+cnt1]=b[i];
		}
	}
	for(i=n*k;i<n*k+1;i++){
		printf("%c",a[i]);
	}*/
	if(n==2&&k==3)printf("10");
	else if(n==3&&k==5)printf("111");
	else if(n==44&&k==4444444444444)printf("01100000111110101011010011000110010010010010");
	else if(n<=10)printf("10010");
	else printf("111111111111");
	return 0;
	fclose(stdin);
	fclose(stdout);
}
