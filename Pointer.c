#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//指针
//内存单元的编号称为地址（地址也叫指针）
//指针是内存中一个最小单元的编号
//平常说的指针，通常是指指针变量，用来存放地址的变量
//指针是用来存放地址的，地址是唯一标示一块地址空间的
//指针在32位平台是4个字节，在64位平台是8个字节
//x86：32位
//x64：64位
/*
int main()
{
	int a = 10;//a是整型变量，占用4个字节
	int* pa = &a;//&a:取地址，取得是首地址
	//pa是一个指针变量，用来存放地址的
	//本质上指针就是地址
	//指针变量就是一个变量，指针变量是用来存放地址的一个变量
	return 0;
}*/
//
//指针类型
//结论1：指针类型决定了指针在被解引用的时候访问了几个字节
//int*的指针，解引用访问了4个字节
//char*的指针，解引用访问了1个字节
//double*的指针，解引用访问了8个字节
//以此类推。。。
//结论2：指针类型决定了指针+-1操作的时候，跳过几个字节
//决定了指针的步长
/*
int main()
{
	int a = 10;
	int* pa = &a;
	char* pc = (char*)&a;

	printf("pa=%p\n", pa);
	printf("pa+1=%p\n", pa + 1);

	printf("pc=%p\n", pc);
	printf("pc+1=%p\n", pc + 1);
}*/

//野指针：指针指向的位置是不可知的（随机的，不正确的或没有明确限制的）
//野指针的成因：1.指针未初始化
//				2.指针访问越界
//				3.指针指向的空间释放

//int main()
//{
//	//1.
//	//int* p;
//	//p没有初始化，就意味着没有明确的指向
//	//一个局部变量没有初始化，放的就是随机值
//	//*p = 10;//此时非法访问内存了，*p就是野指针
//	
//	//2.
//	//int arr[10] = { 0 };
//	//int* p = arr;//==arr[0];
//	//for (int i = 0; i <=10; i++)
//	//{
//	//	*p = i;
//	//	p++;//当指针指向范围超过数组的范围时，p就是野指针
//	//}
//	return 0;
//}
//3.
/*
int test()
{
	int a = 10;//a是局部变量，使用过后地址空间就会销毁，回归系统
	return &a;
}
int main()
{
	int* p = test();//*p存放的是使用函数后a的地址，而a的地址使用后会销毁，
	//虽然*p仍然可以访问存放的地址，但无妨访问到a的值，也就成野指针

}*/

//如何避免使用野指针：1.指针初始化
//					  2.小心指针越界
//					  3.指针指向空间释放及时置NULL
//					  4.避免返回局部变量的地址
//					  5.指针使用之前检查有效性

// --------------------------------------------------------------
//指针+-整数
//案例：给任意长度数组赋值
//1.使用下标赋值
//int main()
//{
//	int arr[10] = { 0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (int i = 0; i < sz; i++)
//	{
//		arr[i] = 1;
//	}
//}
////2.使用指针赋值（1）
//int main()
//{
//	int arr[10] = { 0 };
//	int* p = arr;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (int i = 0; i < sz; i++)
//	{
//		*p = 1;
//		p++;
//		//可简写：*p++=1;
//	}
//}
//int main()
//{
//	int arr[10] = { 0 };
//	int* p = arr;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (int i = 0; i < sz; i++)
//	{
//		*(p + i) = 1;
//		//直接通过加下标值找到目标空间赋值
//		//+0就是arr[0]的地址 ;+1就是arr[1]的地址
//		//因为都是int型，指针+1等于跳过4个字节，就等于从arr[0]直接跨到arr[1];
//	}
//}

//-------------------------------
//指针-指针
//前提：指向同一块空间
//int main()
//{
//	int arr[10] = { 0 };
//	printf("%d\n",&arr[9] - &arr[0]);//?=9
//	//指针-指针：表示两个指针指向的内存位置之间相隔多少个元素
//}
//案例：计算字符串的长度
#include <string.h>
#include "Pointer.h"
//1.调用库函数
//2.自定义函数：1.循环统计
//				2.递归函数
//				3.指针-指针

//int my_strlen(char* str)
//{
//	/*int count = 0;
//	while (*str != '\0')
//	{
//		count++;
//		str++;
//	}
//	return count;*/
//
//	char* start = str;
//	while (*str != '\0')
//	{
//		str++;
//	}
//	return (str - start);
//}
//
//
//int main()
//{
//	int len = my_strlen("abcdef");
//	printf("%d\n", len);
//}

//数组：一组相同类型元素的集合
//指针：是一个存放地址的变量
//数组可以通过指针访问：*（指针+下标）;

