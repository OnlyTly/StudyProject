#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>

int main()
{
//-------------------------------------------------------------------------
	//比大小
	/*int a = 0;
	int b = 0;
	int c = 0;
	printf("请输入任意三个数：");
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
	printf("从大到小：%d %d %d\n", a, b, c);*/
//----------------------------------------------------------------------------------------------
	//求最大公约数（辗转比较法）
	int m = 0;
	int n = 0;

	int r = 0;
	printf("请输入任意两个数：");
	scanf("%d %d", &m, &n);
	while (r=m%n)
	{
		m = n;
		n = r;
	}
	printf("%d\n",n);
	return 0;
}