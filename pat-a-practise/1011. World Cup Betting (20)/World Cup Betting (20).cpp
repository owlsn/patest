#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
using namespace std;

int main(int argc, char * argv[]){
	double score[3][3] = {0}, rate[3] = {0};
	char str[3] = {'W', 'T', 'L'};
	for(int i = 0; i < 3; i ++){
		for(int j = 0; j < 3; j ++){
			cin >> score[i][j];
		}
	}
	for(int i = 0; i < 3; i ++){
		rate[i] = score[i][0];
		int index = 0;
		for(int j = 0; j < 3; j ++){
			if(score[i][j] > rate[i]){
				rate[i] = score[i][j];
				index = j;
			}
		}
		cout << str[index] << " ";
	}
	printf("%.2lf", (rate[0]*rate[1]*rate[2]*0.65 - 1) * 2);
	return 0;
}