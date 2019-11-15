#include<cstdio>
int n;
int min=214748364;
char ma[400010];
int main()
{
	int m,i,j;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&m);
	while(m--){
		scanf("%d",&n);
		getchar();
		for(i=1;i<=n;i++){
			scanf("%c",&ma[i]);
		}
		min=21474836;
		int x;
		for(i=1;i<=2;i++){
			for(j=i+1;j<=n;j++){
				if(ma[i]==ma[j]){
					x=j-i;
					if(x < min){
						min=x;
					}		
				}
			}
		}
		printf("%d\n",min);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
