#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define pf printf
//结构体
//结构是一些值的集合，这些值称为成员变量。结构的每个成员可以是不同的类型
//结构体成员的类型可以是标量，数组，指针，甚至是其他结构体

//结构体的声明
//struct tag { //struct 语句定义了一个包含多个成员的新的数据类型，
//member - list	//tag 是结构体标签，就是名字。
//member - list	// member-list 是标准的变量定义，成员变量
//member - list
//...
//} variable - list;//variable-list 是使用结构类型创建的结构变量，定义在结构的末尾，
//						最后一个分号之前，您可以指定一个或多个结构变量
//						

//在一般情况下，tag、member-list、variable-list 这 3 部分至少要出现 2 个

//结构类型的申明
//struct Person
//{
//	char name[20];
//	char sex[5];
//	int age;
//	int heigh;
//};
//struct Stu
//{
//	struct Person p;
//	char num[20];
//	char tele[20];
//};
////结构体变量的定义和初始化；
////1.可以在结构体声明的同时定义结构体变量（全局）
////2.直接在结构体外定义（全局）
////3.可以在main函数里定义（局部）
//int main()
//{
//	//结构体变量的初始化	
//	//初始化：定义变量的同时赋值
//	struct Person p1 = {"张三","男",20,183};
//	//嵌套结构体变量的初始化
//	struct Stu s = { {"李四","女",20,163},"201156986745","1562978456"};
//
//	//打印初始化过的变量
//	//结构体的访问：可以通过点操作符（.）访问 结构体变量.成员变量
//					//也可通过->操作符，一般配合指针
//	printf("%s %s %d %d\n", p1.name, p1.sex, p1.age, p1.heigh);
//	printf("%s %s %d %d %s %s\n",s.p.name, s.p.sex, s.p.age, s.p.heigh,s.num,s.tele);
//	return 0;
//}

//结构体传参
struct Person
{
	char name[20];
	char sex[5];
	int age;
	int heigh;
};
struct Stu
{
	struct Person p;
	char num[20];
	char tele[20];
};
void print2(struct Person *sp)//传结构体变量的地址
{
	pf("%s %s %d %d\n", sp->name, sp->sex, sp->age, sp->heigh);
}


void print1(struct Person p)//传结构体变量本身
{
	pf("%s %s %d %d\n", p.name, p.sex, p.age, p.heigh);
}
int main()
{
	
	struct Person p1 = {"张三","男",20,183};
	struct Stu s = { {"李四","女",20,163},"201156986745","1562978456"};
	printf("%s %s %d %d\n", p1.name, p1.sex, p1.age, p1.heigh);
	printf("%s %s %d %d %s %s\n",s.p.name, s.p.sex, s.p.age, s.p.heigh,s.num,s.tele);
	print1(p1);
	print2(&p1);
	//print1和print2哪个好？
	//首选print2
	//函数传参的时候，参数是需要压栈的
	//如果传递一个结构体对象的时候，结构体过大，参数压栈的系统开销比较大，所以会导致性能的下降
	//结论：结构体传参的时候，要传结构体的地址
	return 0;
}