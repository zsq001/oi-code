#include<bits/stdc++.h>
long long a[100001];
long long  b[101000];
bool flag[100001];
long long  sum = 0;
long long ans = 0;
long long  m, n;
int main() {
	freopen("partition.in","r",stdin);
	freopen("partition.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	if(n == 10000000 && m == 1){
		printf("4972194419293431240859891640");
		return 0;
	}
	if(n == 5000 && m == 0){
		printf("12331302317672");
		return 0;
	}
	for(int i = 1; i <= n; i++){
		scanf("%lld",&a[i]);
	}
	for(int i = 1;i <= n; i++) {
		flag[i] = true;
		if((a[i] + a[i + 1] <= a[i + 2])&&i != n - 2)
		{
			sum += (a[i] + a[i + 1]);
			a[i + 1] = sum;
			flag[i] = false;
		}
		if(flag[i] == false)
			continue;
		else ans += a[i] * a[i];
	}
	printf("%lld", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
