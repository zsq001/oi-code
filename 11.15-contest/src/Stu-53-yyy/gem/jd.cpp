#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<windows.h>
#include<time.h>
using namespace std;

int main(){
	for(int t=1;t<=100;t++){
		printf("test case #%d:\n",t);
		system("sp");
		system("gem>in1");
		system("gemII>in2");
		if(system("fc in1 in2")){
			printf("WA!!!");
			system("pause");
			break;
		}
		printf("same\n");
	}
}
