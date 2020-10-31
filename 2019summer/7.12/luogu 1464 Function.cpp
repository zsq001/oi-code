#include<cstdio>
#include<cstring>
using namespace std;
int s[21][21][21];
int so(int A,int B,int C){
	if(A<=0||B<=0||C<=0) return 1;
	else if(A>20||B>20||C>20) return so(20,20,20);
    else if(A<B&&B<C){
  		if(!s[A][B][C]) s[A][B][C] = so(A,B,C-1)+so(A,B-1,C-1)-so(A,B-1,C);
 		return s[A][B][C];
 	}
    else{
  		if(!s[A][B][C]) s[A][B][C] = so(A-1,B,C)+so(A-1,B-1,C)+so(A-1,B,C-1)-so(A-1,B-1,C-1);
  		return s[A][B][C];
 	}
}
int main()
{
    int a,b,c;
    while(1){
    	scanf("%d%d%d",&a,&b,&c);
    	if(a==-1&&b==-1&&c==-1) break;
    	printf("w(%d, %d, %d) = %d\n",a,b,c,so(a,b,c));
    }
    return 0;
}
