#include<stdio.h>
#include<math.h>
float v,temp,c;
int a,s,min=999999999;
int asd(float x){
	int y=x/1;
	if(x-y!=0)return 0;
	else return 1;
}
int main(){
	freopen("box.in","r",stdin);
	freopen("box.out","w",stdout);
	int i,j;
	scanf("%f",&v);
	temp=pow(v,1.0/3);
    a=temp/1;
    for(i=a;i>0;i--){
    	for(j=a;j*i<=v;j++){
    		if(asd(v/(i*j))==0)continue;
    		c=v/(i*j);
    		s=2*(i*j+i*c+j*c);
    		if(s<min)min=s;
    	}
    }
    printf("%d",min);
    
}
