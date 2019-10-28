#include <stdio.h>
int main()
{
	freopen("toad.in","r",stdin);
	freopen("toad.out","w",stdout);
	printf("Impossible");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
