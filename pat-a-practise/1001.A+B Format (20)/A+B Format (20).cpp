#include <stdio.h>
int  main(int argc, char* argv[])
{
	int a, b, str[10], i = 0;
	scanf("%d%d", &a, &b);
	//����a+b
	int sum = a + b;
	//��sum<0���ӡ����
	if(sum < 0){
		printf("-");
		sum = - sum;
	}
	//ÿ3λһ��
	int remain = sum;
	do{
		str[i] = remain % 1000;
		i++;
	}
	while(remain /= 1000);
	//��һ�鿪ͷ����Ҫ����,������ǰ����Ҫ��ӡ���ţ������ӡ
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
*/