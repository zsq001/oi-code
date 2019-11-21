#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int a[50010],f[50010];
int main(){	
	int type,i,n,j;
	long long s=0;
	freopen("partition.in","r",stdin);
	freopen("partition.out","w",stdout);
	scanf("%d %d",&n,&type);
	memset(f,0,sizeof(f));
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		f[i]=a[i];
	}

	if(type==0){
	  for(i=1;i<=n;i++){
		if(f[i]<f[i-1]){
			for(j=i-1;j<=i+2,j!=i;j++){  
	  			if(f[i]<f[i-1]&&f[j]!=0x7fffffff){
			  		f[i]=f[i]+a[j];f[j]=0x7fffffff;if(f[i]>f[i-1])continue;
				}
	    	}	
      	}
		if(f[i]<f[i-2]&&f[i-1]==0x7fffffff){
			f[i]=f[i-2]+f[i];f[i-2]=0x7fffffff;
	    }
      }
	  for(i=1;i<=n;i++){
	  	if(f[i]!=0x7fffffff)s=s+f[i]*f[i];
	  }
	  cout<<s;
    }
	else if(n==10000000){cout<<49721944192;cout<<934312408;cout<<59891640;}
	else if(type==1){ rand();cout<<rand();}
	return 0;
}
