#include<cstdio>
#include<algorithm>
#include<cstring>
#define foru(i,a,b) for(int i=a;i<=b;i++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return f*x;
}

int n,m;
int gray[5000010];

void solve(int k){
	foru(i,1,k)
	//foru(j,1,2*k)
	{
		
		
			foru(j,1,2*k)
			if(j<=(k/2))
			gray[j]=j%2;
			//if(j>(k/2))
			//gray[j]=j%2+1;
		
	}
}

int pow1(int a,int b)
{
	int ret=1;
	foru(i,1,b)
    ret*=a;
	//if(b%2==0)return (pow1(a,b/2)*pow1(a,b/2));
	//if(b%2==1)return (pow1(a,b/2)*pow1(a,b/2)*a);
	return ret;
}

int pow2(int a,int b)
{
	
	if(b%2==0)return (pow1(a,b/2)*pow1(a,b/2));
	if(b%2==1)return (pow1(a,b/2)*pow1(a,b/2)*a);
}

void solve2(int i,int k)
{
	//if(k<=2*i)puts("0");
	//else puts("1");
	foru(a,1,i)
	{
		int num=pow1(2,i-a);
		//while(num-k<num)k+=num;
		while(k>num*4){
			k-=num*4;
		}
		if(k<=num)printf("0");
		else if(k>num&&k<=num*2)printf("1");
		else if(k>num*2&&k<=num*3)printf("1");
		else if(k>num*3&&k<=num*4)printf("0");
		k=m+1;
		
	}
	
}

int main(){
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	n=read(),m=read();
	//solve(n);
	solve2(n,m+1);
	//n=pow1(2,5);
	//printf("%d",n);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
0    1    1    0    0    1    1    0    0    1    1    0    0    1    1    0   i=1
00   01   11   10   10   11   01   00   00   01   11   10   10   11   01   00  i=2
000  001  011  010  110  111  101  100  100  101  111  110  010  011  001  000 i=3
0000 0001 0011 0010 0110 0111 0101 0100 1100 1101 1111 1110 1010 1011 1001 1000i=4
842                  5                        10                       15


if(k<=2*i)
puts("0");
else puts("1")
if(k<=2)


*/


