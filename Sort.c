#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//ð������

//д��һ��ֻ����������������
/*
void sort(int arr[],int length)
{
	//����
	for (int i = 0; i < length-1; i++)
	{
		int flag = 1;//��������ʱ�Ѿ��ź���
		//һ��ð������Ĺ���
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

//д������ʹ��qsort()����
//qsort()��ʹ�ÿ����������������������͵����ݣ�
//�÷���void qsort(void *base,size_t num,size_t width,int (*cmp)(const void *e1,const void *e2));
// //void*��ָ���޷����н����û�ȡֵ,�޷�+-����������һ�ַ���ָ�룬���Խ����������͵ĵ�ַ
//  qsort(void *base,		����������ݵ���ʼλ��
//			size_t num,		�����������Ԫ�صĸ���
//			size_t width,	�����������Ԫ�صĴ�С����λ���ֽڣ�
//			int (*cmp)(const void *e1,const void *e2));	����ָ��-�ȽϺ��� cmpָ��ȽϺ����ĵ�ַ
//e1/e2 ��ָ����Ҫ�Ƚϵ�����Ԫ�صĵ�ַ

//�ص�������ͨ������ָ����õĺ���
//������ָ�루��ַ����Ϊ�������ݸ���һ�������������ָ�뱻������������ָ��ĺ���ʱ����Ϊ�ص�����
//�ص����������ɸú�����ʵ�ַ�ֱ�ӵ��ã��������ض����¼�����������ʱ�������һ�����õģ����ڶԸ��¼�������������Ӧ

//  qsort(void *base,��Ҫ��������ݵ���ʼλ��
//			size_t num,�����������Ԫ�صĸ���
//			size_t width,�����������Ԫ�صĴ�С����λ���ֽڣ�
//			int (*cmp)(const void *e1,const void *e2));	����ָ��-�ȽϺ��� cmpָ��ȽϺ����ĵ�ַ
//e1/e2 ��ָ����Ҫ�Ƚϵ�����Ԫ�صĵ�ַ

//�Ƚ���������Ԫ��
/*
int cmp_num(const void *e1,const void *e2)
{
	
	return (*(int*)e2 - *(int*)e1);
	//e1-e2:����e2-e1������
	//e1<e2,����ֵ��<0
	//e1=e2,����ֵ��=0
	//e1>e2,����ֵ��>0
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

//qsort()��ʹ��
//1.����ṹ����
/*
struct stu
{
	char name[20];
	int age;
};

//�����������ַ��������Ƚ�����
int cmp_stu_name(const void*e1,const void*e2)
{
	//strcmp���ַ�һ��һ�ԵıȽ�
	return strcmp(((struct stu*)e1)->name, ((struct stu*)e2)->name);
}
//�����������ַ��������Ƚ�����
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
//2.����ð������ģ��qsort()������
/*
//�Ƚ���������Ԫ��
int cmp_num(const void* e1, const void* e2)
{

	return (*(int*)e1 - *(int*)e2);
	//e1-e2:����e2-e1������
	//e1<e2,����ֵ��<0
	//e1=e2,����ֵ��=0
	//e1>e2,����ֵ��>0
}
//����
void Swap(char*s1,char*s2,int width)
{
	//ͨ���ֽڳ���ֱ�ӽ��н�����������ʱ�ռ�Ĵ�С�޷��ж�
	for (int i = 0; i < width; i++)
	{
		char temp = *s1;
		*s1 = *s2;
		*s2 = temp;
		s1++;
		s2++;
	}
}
//�Զ����sort()��ģ��⺯��qsort();ʵ��ð������
void sort(void *base, int length,int width,int(*cmp)(const void* e1, const void* e2))
{
	//����
	for (int i = 0; i < length - 1; i++)
	{
		int flag = 1;//��������ʱ�Ѿ��ź���
		//һ��ð������Ĺ���
		for (int j = 0; j < length - 1 - i; j++)
		{
			if (cmp((char*)base + j * width, (char*)base + (j+1) * width)>0)//�������������Ǵ��Ƚϵ�����Ԫ�صĵ�ַ
			{
				//����
				Swap((char*)base + j * width, (char*)base + (j+1) * width, width);
				flag = 0;//һ�������ˣ���flag���¸�ֵΪ0��
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
//ͬ������ڽṹ��
int main()
{
	test2();
}
*/