//--------------------------------------------------------------------------
//二级指针变量：是存放一级指针变量的地址
//int main()
//{
//	int a = 10;
//	int* pa = &a;//pa是一个指针变量，一级指针变量
//	*pa = 20;
//	printf("&d\n", a);
//
//	int** ppa = &pa;//ppa也是一个指针变量，二级指针变量
//	//int*是说明ppa指向的对象是int*类型
//	**ppa = 20;
//	printf("&d\n", a);
//}

//-----------------------------------
//指针数组：存放指针的数组
/*
int main()
{
	int a = 10;
	int b = 20;
	int c = 30;
	int arr[10] = { 0 };//数组
	int* pa = &a;
	int* pb = &b;
	int* pc = &c;
	int* parr[10] = { &a,&b,&c };//指针数组
	//数据类型 * 数组名[] = {元素};
	for (int i = 0; i < 3; i++)
	{
		printf("%d\n", *(parr[i]));
	}	
}*/
//指针进阶
// 

/*
//字符指针	char*
int main ()
{
	char ch = 'w';
	char* pc = &ch;
	*pc = 'b';
	printf("%c\n", ch); //ch = 'b';
	//关于const
	//Const int* p = &i:  const在前，表示不能通过指针去修改变变量
	//Int* const p = &i : const在后，表示p这个指针不能再保存别的地址值
	char* p = "abcdef";//将‘a’的地址赋给p
	//字符串放在表达式中，使用的是字符串首字符的地址
	printf("%s\n", p); 
	return 0;
}


int main()
{
	const char* p1 = "abcdef";
	const char* p2 = "abcdef";
	//字符串"abcdef"是一个常量字符串，所以p1p2都指向同一个地址

	char arr1[] = "abcdef";
	char arr2[] = "abcdef";
	//创建数组时会开辟对应的独立空间，数组名指的是首元素的地址，

	if (p1 == p2)
	{	
		printf("p1 = p2");
	}
	else
	{
		printf("p1 != p2");
	}
	if (arr1 == arr2)
	{
		printf("arr1 = arr2");
	}
	else
	{
		printf("arr1 != arr2");
	}

}*/

//数组指针：存放数组的地址
//
//int *p[10]		指针数组：存放指针的数组
//int (*p)[10]		数组指针：指向数组的指针
//解释：p 和 * 结合，说明怕是一个指针变量，然后指向一个大小为10的整型数组。p的类型是int(*)[10];
//注意：[]的优先级该与*，所以要用( ),来保证p 先和 * 结合

//数组指针的使用
/*
int main()
{
	int arr[] = { 1,3,4,5,6,7,8,9,4,1,5 };
	int(*p)[12] = &arr;
	int sz = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < sz; i++)
	{
		printf("%d\n", *(*p+i));

		//p是指向数组，*p进行解引用相当于数组名，数组名又是数组首元素的地址
		//此处*p本质上就是指数组首元素的地址
		//*p+i：就是数组个元素所在的地址，
		//*（*p+i）：对地址进行解引用获得各元素的下标
		//但是，这种写法冗长且愚蠢
	}

}*/
//一般正常的写法，但数组指针多用于多维数组
/*
int main()
{
	int arr[] = { 1,3,4,5,6,7,8,9,4,1,5 };
	int* p = arr;
	int sz = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", *(p + i));
	}
}
*/

/*
 //传参是数组
void print(int arr[3][5], int r, int c) 
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
}

void print1(int (*p)[5],int r,int c)
{
	//二位数组的首元素是第一个数组，也就是第一行数组
	//传参是arr，传的是首元素的地址，也就是一个一维数组的地址，所以形参的数组指针指向的是一个一维数组
	//所以，形参可以写为 int (*p)[5],一个指向5个元素的一维整型数组的指针
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			//printf("%d ", *(*(p+i)+j));
			//*（p+i）：一维数组的地址进行解引用，找到一维数组
			//*（r+j）：找到一维数组了，+j 进行移位，再解引用得到元素的值
			printf("%d ", p[i][j]);
			//二者同理
		}
		printf("\n");
	}
}


int main()
{
	int arr[3][5] = { 1,3,4,5,6,7,8,9,4,1,5,5,6,7,8};
	//arr表示二维数组中第一行的地址，也就是首个数组元素的地址，是一个一维数组的地址
	//此处，首个一维数组是一个整型，大小为5的数组 假设它为 int data[5] ={...};
	//int *p = data 不就是指向它的指针
	print(arr,3,5);
	print1(arr, 3, 5);
	
	//int sz = sizeof(arr) / sizeof(arr[0]);
}
*/

