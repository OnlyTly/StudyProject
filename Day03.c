#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>

int main()
{
//-------------------------------------------------------------------------
	//�ȴ�С
	/*int a = 0;
	int b = 0;
	int c = 0;
	printf("������������������");
	scanf("%d %d %d", &a, &b, &c);
	if (a < b) {
		int temp = a;
		a = b;
		b = temp;
	}
	if (a < c) {
		int temp = a;
		a = c;
		c = temp;
	}
	if (b < c) {
		int temp = b;
		b = c;
		c = temp;
	}
	printf("�Ӵ�С��%d %d %d\n", a, b, c);*/
//----------------------------------------------------------------------------------------------
	//�����Լ����շת�ȽϷ���
	int m = 0;
	int n = 0;

	int r = 0;
	printf("������������������");
	scanf("%d %d", &m, &n);
	while (r=m%n)
	{
		m = n;
		n = r;
	}
	printf("%d\n",n);
	return 0;
}