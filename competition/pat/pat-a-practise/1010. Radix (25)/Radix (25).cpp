#include <iostream>
#include <string>
#include <math.h>
#include <map>
#include <algorithm>
using namespace std;

int main(int argc, char * argv[]){
  map<char, int> ctoi;
  for(char i = '0'; i <= '9'; i ++){
    ctoi[i] = i - 48;
  }
  for(char i = 'a'; i <= 'z'; i++){
    ctoi[i] = i - 87;
  }
  
  string a = "", b = "", temp = "", res = "";
  long long int tag = 0, radix = 0, sum = 0;
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
    sum += ctoi[temp[i]] * pow(double(radix), double(l - i - 1));
  }
  int flag = 0;
  int len = res.length();
  long long int max_dig = 0;
  double t = 0, pre = 0;
  for(int k = 0; k < len; k ++){
    if(ctoi[res[k]] > max_dig){
      max_dig = ctoi[res[k]];
    }
  }
  long long i = max_dig + 1;
  long long left = min(max_dig + 1, sum + 1), right = max(max_dig + 1, sum + 1);
  for(i = (left + right) / 2; left <= right; i = (left + right) / 2){
	t = 0;
	//cout << "i:" << i << ";left:" << left << ";right:" << right;
	for(int j = 0; j < len; j ++){
	  t += ctoi[res[j]] * pow(double(i), double(len - j - 1));
	}
	//cout << ";t:" << t << ";sum:" << sum << endl;
	if(sum == t){
		if(len == 1){
			i = max_dig + 1;
		}
		cout << i;
	    flag = 1;
	    break;
	}
	else if(sum < t){
		right = i - 1;
	}
	else if(sum > t){
		left = i + 1;
	}
	if(t == pre){
	  break;
	}
	pre = t;
  }
  
  if(flag == 0){
    cout << "Impossible";
  }
  return 0;
}