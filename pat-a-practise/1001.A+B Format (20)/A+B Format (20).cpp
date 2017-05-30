#include <stdio.h>
int  main(int argc, char* argv[])
{
	int a, b, str[10], i = 0;
	scanf("%d%d", &a, &b);
	//计算a+b
	int sum = a + b;
	//若sum<0则打印负号
	if(sum < 0){
		printf("-");
		sum = - sum;
	}
	//每3位一组
	int remain = sum;
	do{
		str[i] = remain % 1000;
		i++;
	}
	while(remain /= 1000);
	//第一组开头不需要逗号,其他的前面需要打印逗号，逆序打印
	for(printf("%d", str[--i]); i; --i){
		printf(",%03d", str[i-1]);
	}
	return 0;
}

/*
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
*/