#include<cstdio>
int map[2010];
bool mapp[2010];
long long AA,BB;
int ans;
int main()
{
	int n,i,j;
	freopen("square.in","r",stdin);
	freopen("square.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&map[i]);
	}
	int k=1;
	for(i=1;i<=n;i++)
	{
		mapp[i]=true;
		AA=0;
		BB=0;
		k=1;
		for(j=1;j<=n;j++)
		{
			if(mapp[j]==true){
				j++;
			}
			if(k%2==0){
				BB+=map[j];
			}
			if(k%2!=0){
				AA+=map[j];
			}
			k++;
		}
		if(AA==BB){
			ans++;
		}
		mapp[i]=false;
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
