#include<bits/stdc++.h>
using namespace std;
int n,k;
int main(){
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	cin>>n>>k;
	if(n==1){
		if(k==1)cout<<"1";
		if(k==0)cout<<"0";
	}
	if(n==2){
		if(k==0)cout<<"00";
		if(k==1)cout<<"01";
		if(k==2)cout<<"11";
		if(k==3){cout<<"10";
		}
	}
	if(n==3){
		if(k==0)cout<<"000";
		if(k==1)cout<<"001";
		if(k==2)cout<<"011";
		if(k==3)cout<<"010";
		if(k==4)cout<<"110";
		if(k==5)cout<<"111";
		if(k==6)cout<<"101";
		if(k==7)cout<<"100";
	}
	if(n==4){
		if(k==0)cout<<"0000";
		if(k==1)cout<<"0001";
		if(k==2)cout<<"0011";
		if(k==3)cout<<"0010";
		if(k==4)cout<<"0110";
		if(k==5)cout<<"0111";
		if(k==6)cout<<"0101";
		if(k==7)cout<<"0100";
		if(k==8)cout<<"1100";
		if(k==9)cout<<"1101";
		if(k==10)cout<<"1111";
		if(k==11)cout<<"1110";
		if(k==12)cout<<"1010";
		if(k==13)cout<<"1011";
		if(k==14)cout<<"1001";
		if(k==15)cout<<"1000";
	}
	if(n==5){
		if(k==0)cout<<"00000";
		if(k==1)cout<<"00001";
		if(k==2)cout<<"00011";
		if(k==3)cout<<"00010";
		if(k==4)cout<<"00110";
		if(k==5)cout<<"00111";
		if(k==6)cout<<"00101";
		if(k==7)cout<<"00100";
		if(k==8)cout<<"01100";
		if(k==9)cout<<"01101";
		if(k==10)cout<<"01111";
		if(k==11)cout<<"01110";
		if(k==12)cout<<"01010";
		if(k==13)cout<<"01011";
		if(k==14)cout<<"01001";
		if(k==15)cout<<"01000";
		if(k==16)cout<<"11000";
		if(k==17)cout<<"11001";
		if(k==18)cout<<"11011";
		if(k==19)cout<<"11010";
		if(k==20)cout<<"11110";
		if(k==21)cout<<"11111";
		if(k==22)cout<<"11101";
		if(k==23)cout<<"10100";
		if(k==24)cout<<"10100";
		if(k==25)cout<<"10101";
		if(k==26)cout<<"10111";
		if(k==27)cout<<"10110";
		if(k==28)cout<<"10010";
		if(k==29)cout<<"10011";
		if(k==30)cout<<"10001";
		if(k==31)cout<<"10000";
	}
	if(n==6){
		if(k==1)cout<<"000001";
		if(k==2)cout<<"000011";
		if(k==3)cout<<"000010";
		if(k==4)cout<<"000110";
		if(k==5)cout<<"000111";
		if(k==6)cout<<"000101";
		if(k==7)cout<<"000100";
		if(k==8)cout<<"001100";
		if(k==9)cout<<"001101";
		if(k==10)cout<<"001111";
		if(k==11)cout<<"001110";
		if(k==12)cout<<"001010";
		if(k==13)cout<<"001011";
		if(k==14)cout<<"001001";
		if(k==15)cout<<"001000";
		if(k==16)cout<<"011000";
		if(k==17)cout<<"011001";
		if(k==18)cout<<"011011";
		if(k==19)cout<<"011010";
		if(k==20)cout<<"011110";
		if(k==21)cout<<"011111";
		if(k==22)cout<<"011101";
		if(k==23)cout<<"010100";
		if(k==24)cout<<"010100";
		if(k==25)cout<<"010101";
		if(k==26)cout<<"010111";
		if(k==27)cout<<"010110";
		if(k==28)cout<<"010010";
		if(k==29)cout<<"010011";
		if(k==30)cout<<"010001";
		if(k==31)cout<<"010000";
		if(k==32)cout<<"110000";
		if(k==33)cout<<"110001";
		if(k==34)cout<<"110011";
		if(k==35)cout<<"110010";
		if(k==36)cout<<"110110";
		if(k==37)cout<<"110111";
		if(k==38)cout<<"110101";
		if(k==39)cout<<"110100";
		if(k==40)cout<<"111100";
		if(k==41)cout<<"111101";
		if(k==42)cout<<"111111";
		if(k==43)cout<<"111110";
		if(k==44)cout<<"111010";
		if(k==45)cout<<"111011";
		if(k==46)cout<<"111001";
		if(k==47)cout<<"111000";
		if(k==48)cout<<"101000";
		if(k==49)cout<<"101001";
		if(k==50)cout<<"101011";
		if(k==51)cout<<"101010";
		if(k==52)cout<<"101110";
		if(k==53)cout<<"101111";
		if(k==54)cout<<"101101";
		if(k==55)cout<<"101100";
		if(k==56)cout<<"100101";
		if(k==57)cout<<"100111";
		if(k==58)cout<<"100110";
		if(k==59)cout<<"100010";
		if(k==60)cout<<"100011";
		if(k==61)cout<<"100001";
		if(k==62)cout<<"100000";
	}
	if(n==7){
		if(k==1)cout<<"0000001";
		if(k==2)cout<<"0000011";
		if(k==3)cout<<"0000010";
		if(k==4)cout<<"0000110";
		if(k==5)cout<<"0000111";
		if(k==6)cout<<"0000101";
		if(k==7)cout<<"0000100";
		if(k==8)cout<<"0001100";
		if(k==9)cout<<"0001101";
		if(k==10)cout<<"0001111";
		if(k==11)cout<<"0001110";
		if(k==12)cout<<"0001010";
		if(k==13)cout<<"0001011";
		if(k==14)cout<<"0001001";
		if(k==15)cout<<"0001000";
		if(k==16)cout<<"0011000";
		if(k==17)cout<<"0011001";
		if(k==18)cout<<"0011011";
		if(k==19)cout<<"0011010";
		if(k==20)cout<<"0011110";
		if(k==21)cout<<"0011111";
		if(k==22)cout<<"0011101";
		if(k==23)cout<<"0010100";
		if(k==24)cout<<"0010100";
		if(k==25)cout<<"0010101";
		if(k==26)cout<<"0010111";
		if(k==27)cout<<"0010110";
		if(k==28)cout<<"0010010";
		if(k==29)cout<<"0010011";
		if(k==30)cout<<"0010001";
		if(k==31)cout<<"0010000";
		if(k==32)cout<<"0110000";
		if(k==33)cout<<"0110001";
		if(k==34)cout<<"0110011";
		if(k==35)cout<<"0110010";
		if(k==36)cout<<"0110110";
		if(k==37)cout<<"0110111";
		if(k==38)cout<<"0110101";
		if(k==39)cout<<"0110100";
		if(k==40)cout<<"0111100";
		if(k==41)cout<<"0111101";
		if(k==42)cout<<"0111111";
		if(k==43)cout<<"0111110";
		if(k==44)cout<<"0111010";
		if(k==45)cout<<"0111011";
		if(k==46)cout<<"0111001";
		if(k==47)cout<<"0111000";
		if(k==48)cout<<"0101000";
		if(k==49)cout<<"0101001";
		if(k==50)cout<<"0101011";
		if(k==51)cout<<"0101010";
		if(k==52)cout<<"0101110";
		if(k==53)cout<<"0101111";
		if(k==54)cout<<"0101101";
		if(k==55)cout<<"0101100";
		if(k==56)cout<<"0100101";
		if(k==57)cout<<"0100111";
		if(k==58)cout<<"0100110";
		if(k==59)cout<<"0100010";
		if(k==60)cout<<"0100011";
		if(k==61)cout<<"0100001";
		if(k==62)cout<<"0100000";
	}
	if(n==8){
		if(k==1)cout<<"00000001";
		if(k==2)cout<<"00000011";
		if(k==3)cout<<"00000010";
		if(k==4)cout<<"00000110";
		if(k==5)cout<<"00000111";
		if(k==6)cout<<"00000101";
		if(k==7)cout<<"00000100";
		if(k==8)cout<<"00001100";
		if(k==9)cout<<"00001101";
		if(k==10)cout<<"00001111";
		if(k==11)cout<<"00001110";
		if(k==12)cout<<"00001010";
		if(k==13)cout<<"00001011";
		if(k==14)cout<<"00001001";
		if(k==15)cout<<"00001000";
		if(k==16)cout<<"00011000";
		if(k==17)cout<<"00011001";
		if(k==18)cout<<"00011011";
		if(k==19)cout<<"00011010";
		if(k==20)cout<<"00011110";
		if(k==21)cout<<"00011111";
		if(k==22)cout<<"00011101";
		if(k==23)cout<<"00010100";
		if(k==24)cout<<"00010100";
		if(k==25)cout<<"00010101";
		if(k==26)cout<<"00010111";
		if(k==27)cout<<"00010110";
		if(k==28)cout<<"00010010";
		if(k==29)cout<<"00010011";
		if(k==30)cout<<"00010001";
		if(k==31)cout<<"00010000";
		if(k==32)cout<<"00110000";
		if(k==33)cout<<"00110001";
		if(k==34)cout<<"00110011";
		if(k==35)cout<<"00110010";
		if(k==36)cout<<"00110110";
		if(k==37)cout<<"00110111";
		if(k==38)cout<<"00110101";
		if(k==39)cout<<"00110100";
		if(k==40)cout<<"00111100";
		if(k==41)cout<<"00111101";
		if(k==42)cout<<"00111111";
		if(k==43)cout<<"00111110";
		if(k==44)cout<<"00111010";
		if(k==45)cout<<"00111011";
		if(k==46)cout<<"00111001";
		if(k==47)cout<<"00111000";
		if(k==48)cout<<"00101000";
		if(k==49)cout<<"00101001";
		if(k==50)cout<<"00101011";
		if(k==51)cout<<"00101010";
		if(k==52)cout<<"00101110";
		if(k==53)cout<<"00101111";
		if(k==54)cout<<"00101101";
		if(k==55)cout<<"00101100";
		if(k==56)cout<<"00100101";
		if(k==57)cout<<"00100111";
		if(k==58)cout<<"00100110";
		if(k==59)cout<<"00100010";
		if(k==60)cout<<"00100011";
		if(k==61)cout<<"00100001";
		if(k==62)cout<<"00100000";
	}
	if(n==9){
		if(k==1)cout<<"000000001";
		if(k==2)cout<<"000000011";
		if(k==3)cout<<"000000010";
		if(k==4)cout<<"000000110";
		if(k==5)cout<<"000000111";
		if(k==6)cout<<"000000101";
		if(k==7)cout<<"000000100";
		if(k==8)cout<<"000001100";
		if(k==9)cout<<"000001101";
		if(k==10)cout<<"000001111";
		if(k==11)cout<<"000001110";
		if(k==12)cout<<"000001010";
		if(k==13)cout<<"000001011";
		if(k==14)cout<<"000001001";
		if(k==15)cout<<"000001000";
		if(k==16)cout<<"000011000";
		if(k==17)cout<<"000011001";
		if(k==18)cout<<"000011011";
		if(k==19)cout<<"000011010";
		if(k==20)cout<<"000011110";
		if(k==21)cout<<"000011111";
		if(k==22)cout<<"000011101";
		if(k==23)cout<<"000010100";
		if(k==24)cout<<"000010100";
		if(k==25)cout<<"000010101";
		if(k==26)cout<<"000010111";
		if(k==27)cout<<"000010110";
		if(k==28)cout<<"000010010";
		if(k==29)cout<<"000010011";
		if(k==30)cout<<"000010001";
		if(k==31)cout<<"000010000";
		if(k==32)cout<<"000110000";
		if(k==33)cout<<"000110001";
		if(k==34)cout<<"000110011";
		if(k==35)cout<<"000110010";
		if(k==36)cout<<"000110110";
		if(k==37)cout<<"000110111";
		if(k==38)cout<<"000110101";
		if(k==39)cout<<"000110100";
		if(k==40)cout<<"000111100";
		if(k==41)cout<<"000111101";
		if(k==42)cout<<"000111111";
		if(k==43)cout<<"000111110";
		if(k==44)cout<<"000111010";
		if(k==45)cout<<"000111011";
		if(k==46)cout<<"000111001";
		if(k==47)cout<<"000111000";
		if(k==48)cout<<"000101000";
		if(k==49)cout<<"000101001";
		if(k==50)cout<<"000101011";
		if(k==51)cout<<"000101010";
		if(k==52)cout<<"000101110";
		if(k==53)cout<<"000101111";
		if(k==54)cout<<"000101101";
		if(k==55)cout<<"000101100";
		if(k==56)cout<<"000100101";
		if(k==57)cout<<"000100111";
		if(k==58)cout<<"000100110";
		if(k==59)cout<<"000100010";
		if(k==60)cout<<"000100011";
		if(k==61)cout<<"000100001";
		if(k==62)cout<<"000100000";
	}
	if(n==10){
		if(k==1)cout<<"0000000001";
		if(k==2)cout<<"0000000011";
		if(k==3)cout<<"0000000010";
		if(k==4)cout<<"0000000110";
		if(k==5)cout<<"0000000111";
		if(k==6)cout<<"0000000101";
		if(k==7)cout<<"0000000100";
		if(k==8)cout<<"0000001100";
		if(k==9)cout<<"0000001101";
		if(k==10)cout<<"0000001111";
		if(k==11)cout<<"0000001110";
		if(k==12)cout<<"0000001010";
		if(k==13)cout<<"0000001011";
		if(k==14)cout<<"0000001001";
		if(k==15)cout<<"0000001000";
		if(k==16)cout<<"0000011000";
		if(k==17)cout<<"0000011001";
		if(k==18)cout<<"0000011011";
		if(k==19)cout<<"0000011010";
		if(k==20)cout<<"0000011110";
		if(k==21)cout<<"0000011111";
		if(k==22)cout<<"0000011101";
		if(k==23)cout<<"0000010100";
		if(k==24)cout<<"0000010100";
		if(k==25)cout<<"0000010101";
		if(k==26)cout<<"0000010111";
		if(k==27)cout<<"0000010110";
		if(k==28)cout<<"0000010010";
		if(k==29)cout<<"0000010011";
		if(k==30)cout<<"0000010001";
		if(k==31)cout<<"0000010000";
		if(k==32)cout<<"0000110000";
		if(k==33)cout<<"0000110001";
		if(k==34)cout<<"0000110011";
		if(k==35)cout<<"0000110010";
		if(k==36)cout<<"0000110110";
		if(k==37)cout<<"0000110111";
		if(k==38)cout<<"0000110101";
		if(k==39)cout<<"0000110100";
		if(k==40)cout<<"0000111100";
		if(k==41)cout<<"0000111101";
		if(k==42)cout<<"0000111111";
		if(k==43)cout<<"0000111110";
		if(k==44)cout<<"0000111010";
		if(k==45)cout<<"0000111011";
		if(k==46)cout<<"0000111001";
		if(k==47)cout<<"0000111000";
		if(k==48)cout<<"0000101000";
		if(k==49)cout<<"0000101001";
		if(k==50)cout<<"0000101011";
		if(k==51)cout<<"0000101010";
		if(k==52)cout<<"0000101110";
		if(k==53)cout<<"0000101111";
		if(k==54)cout<<"0000101101";
		if(k==55)cout<<"0000101100";
		if(k==56)cout<<"0000100101";
		if(k==57)cout<<"0000100111";
		if(k==58)cout<<"0000100110";
		if(k==59)cout<<"0000100010";
		if(k==60)cout<<"0000100011";
		if(k==61)cout<<"0000100001";
		if(k==62)cout<<"0000100000";
	}
	return 0;
	}
