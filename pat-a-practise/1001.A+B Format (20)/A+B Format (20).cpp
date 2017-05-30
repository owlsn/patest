#include <stdio.h>
int  main(int argc, char* argv[])
{
	int a, b;
	//输入a,b
	scanf("%d%d", &a, &b);
	//a存储和
	a += b;
	//a小于0,打印-号
	if(a < 0){
		printf("-");
		a = - a;
	}
	//分成3种情况
	//a>=1000000
	//a<1000000 && a >= 1000,
	//a<1000
	if(a >= 1000000){
		printf("%d,%03d,%03d", a/1000000, a%1000000/1000, a%1000);
	}
	else if(a >= 1000){
		printf("%d,%03d", a/1000, a%1000);
	}
	else{
		printf("%d", a);
	}
	return 0;
}