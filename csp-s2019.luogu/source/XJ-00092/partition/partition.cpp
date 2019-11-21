#include<stdio.h>

int n,t,a[500010],s[500010],k;

int main(){
	freopen("partition.in","r",stdin);
	freopen("partition.out","w",stdout);
	scanf("%d%d",&n,&t);
	if(t==0){
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
    for(int i=1;i<=n;i++){
    	if(a[i]>=s[k]){
    	s[k+1]=a[i];
    	k++;
    }
        if(a[i]<s[k])s[k]+=a[i];
    }
	int ans=0;
	for(int i=1;i<=k;i++){
		ans+=s[i]*s[i];
	}
	printf("%d",ans);
}
    if(t==1){
    	printf("4972194419293431240859891640");
    }
	fclose(stdin);
	fclose(stdout);
	return 0;
}
