#include <stdio.h>
int  main(int argc, char* argv[])
{
	int a, b;
	scanf("%d%d", &a, &b);
	a += b;
	if(a < 0){
		printf("-");
		a = - a;
	}
	if(a >= 1000000){
		printf("%d,%03d,%03d", a/1000000, a%1000000/1000, a%1000);
	}
	else if(a > 1000){
		printf("%d,%03d", a/1000, a%1000);
	}
	else{
		printf("%d", a);
	}
	return 0;
}