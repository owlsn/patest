#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main(int argc, char * argv[]){
	string a = "", b = "", temp = "", res = "";
	int tag = 0, radix = 0, result = 0, sum = 0;
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
			sum += pow(double(temp[i] - 48), double(l - i));
		}
		else if(temp[i] >= 57){
			sum += pow(double(temp[i] - 87), double(l - i - 1));
		}
	}
	int bit = 0, flag = 0;
	int len = res.length();
	int i = 0 , t = 0;
	do{
		t = 0;
		for(int j = 0; j < len; j ++){
			if(res[i] >= 48 && res[i] < 57){
				bit = res[i] - 48;
			}
			else if(temp[i] >= 57){
				bit = res[i] - 87;
			}
			if(bit >= i){
				break;
			}
			else{
				cout << "bit:" << bit << ";;sum:" << pow(double(bit), double(len - j));
				t += pow(double(bit), double(len - j));
			}
		}
		cout << "t:"<< t << endl;
		if(sum == t){
			cout << i;
			flag = 1;
			break;
		}
		i ++;
	}while( i <= 3);
	if(flag == 0){
		cout << "Impossible";
	}
	return 0;
}