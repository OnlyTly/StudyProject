//猜数字游戏
// 通过输入一个随机数和电脑生成的随机数比较，并且结束后可以选择是否接着玩
// 思路：
// 一、化繁为简
//		1.让电脑随机生成一个数
//		2.用户输入一个数
//		3.判断这个数的大小，大提醒偏大，小提醒偏小，相等，提醒相等
//		4.结束后，选择输入y/n,是否继续=>创建菜单，定义一个菜单函数menu
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void menu()
{
	printf("*************************************\n");
	printf("*************1.play ,0.exit*********\n");
	printf("*************************************\n");

}
void Gogame()
{
	printf("********欢迎来到猜数字游戏**********\n");
	int randnum = 0;
	int guess = 0;
	//满足一直变幻，使用时间戳来设置随机数的生成起始点
	//时间戳：当前计算机的时间-计算机的起始时间（1970.1.1.0:0:0）=(xxxx)秒
	//time函数：返回的是一个长整型的值
	//通过强转为int型即可
	srand( (unsigned int) time());
	//设置随机数 srand();函数	返回值是随机整型
	//生成随机数 rand();函数	返回值是随机整型 范围 -90 - 32767
	//生成在一个范围内的随机数
	randnum = rand()%100+1;//生成1-100

	while (1)
	{
		printf("请输入你猜的数字:");
		scanf("%d", &guess);
		if (guess>randnum)
		{
			printf("你猜的数字偏大了\n");
		}
		else if (guess<randnum)
		{
			printf("你猜的数字偏小了\n");
		}
		else {
			printf("恭喜你！猜对了！\n");
			break;
		}
	}
	
}


int main()
{
	int input = 0;
	do
	{
		menu();
		printf("请选择：");
		scanf("%d",&input);

		//选择指令，进入操作
		switch (input)
		{
		case 1:
			Gogame();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("请输入正确指令 1 或 0，谢谢\n");
			break;
		}
	} while (input);//只要有input值，循环就可以持续进行
	
	printf("程序继续");
	return 0;
}