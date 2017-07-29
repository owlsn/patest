#include <iostream>
#include <string>
#include <vector>
using namespace std;

string number[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int main(int argc, char * argv[]){
	string input;
	vector<int> result;
	int num[100] = {0};
	cin >> input;
	int m = 0, i = 0;
	int sum = 0;
	for(int i = 0; i < input.length(); i++){
		sum += int(input[i]) - 48;
	}
	do{
		result.push_back(sum % 10) ;
		sum = sum /10;
	}
	while(sum);
	for(vector<int>::iterator it = result.end() - 1; it - result.begin() >= 0; it --){
		cout << number[*it];
		if(it != result.begin()){
			cout << " "; 
		}
	}
	return 0;
}