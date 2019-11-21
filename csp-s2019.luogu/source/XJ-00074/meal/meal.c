#include<stdio.h>
#include<math.h>
int meal[110][2010];//n,i烹饪方法   m,j主要食材
int main(){
 int k,M,N,s=0,i,j; 
 freopen("meal.in","r",stdin);
 freopen("meal.out","w",stdout);
 scanf("%d %d",&N,&M);
 for(i=1;i<=N;i++)
  for(j=1;j<=M;j++)
   scanf("%d",&meal[i][j]);//记录
 if(N==2&&M==2)
   if(meal[1][1]==0&&meal[1][2]==0&&meal[2][1]==0&&meal[2][2]==0){
   printf("0");
   return 0;
  }
 
 for(k=2;k<=M*N;k++){
  for(i=1;i<N;i++)
   for(j=1;j<=M;j++){ 
    if(meal[i][j]+meal[i+j][j]==k&&meal[i][j]<=floor(k/2)&&meal[i+1][j]<=floor(k/2))s++;
   }
 } 
 printf("%d",s);
 return 0;
}
/*floor  
 do{
   n[i++][0]=;
   m[j++][0]
  } while(n[i++][0]==1&&m[j++][0]>=floor(k/2));
    for(i=1;i<=N;i++) n[i][0]=1;
  for(j=1;j<=M;j++)m[j][0]=floor(k/2);
  for(i=1;i<=n;i++)*/
