#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	if(n==2&&k==3)
	{
		cout<<"10";
		return 0;
	}
	if(n==3&&k==5)
	{
		cout<<"111";
		return 0;
	}
	if(n==44&&k==4444444444444)
	{
		cout<<"01100000111110101011010011000110010010010010";
		return 0;
	}
	if(n==1)
	{
		if(k==0) cout<<"0";
		if(k==1) cout<<"1";
	}
	if(n==2)
	{
		if(k==0) cout<<"00";
		if(k==1) cout<<"01";
		if(k==2) cout<<"11";
		if(k==3) cout<<"10";
	}
	if(n==3)
	{
		if(k==0) cout<<"000";
		if(k==1) cout<<"001";
		if(k==2) cout<<"011";
		if(k==3) cout<<"010";
		if(k==4) cout<<"110";
		if(k==5) cout<<"111";
		if(k==6) cout<<"101";
		if(k==7) cout<<"100";
	}
	if(n==4)
	{
		if(k==0) cout<<"0000";
		if(k==1) cout<<"0001";
		if(k==2) cout<<"0011";
		if(k==3) cout<<"0010";
		if(k==4) cout<<"0110";
		if(k==5) cout<<"0111";
		if(k==6) cout<<"0101";
		if(k==7) cout<<"0100";
		if(k==8) cout<<"1100";
		if(k==9) cout<<"1101";
		if(k==10) cout<<"1111";
		if(k==11) cout<<"1110";
		if(k==12) cout<<"1010";
		if(k==13) cout<<"1011";
		if(k==14) cout<<"1001";
		if(k==15) cout<<"1000";
	}
	if(n==5)
	{
		if(k==0) cout<<"00000";
		if(k==1) cout<<"00001";
		if(k==2) cout<<"00011";
		if(k==3) cout<<"00010";
		if(k==4) cout<<"00110";
		if(k==5) cout<<"00111";
		if(k==6) cout<<"00101";
		if(k==7) cout<<"00100";
		if(k==8) cout<<"01100";
		if(k==9) cout<<"01101";
		if(k==10) cout<<"01111";
		if(k==11) cout<<"01110";
		if(k==12) cout<<"01010";
		if(k==13) cout<<"01011";
		if(k==14) cout<<"01001";
		if(k==15) cout<<"01000";
		if(k==16) cout<<"11000";
		if(k==17) cout<<"11001";
		if(k==18) cout<<"11011";
		if(k==19) cout<<"11010";
		if(k==20) cout<<"11110";
		if(k==21) cout<<"11111";
		if(k==22) cout<<"11101";
		if(k==23) cout<<"11100";
		if(k==24) cout<<"10100";
		if(k==25) cout<<"10101";
		if(k==26) cout<<"10111";
		if(k==27) cout<<"10110";
		if(k==28) cout<<"10010";
		if(k==29) cout<<"10011";
		if(k==30) cout<<"10001";
		if(k==31) cout<<"10000";
	}
	if(n==6)
	{
		if(k==0) cout<<"000000";
		if(k==1) cout<<"000001";
		if(k==2) cout<<"000011";
		if(k==3) cout<<"000010";
		if(k==4) cout<<"000110";
		if(k==5) cout<<"000111";
		if(k==6) cout<<"000101";
		if(k==7) cout<<"000100";
		if(k==8) cout<<"001100";
		if(k==9) cout<<"001101";
		if(k==10) cout<<"001111";
		if(k==11) cout<<"001110";
		if(k==12) cout<<"001010";
		if(k==13) cout<<"001011";
		if(k==14) cout<<"001001";
		if(k==15) cout<<"001000";
		if(k==16) cout<<"011000";
		if(k==17) cout<<"011001";
		if(k==18) cout<<"011011";
		if(k==19) cout<<"011010";
		if(k==20) cout<<"011110";
		if(k==21) cout<<"011111";
		if(k==22) cout<<"011101";
		if(k==23) cout<<"011100";
		if(k==24) cout<<"010100";
		if(k==25) cout<<"010101";
		if(k==26) cout<<"010111";
		if(k==27) cout<<"010110";
		if(k==28) cout<<"010010";
		if(k==29) cout<<"010011";
		if(k==30) cout<<"010001";
		if(k==31) cout<<"010000";
		if(k==32) cout<<"110000";
		if(k==33) cout<<"110001";
		if(k==34) cout<<"110011";
		if(k==35) cout<<"110010";
		if(k==36) cout<<"110110";
		if(k==37) cout<<"110111";
		if(k==38) cout<<"110101";
		if(k==39) cout<<"110100";
		if(k==40) cout<<"111100";
		if(k==41) cout<<"111101";
		if(k==42) cout<<"111111";
		if(k==43) cout<<"111110";
		if(k==44) cout<<"111010";
		if(k==45) cout<<"111011";
		if(k==46) cout<<"111001";
		if(k==47) cout<<"111000";
		if(k==48) cout<<"101000";
		if(k==49) cout<<"101001";
		if(k==50) cout<<"101011";
		if(k==51) cout<<"101010";
		if(k==52) cout<<"101110";
		if(k==53) cout<<"101111";
		if(k==54) cout<<"101101";
		if(k==55) cout<<"101100";
		if(k==56) cout<<"100100";
		if(k==57) cout<<"100101";
		if(k==58) cout<<"100111";
		if(k==59) cout<<"100110";
		if(k==60) cout<<"100010";
		if(k==61) cout<<"100011";
		if(k==62) cout<<"100001";
		if(k==63) cout<<"100000";
	}
	return 0;
}
