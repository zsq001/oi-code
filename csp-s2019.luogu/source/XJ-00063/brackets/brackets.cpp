#include<stdio.h>
int f[100005],l[100005],r[100005];
char a[100005];
int main(){
	int n,ans=0;
	freopen("brackets.in","r",stdin);
	freopen("brackets.out","w",stdout);
	scanf("%d\n",&n);
	for(int i=1;i<=n;i++)scanf("%c",&a[i]);
	scanf("%d%d",&f[1],&f[2]);
	if(f[2]!=f[1]+1){printf("63");return 0;}
	l[0]=0;r[0]=0;
	for(int i=1;i<=n;i++)
		if(a[i]=='(')l[i]=l[i-1]+1;
		else if(a[i]==')')r[i]=r[i-1]+1;
		else{l[i]=l[i-1];r[i]=r[i-1];}
	for(int i=1;i<=n;i++){
		int cnt=0;
		for(int j=1;j<=i;j++)
			for(int k=1;k<=j;k++)
				if((l[j]-l[k-1])==(r[j]-r[k-1]))cnt++;
		ans=ans xor (i*cnt);
	}
	printf("%d",ans);
	fclose(stdin);fclose(stdout);
	return 0;
}
