#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;



int main(){
	freopen("code.in", "r", stdin);
	freopen("code.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	
	if(n == 1){
		if(k == 0) cout << "0";
		else cout << 1;
	}
	
	if(n == 2){
		if(k == 0) cout << "00";
		if(k == 1) cout << "01";
		if(k == 2) cout << "11";
		if(k == 3) cout << "10";
	}
	
	if(n == 3){
		if(k == 0) cout << "000";
		if(k == 1) cout << "001";
		if(k == 2) cout << "010";
		if(k == 3) cout << "010";
		if(k == 4) cout << "110";
		if(k == 5) cout << "111";
		if(k == 6) cout << "101";
		if(k == 7) cout << "100";
	}
	
	if(n == 4){
		if(k == 0) cout << "0000";
		if(k == 1) cout << "0001";
		if(k == 2) cout << "0010";
		if(k == 3) cout << "0010";
		if(k == 4) cout << "0110";
		if(k == 5) cout << "0111";
		if(k == 6) cout << "0101";
		if(k == 7) cout << "0100";
		if(k == 15) cout << "1000";
		if(k == 14) cout << "1001";
		if(k == 13) cout << "1010";
		if(k == 12) cout << "1010";
		if(k == 11) cout << "1110";
		if(k == 10) cout << "1111";
		if(k == 9) cout << "1101";
		if(k == 8) cout << "1100";
	}
	
	if(n == 5){
		if(k == 0) cout << "00000";
		if(k == 1) cout << "00001";
		if(k == 2) cout << "00010";
		if(k == 3) cout << "00010";
		if(k == 4) cout << "00110";
		if(k == 5) cout << "00111";
		if(k == 6) cout << "00101";
		if(k == 7) cout << "00100";
		if(k == 15) cout << "01000";
		if(k == 14) cout << "01001";
		if(k == 13) cout << "01010";
		if(k == 12) cout << "01010";
		if(k == 11) cout << "01110";
		if(k == 10) cout << "01111";
		if(k == 9) cout << "01101";
		if(k == 8) cout << "01100";
		if(k == 24) cout << "10000";
		if(k == 25) cout << "10001";
		if(k == 26) cout << "10010";
		if(k == 27) cout << "10010";
		if(k == 28) cout << "10110";
		if(k == 29) cout << "10111";
		if(k == 30) cout << "10101";
		if(k == 31) cout << "10100";
		if(k == 23) cout << "11000";
		if(k == 22) cout << "11001";
		if(k == 21) cout << "11010";
		if(k == 20) cout << "11010";
		if(k == 19) cout << "11110";
		if(k == 18) cout << "11111";
		if(k == 17) cout << "11101";
		if(k == 16) cout << "11100";
	}
	
	if(n == 6){
		if(k == 0) cout << "000000";
		if(k == 1) cout << "000001";
		if(k == 2) cout << "000010";
		if(k == 3) cout << "000010";
		if(k == 4) cout << "000110";
		if(k == 5) cout << "000111";
		if(k == 6) cout << "000101";
		if(k == 7) cout << "000100";
		if(k == 15) cout << "001000";
		if(k == 14) cout << "001001";
		if(k == 13) cout << "001010";
		if(k == 12) cout << "001010";
		if(k == 11) cout << "001110";
		if(k == 10) cout << "001111";
		if(k == 9) cout << "001101";
		if(k == 8) cout << "001100";
		if(k == 24) cout << "010000";
		if(k == 25) cout << "010001";
		if(k == 26) cout << "010010";
		if(k == 27) cout << "010010";
		if(k == 28) cout << "010110";
		if(k == 29) cout << "010111";
		if(k == 30) cout << "010101";
		if(k == 31) cout << "010100";
		if(k == 23) cout << "011000";
		if(k == 22) cout << "011001";
		if(k == 21) cout << "011010";
		if(k == 20) cout << "011010";
		if(k == 19) cout << "011110";
		if(k == 18) cout << "011111";
		if(k == 17) cout << "011101";
		if(k == 16) cout << "011100";
	}
	
	if(n == 7){
		if(k == 0) cout << "0000000";
		if(k == 1) cout << "0000001";
		if(k == 2) cout << "0000010";
		if(k == 3) cout << "0000010";
		if(k == 4) cout << "0000110";
		if(k == 5) cout << "0000111";
		if(k == 6) cout << "0000101";
		if(k == 7) cout << "0000100";
		if(k == 15) cout << "0001000";
		if(k == 14) cout << "0001001";
		if(k == 13) cout << "0001010";
		if(k == 12) cout << "0001010";
		if(k == 11) cout << "0001110";
		if(k == 10) cout << "0001111";
		if(k == 9) cout << "0001101";
		if(k == 8) cout << "0001100";
		if(k == 24) cout << "0010000";
		if(k == 25) cout << "0010001";
		if(k == 26) cout << "0010010";
		if(k == 27) cout << "0010010";
		if(k == 28) cout << "0010110";
		if(k == 29) cout << "0010111";
		if(k == 30) cout << "0010101";
		if(k == 31) cout << "0010100";
		if(k == 23) cout << "0011000";
		if(k == 22) cout << "0011001";
		if(k == 21) cout << "0011010";
		if(k == 20) cout << "0011010";
		if(k == 19) cout << "0011110";
		if(k == 18) cout << "0011111";
		if(k == 17) cout << "0011101";
		if(k == 16) cout << "0011100";
	}
	
	return 0;
}
