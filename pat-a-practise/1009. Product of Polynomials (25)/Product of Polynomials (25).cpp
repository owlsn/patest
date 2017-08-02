#include <iostream>
<<<<<<< HEAD
using namespace std;

int main(int argc, char * argv[]){
        int n, m, temp = 0;
        double n1[1001] = {0}, m1[1001] = {0}, t[2002] = {0}, result[2002] = {0};
        cin >> n;
        for(int i = 0; i < n; i++){
                cin >> temp;
                cin >> n1[temp];
        }
        cin >> m;
        for(int i = 0; i < m; i++){
                cin >> temp;
                cin >> m1[temp];
        }
	
}
=======
#include <stdio.h>
using namespace std;

int main(int argc, char * argv[]){
	int n, m; 
	int temp = 0, nmax = 0, mmax = 0;
	double n1[1001] = {0}, m1[1001] = {0}, t[2002] = {0}, result[2002] = {0};
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> temp;
		if(i == 0){
			nmax = temp;
		}
		cin >> n1[temp];
	}
	cin >> m;
	for(int i = 0; i < m; i++){
		cin >> temp;
		if(i== 0){
			mmax = temp;
		}
		cin >> m1[temp];
	}
	for(int i = 0; i <= nmax; i++){
		for(int j = 0; j <= mmax; j++){
			t[i + j] = n1[i] * m1[j];
			result[i + j] += t[i + j];
		}
	}
	int count = 0;
	for(int i = 0; i <= nmax + mmax ; i ++ ){
		if(result[i] != 0){
			count ++ ;
		}
	}
	cout << count << ' ';
	for(int i = nmax + mmax; i >= 0; i--){
		if(result[i] != 0){
			cout << i << ' ';
			printf("%.1f", result[i]);
			if(-- count){
				cout << ' ';
			}
		}
	}
	return 0;
}
>>>>>>> 5f77180a230691026517dc4d03e7e0696ae58d90
