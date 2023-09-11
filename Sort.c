#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//冒泡排序

//写法一：只能排有序整型数组
/*
void sort(int arr[],int length)
{
	//趟数
	for (int i = 0; i < length-1; i++)
	{
		int flag = 1;//假设数组时已经排好序
		//一趟冒泡排序的过程
		for (int j = 0; j < length-1-i; j++)
		{
			if (arr[j]>arr[j+1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				flag = 0;
			}
		}
		if (flag == 1)
		{
			break;
		}
	}
}
int main()
{
	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
	int length = sizeof(arr) / sizeof(arr[0]);
	sort(arr, length);
	for (int i = 0; i < length; i++)
	{
		printf("%d ", arr[i]);
	}
}
*/

//写法二：使用qsort()函数
//qsort()：使用快速排序例程排序（任意类型的数据）
//用法：void qsort(void *base,size_t num,size_t width,int (*cmp)(const void *e1,const void *e2));
// //void*的指针无法进行解引用获取值,无法+-整数，它是一种泛型指针，可以接受任意类型的地址
//  qsort(void *base,		需排序的数据的起始位置
//			size_t num,		待排序的数据元素的个数
//			size_t width,	待排序的数据元素的大小（单位是字节）
//			int (*cmp)(const void *e1,const void *e2));	函数指针-比较函数 cmp指向比较函数的地址
//e1/e2 ：指向你要比较的两个元素的地址

//回调函数：通过函数指针调用的函数
//将函数指针（地址）作为参数传递给另一个函数，当这个指针被用来调用其所指向的函数时，称为回调函数
//回调函数不是由该函数的实现方直接调用，而是在特定的事件或条件发生时由另外的一方调用的，用于对该事件或条件进行响应

//  qsort(void *base,你要排序的数据的起始位置
//			size_t num,待排序的数据元素的个数
//			size_t width,待排序的数据元素的大小（单位是字节）
//			int (*cmp)(const void *e1,const void *e2));	函数指针-比较函数 cmp指向比较函数的地址
//e1/e2 ：指向你要比较的两个元素的地址

//比较两个整型元素
/*
int cmp_num(const void *e1,const void *e2)
{
	
	return (*(int*)e2 - *(int*)e1);
	//e1-e2:升序；e2-e1：降序
	//e1<e2,返回值是<0
	//e1=e2,返回值是=0
	//e1>e2,返回值是>0
}
int main()
{
	int arr[] = { 4,5,6,7,2,1,0,9,3,8 };
	int length = sizeof(arr) / sizeof(arr[0]);
	qsort(arr,length,sizeof(arr[0]),cmp_num);
	for (int i = 0; i < length; i++)
	{
		printf("%d ", arr[i]);
	}
}
*/

//qsort()的使用
//1.排序结构数据
/*
struct stu
{
	char name[20];
	int age;
};

//按照姓名（字符串）来比较排序
int cmp_stu_name(const void*e1,const void*e2)
{
	//strcmp是字符一对一对的比较
	return strcmp(((struct stu*)e1)->name, ((struct stu*)e2)->name);
}
//按照姓名（字符串）来比较排序
int cmp_stu_age(const void* e1, const void* e2)
{
	return (((struct stu*)e1)->age-((struct stu*)e2)->age);
}
void test()
{
	struct stu s[] = { {"zhangsan",16},{"lisi",30},{"wangwu",20} };
	int length = sizeof(s) / sizeof(s[0]);
	//qsort(s,length,sizeof(s[0]),cmp_stu_name);
	qsort(s,length,sizeof(s[0]),cmp_stu_age);
}
int main()
{
	test();
}
*/
//2.改造冒泡排序（模拟qsort()函数）
/*
//比较两个整型元素
int cmp_num(const void* e1, const void* e2)
{

	return (*(int*)e1 - *(int*)e2);
	//e1-e2:升序；e2-e1：降序
	//e1<e2,返回值是<0
	//e1=e2,返回值是=0
	//e1>e2,返回值是>0
}
//交换
void Swap(char*s1,char*s2,int width)
{
	//通过字节长度直接进行交换，避免临时空间的大小无法判断
	for (int i = 0; i < width; i++)
	{
		char temp = *s1;
		*s1 = *s2;
		*s2 = temp;
		s1++;
		s2++;
	}
}
//自定义的sort()，模拟库函数qsort();实现冒泡排序
void sort(void *base, int length,int width,int(*cmp)(const void* e1, const void* e2))
{
	//趟数
	for (int i = 0; i < length - 1; i++)
	{
		int flag = 1;//假设数组时已经排好序
		//一趟冒泡排序的过程
		for (int j = 0; j < length - 1 - i; j++)
		{
			if (cmp((char*)base + j * width, (char*)base + (j+1) * width)>0)//两个参数传的是待比较的两个元素的地址
			{
				//交换
				Swap((char*)base + j * width, (char*)base + (j+1) * width, width);
				flag = 0;//一旦交换了，则flag重新赋值为0；
			}
		}
		if (flag == 1)
		{
			break;
		}
	}
}

void test2()
{
	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
	int length = sizeof(arr) / sizeof(arr[0]);
	sort(arr, length, sizeof(arr[0]), cmp_num);
	for (int i = 0; i < length; i++)
	{
		printf("%d ", arr[i]);
	}
}
//同理可用于结构体
int main()
{
	test2();
}
*/