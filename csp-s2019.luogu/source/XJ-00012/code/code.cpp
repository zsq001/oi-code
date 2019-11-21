#include <stdio.h>
#include <string.h>
int n,len,code1=3,code2=1;
long long k;
char str[70][5000005];
int num[5000005];
int pow(int x)
{
 int ans=1,num=2;
 if(x==1)return 2;
 while(x!=0)
 {
   ans*=num;
   if(x%2!=0)num*=num;
   x/=2;	
 }
 return ans;
}
void code(int x)
{
 int len=pow(x)/2;
 int cmp=pow(x-1);
 for(int i=0;i<len/2;i++)
 {
 	str[x][i]=str[x-1][i];
 	str[x][cmp++]+=str[x][i]+code1;
 }
 for(int i=len/2;i<len;i++)
 {
 	str[x][i]=str[x-1][i];
 	str[x][cmp++]+=str[x][i]+code2;
 }
 code1*=2,code2*=2;
 return ;
}
int main()
{
 freopen("code.in","r",stdin);
 freopen("code.out","w",stdout);
 scanf("%d %lld",&n,&k);
 str[1][0]=0,str[1][1]=1;
 for(int i=2;i<=n;i++)
 {
   code(i);
 }
 int i=0;
 while(str[n][k]!=0)
 {
   num[i]=str[n][k]%2;
   i++;
   str[n][k]/=2;
 }
 i--;
 for(;i>=0;i--)
 {
 	printf("%d",num[i]);
 }
 fclose(stdin);
 fclose(stdout);
 return 0;
}