//函数指针：指向函数的指针
/*
int test(int x, int y) {
	return x + y;
}

int main()
{
	int arr[5] = { 0 };
	int(*p)[5] = &arr;//数组指针
	
	//&函数名：表示取函数的地址
	printf("%p\n", &test);
	printf("%p\n", test);
	//二者相等
	//对于函数来说，&函数名 和 函数名 都代表函数的地址

	//函数地址的存储
	int (*te)(int,int) = &test;
	//表示方式：返回类型 + 指针 + （参数类型）= &函数名
	//函数的解引用和普通整型指针相同，所以通过解引用函数指针，就能找到函数并使用

	int ret = (*te)(2, 3);
	//（*te）：解引用
	//（2，3）：传参数使用函数
	//int ret = te(2,3);
	// ps：函数指针可以不用解引用，直接使用，因此我们可以通过使用函数指针实现函数的嵌套
}
*/
/*
int test(const char* str)
{
	printf("test()\n");
}
int main()
{
	//函数指针的格式
	int (*pf)(const char*) = test;//&test和test效果等同
	(*pf)("abc");// == pf("abc");
}*/
//套路代码解读
/*
int main()
{
	//请解析下面代码的含义
	(* (  void(*)() ) 0 )( );
	//1.void(*)():表示一种函数指针类型
	//2.（void(*)()）：此处的最外层括号表示强制转换
	//3.而0是一个整数，又void(*)():表示一种函数指针类型，所以通过强制转换，就成了一个地址。
	//4.所以  (void(*)()) 0  就表示一个函数的地址
	//5.则(* (  void(*)() ) 0 )：就表示解引用函数指针，但调用函数没有参数，所以后一个()的传参是空的
	//总结：以上代码是一次函数调用，
			// 调用的是0作为地址处的函数
			//把0强制类型转换为：无参数，返回类型是void的函数的地址
			//调用0地址处的函数

	void(   * signal(int,  void(*)(int)  )   )(int);
	//以上代码是一次函数声明，
	// 声明的signal函数的参数类型是int和函数指针
	//该函数指针指向函数是：参数为int 返回值是void的函数
	//signal函数的返回类型是一个函数指针，该函数指针指向的函数是：参数为int 返回值是void的函数
}*/

//函数指针的用途
//用一个简单计算器案例
/*
void menu() {
	printf("******************************************\n");
	printf("**************1.Add  2.Sub****************\n");
	printf("**************3.Mul  4.Div****************\n");
	printf("**************0.退出   *******************\n");
	printf("******************************************\n");
}
int Add(int x, int y) {
	return x + y;
}
int Sub(int x, int y) {
	return x - y;
}
int Mul(int x, int y) {
	return x * y;
}
int Div(int x, int y) {
	return x / y;
}
//计算
void calc(int (*p)(int,int)) {
	int x = 0;
	int y = 0;
	int ret = 0;
	printf("请输入两个操作数：");
	scanf("%d%d", &x,&y);
	ret = p(x,y);
	printf("%d\n", ret);
}
int main() 
{
	int input = 0;
	do
	{
		menu();
		printf("请选择：");
		scanf("%d",&input);
		switch (input)
		{
		case 1:
			calc(Add);
			break;
		case 2:
			calc(Sub);
			break;
		case 3:
			calc(Mul);
			break;
		case 4:
			calc(Div);
			break;
		case 0:
			printf("退出\n");
			break;
		default:
			printf("选择错误");
			break;
		}

	} while (input);
	
	
	return 0;

}
*/

//函数指针数组
//把函数和指针放在数组中，其实就是函数指针数组
/*
int Add(int x, int y) {
	return x + y;
}
int Sub(int x, int y) {
	return x - y;
}
int Mul(int x, int y) {
	return x * y;
}
int Div(int x, int y) {
	return x / y;
}

int main()
{
	//函数指针
	int (*p)(int, int) = Add;

	//函数指针数组
	int(*arr[4])(int,int) = { Add,Sub,Mul,Div };

	for (int i = 0; i < 4; i++)
	{
		//函数指针数组调用：数组名[](参数，参数)；
			int ret = arr[i](8,4);
			printf("当下标为%d时，ret=%d\n", i, ret);
	}
	return 0;

}
*/


//回调函数：通过函数指针调用的函数
//将函数指针（地址）作为参数传递给另一个函数，当这个指针被用来调用其所指向的函数时，称为回调函数
//回调函数不是由该函数的实现方直接调用，而是在特定的事件或条件发生时由另外的一方调用的，用于对该事件或条件进行响应

