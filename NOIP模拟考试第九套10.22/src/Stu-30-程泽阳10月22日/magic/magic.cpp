#include<cstdio>
long long ans;
long long Mode(long long a, long long b, long long mode)
{
    long long sum = 1;
    while (b) {
        if (b & 1) {
            sum = (sum * a) % mode;
            b--;
        }
        b /= 2;
        a = a * a % mode;
    }
    return sum;
}
int main()
{
	int n;
	long long mod=1000000007;
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	scanf("%d",&n);
	n++;
	ans=Mode(3,n,mod);
	ans=ans-1;
	printf("%lld",ans/2);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
