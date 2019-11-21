#include<stdio.h>
long long  a[100001];
long long  b[100001];
int main() {
	freopen("centroid.in","r",stdin);
	freopen("centroid.out","w",stdout);
	int q;
	scanf("%d",&q);
	while(q--){
		int n;
		int sum = 0;
		scanf("%d",&n);
		for(int i = 1; i <= n - 1 ; i++)
	{
		scanf("%lld",&a[i]);
		scanf("%lld",&b[i]);
	}
	for(int i = 1; i <= n - 1 ; i++ ){
		sum += a[i] + b[i];	
	}
	printf("%d\n", sum  + (2 * n));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
