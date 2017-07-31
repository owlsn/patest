#include <iostream>
using namespace std;

int main(int argc, char * argv[]){
	int n, level = 0, pre = 0, up_cost = 6, down_cost = 4, stay = 5, cost = 0;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> level;
		if(level > pre){
			cost += up_cost * (level - pre);
		}
		else if(level < pre){
			cost += down_cost * (pre - level);
		}
		cost += stay;
		pre = level;
	}
	cout << cost;
	return 0;
}
