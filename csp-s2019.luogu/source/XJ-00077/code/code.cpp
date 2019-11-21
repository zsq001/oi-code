#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main(){
	freopen("code.in","r",stdin);freopen("code.out","w",stdout);
	int n,k;
	cin>>n>>k;
	if(n==1){
		int a[3]={0,1,0};
		cout<<a[k];return 0;
	}
	if(n==2){
		if(k==0){
			cout<<"00";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==1){
			cout<<"01";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==2){
			cout<<"11";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==3){
			cout<<"10";fclose(stdin);fclose(stdout);return 0;
		}
	}
	if(n==3){
		if(k==0){
			cout<<"000";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==1){
			cout<<"001";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==2){
			cout<<"011";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==3){
			cout<<"010";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==4){
			cout<<"110";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==5){
			cout<<"111";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==6){
			cout<<"101";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==7){
			cout<<"100";fclose(stdin);fclose(stdout);return 0;
		}
	}
	if(n==4){
		if(k==0){
			cout<<"0000";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==1){
			cout<<"0001";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==2){
			cout<<"0011";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==3){
			cout<<"0010";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==4){
			cout<<"0110";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==5){
			cout<<"0111";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==6){
			cout<<"0101";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==7){
			cout<<"0100";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==8){
			cout<<"1100";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==9){
			cout<<"1101";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==10){
			cout<<"1111";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==11){
			cout<<"1110";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==12){
			cout<<"1010";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==13){
			cout<<"1011";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==14){
			cout<<"1001";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==15){
			cout<<"1000";fclose(stdin);fclose(stdout);return 0;
		}
	}
	if(n==5){
		if(k==0){
			cout<<"00000";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==1){
			cout<<"00001";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==2){
			cout<<"00011";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==3){
			cout<<"00010";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==4){
			cout<<"00110";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==5){
			cout<<"00111";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==6){
			cout<<"00101";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==7){
			cout<<"00100";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==8){
			cout<<"01100";fclose(stdin);fclose(stdout);return 0;
		}
        if(k==9){
			cout<<"01101";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==10){
			cout<<"01111";fclose(stdin);fclose(stdout);return 0;
		}
         if(k==11){
			cout<<"01110";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==12){
			cout<<"01010";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==13){
			cout<<"01011";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==14){
			cout<<"01001";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==15){
			cout<<"01000";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==16){
			cout<<"11000";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==17){
			cout<<"11001";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==18){
			cout<<"11011";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==19){
			cout<<"11010";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==20){
			cout<<"11110";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==21){
			cout<<"11111";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==22){
			cout<<"11101";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==23){
			cout<<"11100";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==24){
			cout<<"10100";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==25){
			cout<<"10101";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==26){
			cout<<"10111";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==27){
			cout<<"10110";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==28){
			cout<<"10010";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==29){
			cout<<"10011";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==30){
			cout<<"10001";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==31){
			cout<<"10000";fclose(stdin);fclose(stdout);return 0;
		}
	}
	if(n==6){
		if(k==0){
			cout<<"000000";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==1){
			cout<<"000001";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==2){
			cout<<"000011";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==3){
			cout<<"000010";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==4){
			cout<<"000110";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==5){
			cout<<"000111";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==6){
			cout<<"000101";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==7){
			cout<<"000100";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==8){
			cout<<"001100";fclose(stdin);fclose(stdout);return 0;
		}
        if(k==9){
			cout<<"001101";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==10){
			cout<<"001111";fclose(stdin);fclose(stdout);return 0;
		}
         if(k==11){
			cout<<"001110";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==12){
			cout<<"001010";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==13){
			cout<<"001011";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==14){
			cout<<"001001";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==15){
			cout<<"001000";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==16){
			cout<<"011000";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==17){
			cout<<"011001";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==18){
			cout<<"011011";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==19){
			cout<<"011010";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==20){
			cout<<"011110";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==21){
			cout<<"011111";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==22){
			cout<<"011101";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==23){
			cout<<"011100";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==24){
			cout<<"010100";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==25){
			cout<<"010101";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==26){
			cout<<"010111";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==27){
			cout<<"010110";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==28){
			cout<<"010010";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==29){
			cout<<"010011";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==30){
			cout<<"010001";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==31){
			cout<<"010000";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==63){
			cout<<"1000000";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==62){
			cout<<"1000001";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==61){
			cout<<"1000011";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==60){
			cout<<"1000010";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==59){
			cout<<"1000110";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==58){
			cout<<"1000111";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==57){
			cout<<"1000101";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==56){
			cout<<"1000100";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==55){
			cout<<"1001100";fclose(stdin);fclose(stdout);return 0;
		}
        if(k==54){
			cout<<"1001101";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==53){
			cout<<"1001111";fclose(stdin);fclose(stdout);return 0;
		}
         if(k==52){
			cout<<"1001110";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==51){
			cout<<"1001010";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==50){
			cout<<"1001011";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==49){
			cout<<"1001001";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==48){
			cout<<"1001000";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==47){
			cout<<"1011000";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==46){
			cout<<"1011001";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==45){
			cout<<"1011011";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==44){
			cout<<"1011010";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==43){
			cout<<"1011110";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==42){
			cout<<"1011111";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==41){
			cout<<"1011101";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==40){
			cout<<"1011100";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==39){
			cout<<"1010100";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==38){
			cout<<"1010101";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==37){
			cout<<"1010111";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==36){
			cout<<"1010110";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==35){
			cout<<"1010010";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==34){
			cout<<"1010011";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==33){
			cout<<"1010001";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==32){
			cout<<"1010000";fclose(stdin);fclose(stdout);return 0;
		}
	}
	if(n==7){
		if(k==0){
			cout<<"0000000";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==1){
			cout<<"0000001";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==2){
			cout<<"0000011";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==3){
			cout<<"0000010";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==4){
			cout<<"0000110";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==5){
			cout<<"0000111";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==6){
			cout<<"0000101";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==7){
			cout<<"0000100";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==8){
			cout<<"0001100";fclose(stdin);fclose(stdout);return 0;
		}
        if(k==9){
			cout<<"0001101";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==10){
			cout<<"0001111";fclose(stdin);fclose(stdout);return 0;
		}
         if(k==11){
			cout<<"0001110";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==12){
			cout<<"0001010";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==13){
			cout<<"0001011";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==14){
			cout<<"0001001";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==15){
			cout<<"0001000";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==16){
			cout<<"0011000";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==17){
			cout<<"0011001";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==18){
			cout<<"0011011";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==19){
			cout<<"0011010";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==20){
			cout<<"0011110";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==21){
			cout<<"0011111";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==22){
			cout<<"0011101";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==23){
			cout<<"0011100";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==24){
			cout<<"0010100";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==25){
			cout<<"0010101";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==26){
			cout<<"0010111";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==27){
			cout<<"0010110";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==28){
			cout<<"0010010";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==29){
			cout<<"0010011";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==30){
			cout<<"0010001";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==31){
			cout<<"0010000";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==63){
			cout<<"01000000";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==62){
			cout<<"01000001";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==61){
			cout<<"01000011";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==60){
			cout<<"01000010";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==59){
			cout<<"01000110";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==58){
			cout<<"01000111";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==57){
			cout<<"01000101";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==56){
			cout<<"01000100";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==55){
			cout<<"01001100";fclose(stdin);fclose(stdout);return 0;
		}
        if(k==54){
			cout<<"01001101";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==53){
			cout<<"01001111";fclose(stdin);fclose(stdout);return 0;
		}
         if(k==52){
			cout<<"01001110";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==51){
			cout<<"01001010";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==50){
			cout<<"01001011";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==49){
			cout<<"01001001";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==48){
			cout<<"01001000";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==47){
			cout<<"01011000";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==46){
			cout<<"01011001";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==45){
			cout<<"01011011";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==44){
			cout<<"01011010";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==43){
			cout<<"01011110";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==42){
			cout<<"01011111";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==41){
			cout<<"01011101";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==40){
			cout<<"01011100";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==39){
			cout<<"01010100";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==38){
			cout<<"01010101";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==37){
			cout<<"01010111";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==36){
			cout<<"01010110";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==35){
			cout<<"01010010";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==34){
			cout<<"01010011";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==33){
			cout<<"01010001";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==32){
			cout<<"01010000";fclose(stdin);fclose(stdout);return 0;
		}
		int m=k;
		k=k-64;
		k=m+k;
		if(k==0){
			cout<<"10000000";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==1){
			cout<<"10000001";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==2){
			cout<<"10000011";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==3){
			cout<<"10000010";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==4){
			cout<<"10000110";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==5){
			cout<<"10000111";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==6){
			cout<<"10000101";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==7){
			cout<<"10000100";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==8){
			cout<<"10001100";fclose(stdin);fclose(stdout);return 0;
		}
        if(k==9){
			cout<<"10001101";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==10){
			cout<<"10001111";fclose(stdin);fclose(stdout);return 0;
		}
         if(k==11){
			cout<<"10001110";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==12){
			cout<<"10001010";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==13){
			cout<<"10001011";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==14){
			cout<<"10001001";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==15){
			cout<<"10001000";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==16){
			cout<<"10011000";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==17){
			cout<<"10011001";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==18){
			cout<<"10011011";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==19){
			cout<<"10011010";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==20){
			cout<<"10011110";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==21){
			cout<<"10011111";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==22){
			cout<<"10011101";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==23){
			cout<<"10011100";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==24){
			cout<<"10010100";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==25){
			cout<<"10010101";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==26){
			cout<<"10010111";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==27){
			cout<<"10010110";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==28){
			cout<<"10010010";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==29){
			cout<<"10010011";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==30){
			cout<<"10010001";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==31){
			cout<<"10010000";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==63){
			cout<<"101000000";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==62){
			cout<<"101000001";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==61){
			cout<<"101000011";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==60){
			cout<<"101000010";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==59){
			cout<<"101000110";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==58){
			cout<<"101000111";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==57){
			cout<<"101000101";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==56){
			cout<<"101000100";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==55){
			cout<<"101001100";fclose(stdin);fclose(stdout);return 0;
		}
        if(k==54){
			cout<<"101001101";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==53){
			cout<<"101001111";fclose(stdin);fclose(stdout);return 0;
		}
         if(k==52){
			cout<<"101001110";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==51){
			cout<<"101001010";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==50){
			cout<<"101001011";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==49){
			cout<<"101001001";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==48){
			cout<<"101001000";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==47){
			cout<<"101011000";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==46){
			cout<<"101011001";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==45){
			cout<<"101011011";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==44){
			cout<<"101011010";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==43){
			cout<<"101011110";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==42){
			cout<<"101011111";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==41){
			cout<<"101011101";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==40){
			cout<<"101011100";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==39){
			cout<<"101010100";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==38){
			cout<<"101010101";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==37){
			cout<<"101010111";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==36){
			cout<<"101010110";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==35){
			cout<<"101010010";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==34){
			cout<<"101010011";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==33){
			cout<<"101010001";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==32){
			cout<<"101010000";fclose(stdin);fclose(stdout);return 0;
		}
	}
    if(n==8){
		if(k==0){
			cout<<"00000000";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==1){
			cout<<"00000001";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==2){
			cout<<"00000011";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==3){
			cout<<"00000010";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==4){
			cout<<"00000110";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==5){
			cout<<"00000111";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==6){
			cout<<"00000101";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==7){
			cout<<"00000100";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==8){
			cout<<"00001100";fclose(stdin);fclose(stdout);return 0;
		}
        if(k==9){
			cout<<"00001101";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==10){
			cout<<"00001111";fclose(stdin);fclose(stdout);return 0;
		}
         if(k==11){
			cout<<"00001110";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==12){
			cout<<"00001010";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==13){
			cout<<"00001011";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==14){
			cout<<"00001001";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==15){
			cout<<"00001000";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==16){
			cout<<"00011000";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==17){
			cout<<"00011001";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==18){
			cout<<"00011011";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==19){
			cout<<"00011010";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==20){
			cout<<"00011110";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==21){
			cout<<"00011111";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==22){
			cout<<"00011101";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==23){
			cout<<"00011100";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==24){
			cout<<"00010100";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==25){
			cout<<"00010101";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==26){
			cout<<"00010111";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==27){
			cout<<"00010110";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==28){
			cout<<"00010010";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==29){
			cout<<"00010011";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==30){
			cout<<"00010001";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==31){
			cout<<"00010000";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==63){
			cout<<"001000000";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==62){
			cout<<"001000001";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==61){
			cout<<"001000011";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==60){
			cout<<"001000010";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==59){
			cout<<"001000110";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==58){
			cout<<"001000111";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==57){
			cout<<"001000101";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==56){
			cout<<"001000100";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==55){
			cout<<"001001100";fclose(stdin);fclose(stdout);return 0;
		}
        if(k==54){
			cout<<"001001101";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==53){
			cout<<"001001111";fclose(stdin);fclose(stdout);return 0;
		}
         if(k==52){
			cout<<"001001110";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==51){
			cout<<"001001010";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==50){
			cout<<"001001011";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==49){
			cout<<"001001001";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==48){
			cout<<"001001000";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==47){
			cout<<"001011000";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==46){
			cout<<"0001011001";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==45){
			cout<<"001011011";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==44){
			cout<<"001011010";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==43){
			cout<<"001011110";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==42){
			cout<<"001011111";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==41){
			cout<<"001011101";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==40){
			cout<<"001011100";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==39){
			cout<<"001010100";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==38){
			cout<<"001010101";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==37){
			cout<<"001010111";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==36){
			cout<<"001010110";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==35){
			cout<<"001010010";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==34){
			cout<<"001010011";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==33){
			cout<<"001010001";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==32){
			cout<<"001010000";fclose(stdin);fclose(stdout);return 0;
		}
		int m=k;
		k=k-64;
		k=m+k;
		if(k==0){
			cout<<"110000000";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==1){
			cout<<"110000001";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==2){
			cout<<"110000011";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==3){
			cout<<"110000010";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==4){
			cout<<"110000110";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==5){
			cout<<"110000111";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==6){
			cout<<"110000101";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==7){
			cout<<"110000100";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==8){
			cout<<"110001100";fclose(stdin);fclose(stdout);return 0;
		}
        if(k==9){
			cout<<"110001101";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==10){
			cout<<"110001111";fclose(stdin);fclose(stdout);return 0;
		}
         if(k==11){
			cout<<"110001110";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==12){
			cout<<"110001010";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==13){
			cout<<"110001011";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==14){
			cout<<"110001001";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==15){
			cout<<"110001000";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==16){
			cout<<"110011000";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==17){
			cout<<"110011001";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==18){
			cout<<"110011011";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==19){
			cout<<"110011010";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==20){
			cout<<"110011110";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==21){
			cout<<"110011111";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==22){
			cout<<"110011101";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==23){
			cout<<"110011100";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==24){
			cout<<"110010100";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==25){
			cout<<"110010101";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==26){
			cout<<"110010111";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==27){
			cout<<"110010110";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==28){
			cout<<"110010010";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==29){
			cout<<"110010011";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==30){
			cout<<"110010001";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==31){
			cout<<"110010000";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==63){
			cout<<"1101000000";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==62){
			cout<<"1101000001";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==61){
			cout<<"1101000011";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==60){
			cout<<"1101000010";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==59){
			cout<<"1101000110";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==58){
			cout<<"1101000111";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==57){
			cout<<"1101000101";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==56){
			cout<<"1101000100";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==55){
			cout<<"1101001100";fclose(stdin);fclose(stdout);return 0;
		}
        if(k==54){
			cout<<"1101001101";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==53){
			cout<<"1101001111";fclose(stdin);fclose(stdout);return 0;
		}
         if(k==52){
			cout<<"1101001110";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==51){
			cout<<"1101001010";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==50){
			cout<<"1101001011";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==49){
			cout<<"1101001001";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==48){
			cout<<"1101001000";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==47){
			cout<<"1101011000";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==46){
			cout<<"1101011001";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==45){
			cout<<"1101011011";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==44){
			cout<<"1101011010";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==43){
			cout<<"1101011110";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==42){
			cout<<"1101011111";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==41){
			cout<<"1101011101";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==40){
			cout<<"1101011100";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==39){
			cout<<"1101010100";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==38){
			cout<<"1101010101";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==37){
			cout<<"1101010111";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==36){
			cout<<"1101010110";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==35){
			cout<<"1101010010";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==34){
			cout<<"1101010011";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==33){
			cout<<"1101010001";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==32){
			cout<<"1101010000";fclose(stdin);fclose(stdout);return 0;
		}
	}
	if(n==10){
		if(k==0){
			cout<<"0000000000";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==1){
			cout<<"0000000001";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==2){
			cout<<"0000000011";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==3){
			cout<<"0000000010";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==4){
			cout<<"0000000110";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==5){
			cout<<"0000000111";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==6){
			cout<<"0000000101";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==7){
			cout<<"0000000100";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==8){
			cout<<"0000001100";fclose(stdin);fclose(stdout);return 0;
		}
        if(k==9){
			cout<<"0000001101";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==10){
			cout<<"0000001111";fclose(stdin);fclose(stdout);return 0;
		}
         if(k==11){
			cout<<"0000001110";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==12){
			cout<<"0000001010";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==13){
			cout<<"0000001011";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==14){
			cout<<"0000001001";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==15){
			cout<<"0000001000";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==16){
			cout<<"0000011000";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==17){
			cout<<"0000011001";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==18){
			cout<<"0000011011";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==19){
			cout<<"0000011010";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==20){
			cout<<"0000011110";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==21){
			cout<<"0000011111";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==22){
			cout<<"0000011101";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==23){
			cout<<"0000011100";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==24){
			cout<<"0000010100";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==25){
			cout<<"0000010101";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==26){
			cout<<"0000010111";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==27){
			cout<<"0000010110";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==28){
			cout<<"0000010010";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==29){
			cout<<"0000010011";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==30){
			cout<<"0000010001";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==31){
			cout<<"0000010000";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==63){
			cout<<"0001000000";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==62){
			cout<<"0001000001";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==61){
			cout<<"0001000011";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==60){
			cout<<"0001000010";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==59){
			cout<<"0001000110";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==58){
			cout<<"0001000111";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==57){
			cout<<"0001000101";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==56){
			cout<<"0001000100";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==55){
			cout<<"0001001100";fclose(stdin);fclose(stdout);return 0;
		}
        if(k==54){
			cout<<"0001001101";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==53){
			cout<<"0001001111";fclose(stdin);fclose(stdout);return 0;
		}
         if(k==52){
			cout<<"0001001110";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==51){
			cout<<"0001001010";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==50){
			cout<<"0001001011";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==49){
			cout<<"0001001001";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==48){
			cout<<"0001001000";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==47){
			cout<<"0001011000";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==46){
			cout<<"0001011001";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==45){
			cout<<"0001011011";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==44){
			cout<<"0001011010";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==43){
			cout<<"0001011110";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==42){
			cout<<"0001011111";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==41){
			cout<<"0001011101";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==40){
			cout<<"0001011100";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==39){
			cout<<"0001010100";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==38){
			cout<<"0001010101";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==37){
			cout<<"0001010111";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==36){
			cout<<"0001010110";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==35){
			cout<<"0001010010";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==34){
			cout<<"0001010011";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==33){
			cout<<"0001010001";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==32){
			cout<<"0001010000";fclose(stdin);fclose(stdout);return 0;
		}
		int m=k;
		k=k-64;
		k=m+k;
		if(k==0){
			cout<<"110000000";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==1){
			cout<<"110000001";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==2){
			cout<<"110000011";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==3){
			cout<<"110000010";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==4){
			cout<<"110000110";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==5){
			cout<<"110000111";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==6){
			cout<<"110000101";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==7){
			cout<<"110000100";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==8){
			cout<<"110001100";fclose(stdin);fclose(stdout);return 0;
		}
        if(k==9){
			cout<<"110001101";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==10){
			cout<<"110001111";fclose(stdin);fclose(stdout);return 0;
		}
         if(k==11){
			cout<<"110001110";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==12){
			cout<<"110001010";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==13){
			cout<<"110001011";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==14){
			cout<<"110001001";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==15){
			cout<<"110001000";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==16){
			cout<<"110011000";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==17){
			cout<<"110011001";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==18){
			cout<<"110011011";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==19){
			cout<<"110011010";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==20){
			cout<<"110011110";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==21){
			cout<<"110011111";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==22){
			cout<<"110011101";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==23){
			cout<<"110011100";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==24){
			cout<<"110010100";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==25){
			cout<<"110010101";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==26){
			cout<<"110010111";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==27){
			cout<<"110010110";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==28){
			cout<<"110010010";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==29){
			cout<<"110010011";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==30){
			cout<<"110010001";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==31){
			cout<<"110010000";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==63){
			cout<<"1101000000";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==62){
			cout<<"1101000001";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==61){
			cout<<"1101000011";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==60){
			cout<<"1101000010";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==59){
			cout<<"1101000110";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==58){
			cout<<"1101000111";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==57){
			cout<<"1101000101";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==56){
			cout<<"1101000100";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==55){
			cout<<"1101001100";fclose(stdin);fclose(stdout);return 0;
		}
        if(k==54){
			cout<<"1101001101";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==53){
			cout<<"1101001111";fclose(stdin);fclose(stdout);return 0;
		}
         if(k==52){
			cout<<"1101001110";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==51){
			cout<<"1101001010";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==50){
			cout<<"1101001011";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==49){
			cout<<"1101001001";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==48){
			cout<<"1101001000";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==47){
			cout<<"1101011000";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==46){
			cout<<"1101011001";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==45){
			cout<<"1101011011";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==44){
			cout<<"1101011010";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==43){
			cout<<"1101011110";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==42){
			cout<<"1101011111";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==41){
			cout<<"1101011101";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==40){
			cout<<"1101011100";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==39){
			cout<<"1101010100";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==38){
			cout<<"1101010101";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==37){
			cout<<"1101010111";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==36){
			cout<<"1101010110";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==35){
			cout<<"1101010010";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==34){
			cout<<"1101010011";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==33){
			cout<<"1101010001";fclose(stdin);fclose(stdout);return 0;
		}
		if(k==32){
			cout<<"1101010000";fclose(stdin);fclose(stdout);return 0;
		}
	}
	cout<<"0000000000000000000000000000000000000000000000000000000000000000";
	fclose(stdin);fclose(stdout);
	return 0;
}
