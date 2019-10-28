#include <cstdio>
int main()
{
 freopen("plate.in","w",stdout);
 puts("500 500 500");
 for(int i=1;i<=500;i++)
 {
  for(int j=1;j<=500;j++)
   printf("%d ",j);
  puts("");
 }
 return 0;
}
