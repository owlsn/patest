#include <stdio.h>
int  main(int argc, char* argv[])
{
	int a, b;
	//����a,b
	scanf("%d%d", &a, &b);
	//a�洢��
	a += b;
	//aС��0,��ӡ-��
	if(a < 0){
		printf("-");
		a = - a;
	}
	//�ֳ�3�����
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