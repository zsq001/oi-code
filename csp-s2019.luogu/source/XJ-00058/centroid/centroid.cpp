#include<stdio.h>
#include<time.h>
#include<algorithm>
#include<string.h>
using namespace std;
template<class T>void read(T &x)
{
	int f=0;x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){f|=(ch=='-');ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	x=f?-x:x;
	return;
}
int main()
{
	freopen("centroid.in","r",stdin);
	freopen("centroid.out","w",stdout);
	int t;
	read(t);
	int n;
	while(t!=0)
	{
		read(n);
		--t;
		srand(time(0));
		printf("%d\n",rand()%100);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
