#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main(int argc, char * argv[]){
	string a = "", b = "", temp = "", res = "";
	long long int tag = 0, radix = 0, result = 0, sum = 0;
	cin >> a >> b;
	cin >> tag >> radix;
	if(tag == 1){
		temp = a;
		res = b;
	}
	else if(tag == 2){
		temp = b;
		res = a;
	}
	int l = temp.length();
	for(int i = 0; i < l; i++){
		if(temp[i] >= 48 && temp[i] < 57){
			sum += (temp[i] - 48) * pow(double(radix), double(l - i - 1));
		}
		else if(temp[i] >= 57){
			sum += (temp[i] - 87) * pow(double(radix), double(l - i -  1));
		}
	}
	long long int bit = 0, flag = 0;
	int len = res.length();
	long long int i = 1 , t = 0;
	do{
		t = 0;
		bit = 0;
		if(len == 1 && res[0] == '0'){
			if(sum == 0){
				cout << 1;			
			}
			break;
		}
		for(int j = 0; j < len; j ++){
			if(res[j] >= 48 && res[j] < 57){
				bit = res[j] - 48;
			}
			else if(res[j] >= 57){
				bit = res[j] - 87;
			}
			if(bit >= i){
				break;
			}
			else{
				t += bit * pow(double(i), double(len - j - 1));
			}
		}
		if(sum == t){
			cout << i;
			flag = 1;
			break;
		}
		i ++;
	}while( sum >= t);
	if(flag == 0){
		cout << "Impossible";
	}
	return 0;
}