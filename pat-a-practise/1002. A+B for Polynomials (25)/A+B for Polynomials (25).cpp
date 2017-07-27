#include <stdio.h>

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