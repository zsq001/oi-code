#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
int a[101];
long long s[101];
int m[9]={011,010,110,111,101};
int q[25]={0011,0010,0110,0111,0101,0100,1100,1101,1111,1110,1010,1011,1001};
int main(){
	int i,n,k,r,h=0;
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	scanf("%d %d",&n,&k);
	s[0]=1;
	memset(a,0,sizeof(a));
	for(i=1;i<=n;i++)
	  s[i]=s[i-1]*2;
	if(k==0){
		for(i=1;i<=n;i++)
		  printf("%d",0);
	}
	else if(k==1){
		for(i=1;i<=n-1;i++){
			printf("%d",0);
		}
		printf("%d",1);
	}
	else if(k==2){
		for(i=1;i<=n-2;i++){
			printf("%d",0);
		}
		printf("%d",1);
	}
	else if(k==s[n]){
		printf("1");
		for(i=1;i<=n-1;i++)
		  printf("0");
	}
	else if(n<=10){
		if(n==3)printf("%d",m[k+2]);
		if(n==4)printf("%d",q[k+2]);
	    if(n==5){if(k<16)printf("0%d",q[k]);else printf("1%d",q[k]);}
	    if(n==6){if(k<16)printf("00%d",q[k]);else if(k<=32&&k>=16)printf("01%d",q[k]);
	    }
	}
	else {
		i=0;
		long long m=s[n-1];
		double l=double(m-0.5);
		while(i<=n){
			h++;
			if(n-i-1<0)l=1.5;
			if(h==1)
			{
			   if(k<m/2)a[n-i]=0;
			    else a[n-i]=0;
			}
			else if(k>l){
			  if(h%2==1)a[n-i]=1;
			  else a[n-i]=0;
			  l=double(s[n-i-1]+s[n-i-1]/2-0.5);
			
			}
			else {
				if(h%2==1)a[n-i]=0;
				else a[n-i]=1;
				l=double(s[n-i-1]/2-0.5);
			}
			i++;
			
		}
		for(i=n;i>=1;i--)
		  printf("%d",a[i]);
	}
	return 0;
}
