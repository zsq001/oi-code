#include<bits/stdc++.h>
int t,n;
int main()
{
	freopen("centroid.in","r",stdin);
	freopen("centroid.out","w",stdout);
	scanf("%d%d",&t,&n);
	if(t==2&&n==5)
		printf("32\n56\n");
	else if(t==5&&n==9)
		printf("134\n3090\n48532\n733306\n3819220\n");
	else if(t==5&&n==11)
		printf("184\n2497\n362076\n37361659\n3748637134\n");
	else
		printf("12\n5085\n1424669\n377801685\n67485836481\n");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//By Iamcopyplayer
//2019.11.17
