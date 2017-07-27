#include <stdio.h>
<<<<<<< HEAD

int main(int argc, char* argv[]){
	int n, m;
	int n1[10] = {0}, m1[10] = {0};
	double n2[10] = {0}, m2[10] = {0};
	scanf("%d", &n);
	printf("%d", n);
	for(int i = 0; i < n; i++){
		scanf("%d %f", &n1[i], &n2[i]);
	}
	scanf("%d", &m);
	printf("%d", m);
	for(int i = 0; i< m; i++){
		scanf("%d %f", &m1[i], &m2[i]);
	}
	for(int i = 0; i< 10; i++){
		printf("%d %f", n1[i], n2[i]);
		printf("%d %f", m1[i], m2[i]);
	}
	scanf("%d", &n);
	return 0;
}
=======
#include <iostream>
using namespace std;
int main(int argc, char * argv[]){
	int n, m; 
	int temp = 0;
	double n1[1001] = {0.0}, m1[1001] = {0.0};
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
	int count = 0;
	double result[1001] = {0.0};
	for(int i = 0; i < 1001; i++){
		result[i] = n1[i] + m1[i];
		if(result[i] != 0.0){
			count ++ ;
		}
	}
	printf("%d", count);
	for(int i = 1000; i >= 0; i--){
		if(result[i] != 0.0){
			printf(" %d %.1f", i,result[i]);
		}
	}
	return 0;
}
>>>>>>> f1aac265c02d3b56f0b4da2b8c89c052775257e4
