#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define pf printf
//�ṹ��
//�ṹ��һЩֵ�ļ��ϣ���Щֵ��Ϊ��Ա�������ṹ��ÿ����Ա�����ǲ�ͬ������
//�ṹ���Ա�����Ϳ����Ǳ��������飬ָ�룬�����������ṹ��

//�ṹ�������
//struct tag { //struct ��䶨����һ�����������Ա���µ��������ͣ�
//member - list	//tag �ǽṹ���ǩ���������֡�
//member - list	// member-list �Ǳ�׼�ı������壬��Ա����
//member - list
//...
//} variable - list;//variable-list ��ʹ�ýṹ���ʹ����Ľṹ�����������ڽṹ��ĩβ��
//						���һ���ֺ�֮ǰ��������ָ��һ�������ṹ����
//						

//��һ������£�tag��member-list��variable-list �� 3 ��������Ҫ���� 2 ��

//�ṹ���͵�����
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
////�ṹ������Ķ���ͳ�ʼ����
////1.�����ڽṹ��������ͬʱ����ṹ�������ȫ�֣�
////2.ֱ���ڽṹ���ⶨ�壨ȫ�֣�
////3.������main�����ﶨ�壨�ֲ���
//int main()
//{
//	//�ṹ������ĳ�ʼ��	
//	//��ʼ�������������ͬʱ��ֵ
//	struct Person p1 = {"����","��",20,183};
//	//Ƕ�׽ṹ������ĳ�ʼ��
//	struct Stu s = { {"����","Ů",20,163},"201156986745","1562978456"};
//
//	//��ӡ��ʼ�����ı���
//	//�ṹ��ķ��ʣ�����ͨ�����������.������ �ṹ�����.��Ա����
//					//Ҳ��ͨ��->��������һ�����ָ��
//	printf("%s %s %d %d\n", p1.name, p1.sex, p1.age, p1.heigh);
//	printf("%s %s %d %d %s %s\n",s.p.name, s.p.sex, s.p.age, s.p.heigh,s.num,s.tele);
//	return 0;
//}

//�ṹ�崫��
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
void print2(struct Person *sp)//���ṹ������ĵ�ַ
{
	pf("%s %s %d %d\n", sp->name, sp->sex, sp->age, sp->heigh);
}


void print1(struct Person p)//���ṹ���������
{
	pf("%s %s %d %d\n", p.name, p.sex, p.age, p.heigh);
}
int main()
{
	
	struct Person p1 = {"����","��",20,183};
	struct Stu s = { {"����","Ů",20,163},"201156986745","1562978456"};
	printf("%s %s %d %d\n", p1.name, p1.sex, p1.age, p1.heigh);
	printf("%s %s %d %d %s %s\n",s.p.name, s.p.sex, s.p.age, s.p.heigh,s.num,s.tele);
	print1(p1);
	print2(&p1);
	//print1��print2�ĸ��ã�
	//��ѡprint2
	//�������ε�ʱ�򣬲�������Ҫѹջ��
	//�������һ���ṹ������ʱ�򣬽ṹ����󣬲���ѹջ��ϵͳ�����Ƚϴ����Իᵼ�����ܵ��½�
	//���ۣ��ṹ�崫�ε�ʱ��Ҫ���ṹ��ĵ�ַ
	return 0;
}