#include <iostream>
using namespace std;

int main(int argc, char * argv[]){
	int k = 0, n = 0, temp = 0, sum = -1, left = 0, right = 0, index = 0, flag = 0;
	int num[10001] = {0};
	cin >> k;
	for(int i = 0; i < k; i++){
		cin >> n;
		num[i] = n;
		if(n >= 0){
			flag = 1;
		}
		temp += n;
		if(temp < 0){
			index = i + 1;
			temp = 0;
		}
		else if(temp > sum){
			sum = temp;
			right = i;
			left = index;
		}
	}
	if(flag == 0){
		cout << 0 << ' ' << num[0] << ' ' << num[k - 1];
	}
	else{
		cout << sum << ' ' << num[left] << ' ' << num[right];
	}
	return 0;
}