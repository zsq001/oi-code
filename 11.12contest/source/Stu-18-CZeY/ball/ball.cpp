#include<cstdio>
#include<cstring>
int a[110],b[110];
int xa,xb,num;

/*
void dfs(int x){
	int i;
	for(i=x;i>=1;i--){
		a[i]=b[i];
	}
}
*/

int main()
{
	int n;
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	scanf("%d",&n);
	char r;
	r=getchar();
	for(int i=1;i<=n;i++){
		r=getchar();
		if(r=='R'){
			a[i]=1;
		}
		else if(r=='B'){
			a[i]=0;
		}
	}
	int ans=0;
	while(ans!=n){
		xb=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1){
//				b[++xb]=0;
				a[i]=0;
				ans++;
			}
			else if(a[i]==0){
//				b[++xb]=1;
				a[i]=1;
//				dfs(xb);
				num++;
				ans=0;
				break;
			}
		}
		if(num > 10485750){
			printf("-1\n");
			return 0;
		}
	} 
	printf("%d",num);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
