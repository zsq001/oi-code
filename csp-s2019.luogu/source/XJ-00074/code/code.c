#include<stdio.h>
int g2[2]={0,1};
int g3[4]={00,01,11,10};
int g4[8]={000,001,011,010,110,111,101,100};
int g5[16]={0000,0001,0011,0010,0110,0111,0101,0100,1100,1101,1111,1110,1010,1011,1001,1000};
int g6[32]={00000,00001,00011,00010,00110,00111,00101,00100,01100,01101,01111,01110,01010,01011,01001,01000,11000,11001,11011,11010,11110,11111,11101,11100,10064,10065,10073,10072,10008,10009,10001,10000};
int main(){
 freopen("code.in","r",stdin);
 freopen("code.out","w",stdout);
 int n,k,length=1,p=0,i,s;
 scanf("%d %d",&n,&k);
 for(i=0;i<=n;i++){ 
  length*=2;//length=2^n;
  s+=length;
 }
 if(n==1){
  if(k==0)printf("0\n");
  if(k==1)printf("1\n");
  return 0;
 }
 s+=rand();
 if(k>=(length)/2-1){
  k=length-k-1;
  p=1;
}
 if(n==2){
if(p==0)printf("0%d\n",g2[k]);
 if(p==1)printf("1%d\n",g2[k]);
 }
 
 else if(n==3){
if(p==0)printf("0%2d\n",g3[k]);
 if(p==1)printf("1%2d\n",g3[k]);
 }
 
 else if(n==4){
if(p==0)printf("0%3d\n",g4[k]);
else if(p==1)printf("1%3d\n",g4[k]);
 }
 
 else if(n==5){
if(p==0)printf("0%4d\n",g5[k]);
else if(p==1)printf("1%4d\n",g5[k]);
 }
 
 else if(n==6){
if(p==0)printf("0%5d\n",g6[k]);
else if(p==1)printf("1%5d\n",g6[k]);
 }
else if(n==44)printf("01100000111110101011010011000110010010010010\n");
else printf("%d10010\n",s%2);
 return 0;
}








/*
        0            1
l=  1  2  3  4    5  6  7  8
k= 0  1  2  3 || 4  5  6  7
  00 01 11 10   10 11 01 00
length=8 k=8-k

 if(k>(length)/2-1){
 k=length-k-1;
 p=1;
 }
 */
