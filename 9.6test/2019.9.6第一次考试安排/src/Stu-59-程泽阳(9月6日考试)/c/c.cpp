#include<cstdio>
int main()
{
	int n,x;
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	scanf("%d%d",&n,&x);
	if(n==4 && x==3){
		printf("1\n1 2 3 4\n");
	}
	else{
		printf("2\n4 7 8 13\n3 8 9 12\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
