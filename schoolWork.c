#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//定义一个结构类型包含一名学生的 3 门学科成绩和个人平均成绩，
//要求输入某位学生的三门课程成绩，
//并计算其平均成绩。
//(1)请用普通的结构变量实现；
//(2)请用结构指针实现。

// struct Stu
//{
//	int course1;
//	int course2;
//	int course3;
//	int average;
//};
////int Ave(struct Stu* s) 
////{
////	return (s->course1+ s->course2+s->course3)/3;
////}
//int main()
//{
//
//	struct Stu s;
//	printf("请输入学科一的成绩：");
//	scanf("%d", &s.course1);
//	printf("请输入学科二的成绩：");
//	scanf("%d", &s.course2);
//	printf("请输入学科三的成绩：");
//	scanf("%d", &s.course3);
//
//	//s.average = Ave(&s);
//
//	s.average = (s.course1 + s.course2 + s.course3) / 3;
//
//	/*printf("该学生的学科一成绩：%d\n", s.course1);
//	printf("该学生的学科二成绩：%d\n", s.course2);
//	printf("该学生的学科三成绩：%d\n", s.course3);*/
//	printf("该学生的平均成绩：%d\n", s.average);
//	return 0;
//}

//void main()
//
//{
//    int  a = 1, b = 2, * p1, * p2, * pt;
//
//    p1 = &a;    p2 = &b;
//
//    
//    printf("a = %d, b = %d \n", a, b);
//    printf("p1地址：%d, p2地址：%d\n", p1, p2);
//    printf("*p1=%d, *p2=%d\n", *p1, *p2);
//
//    pt = p1;
//    p1 = p2;
//    p2 = pt;
//
//    printf("a = %d, b = %d \n", a, b);
//    printf("p1地址：%d, p2地址：%d\n", p1, p2);
//    printf("*p1=%d, *p2=%d\n", *p1, *p2);
//
//
//}

//输入一个整数n（不超过10位数），将它的各位数字重新组合，输出其中的最大值。如输入3427，则输出7432.
//int main()
//{
//	int m,i = 0;
//	long arr[10];
//	printf("请输入一个整数：");
//	scanf("%d", &m);
//	while (m>0)
//	{
//		arr[i] = m % 10;
//		i++;
//		m = m / 10;
//	}
//	/*for (int k = 0; k <i ; k++)
//	{
//		printf("%d ", arr[k]);
//	}
//	printf("\n");*/
//
//	for (int k = 0; k < i; k++)
//	{
//		for (int j = 0; j < i ; j++)
//		{
//			if (arr[j] < arr[j + 1]) {
//				int temp = arr[j+1];
//				arr[j + 1] = arr[j];
//				arr[j] = temp;
//			}
//		}
//
//	}
//	printf("\n");
//	printf("其重组的最大值为：");
//	for (int k = 0; k <i; k++)
//	{
//		printf("%d", arr[k]);
//	}
//}


//杨辉三角 10行
//int main()
//{
//	int arr[10][10];
//	int end = 10;
//	for (int i = 0; i < end; i++)
//	{
//		arr[i][0] = 1;
//		arr[i][i] = 1;
//	}
//	for (int i = 2; i < end; i++)
//	{
//		for (int j = 1; j < i; j++)
//		{
//			arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
//		}
//	}
//
//
//	for (int i = 0; i < end; i++)
//	{
//		for (int j = 0; j <= i; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//
//}
//struct point {
//	float x, y;
//};
//
//int main() {
//	int  i, num = 0;
//	struct point p[5];
//	//定义结构体数组
//	printf("Input 5 points: ");
//	for (i = 0; i<5;i++)
//	scanf("%f,%f", &p[i].x, &p[i].y);//输入5个点的坐标
//
//	for (i = 0; i<5;i++)
//		if(p[i].x *p[i].x<9 && p[i].y * p[i].y<9)
//		num++;
//	printf(" num= %d ", num);
//}

//假设有两个按元素值递增次序排列的单链表，
// 请编程实现将这两个单链表合并为一个按元素值递减次序排列的单链表，
//并要求利用原来两个单链表的结点存放合并后的单链表。
/*
typedef struct node 
{
	int data;//数据域
	struct node* next;
}node,*LinkList;
//通常用linklist说明指针变量，强调它是某个单链表的头指针变量，定义为linklist L,L表示头指针。
//node用来定义单链表中结点的指针，例如node *p，p为结点的指针变量，p也可以定义为头结点。

//链表的初始化
node* startlist(node*L) {
	//初始化单链表 并设置为空表
	L = (node*)malloc(sizeof(node));
	L->next = NULL;//使头结点的指针域为空，建立一个空的单链表 
	return L;
}//在方法体内为头结点分配内存空间的时候要注意，必须要返回指针

 //头插法建立单链表
void creatfromhead(node* L) {//利用头插法建立单链表 
	node* p;//新建一个结点指针 
	int i = 1;
	int j;
	while (i != 0) {
		scanf("%d", &j);
		if (j != -1) {
			p = (node*)malloc(sizeof(node));//新建一个结点
			p->data = j;//把输入的值赋值给新结点的指针域
			p->next = L->next;//把新结点插入到表头 
			L->next = p;//头结点要始终放在最前面 
		}
		else
		{
			i = 0;//如果输入-1则结束单链表的输入	
		}
	}
}
//
void creatfromtail(node* l) {//利用尾插法建立单链表
	node* p;//新建一个结点指针
	node* r;//再建立一个尾指针
	int i = 1;
	int j;
	r = l;//很重要的一步，令尾指针r指向头结点l,便于做尾插入 
	while (i != 0) {
		scanf("%d", &j);
		if (j != -1) {
			p = (node*)malloc(sizeof(node));//建立一个新结点
			p->data = j;
			r->next = p;//尾指针的指针域指向新结点p
			r = p;//再让尾指针放在p后面，尾指针永远在最后 

		}
		else
		{
			i = 0;//输入-1则结束 
			r->next = NULL;//尾指针的指针域设置为空，表示链表的结束 
		}
	}
}

//单链表打印 
void print(node* L) {//对单链表进行打印
	if (L->next == NULL)
	printf("该链表为空");

	printf("该链表的内容为：");
	while (L->next != NULL) {
		printf("%d ", L->next->data);
		L = L->next;
	}
	printf("\n");
}

//
void Merge(LinkList A, LinkList B) {
	node* pa = A->next, * pb = B->next;	//pa.pb分别为A,B的工作指针 
	A->next = NULL;//A作为结果链表的头指针,先将结果链表初始化为空 
	node* ra, * rb;//ra,rb暂存pa的后继结点指针,以防断链 
	while (pa != NULL && pb != NULL) {
		if (pa->data < pb->data) {
			ra = pa->next;
			pa->next = A->next;//头插法插入较小的数 
			A->next = pa;
			pa = ra;
		}
		else {
			rb = pb->next;
			pb->next = A->next;
			A->next = pb;
			pb = rb;
		}
	}
	while (pa != NULL) {//头插法插入A表剩下的数 
		ra = pa->next;
		pa->next = A->next;
		A->next = pa;
		pa = ra;
	}
	while (pb != NULL) {//头插法插入B表剩下的数 
		rb = pb->next;
		pb->next = A->next;
		A->next = pb;
		pb = rb;
	}
	free(B);
}
int main() {
	node* l, * m ,*LA,*LB;
	LA = startlist(&l);
	
	LB = startlist(&m);
	printf("单链表已初始化\n");
	printf("递增链表LA：\n");
	//creatfromhead(l);
	creatfromtail(LA);
	print(LA);
	printf("递增链表LB：\n");
	//creatfromhead(m);
	creatfromtail(LB);
	print(LB);
	printf("两个单链合并递减排序：\n");
	Merge(LA,LB);
	print(LA);
	return 0;
}

*/


//编写程序，将十进制数N转换为d进制数。
//1.定义一个栈，用于存储二进制数的每一位。
//2.对于输入的十进制数N，不断进行除2操作，将余数压入栈中，直到商为0。
//3.从栈顶开始依次弹出每一位二进制数，输出即可得到从低位到高位的二进制数。
/*

#define MAX_SIZE 100

typedef struct {
	int data[MAX_SIZE];
	int top;
} Stack;

void init(Stack* s) {
	s->top = -1;
}

int isEmpty(Stack* s) {
	return s->top == -1;
}

int isFull(Stack* s) {
	return s->top == MAX_SIZE - 1;
}

int push(Stack* s, int x) {
	if (isFull(s)) {
		printf("Stack is full.\n");
		return 0;
	}
	s->data[++s->top] = x;
}

int pop(Stack* s) {
	if (isEmpty(s)) {
		printf("Stack is empty.\n");
		return -1;
	}
	return s->data[s->top--];
}

int decimalToBinary(int n,int x) {
	Stack s;
	init(&s);
	while (n != 0) {
		push(&s, n % x);
		n /= x;
	}
	printf("从低位到高位输出的结果为: ");
	while (!isEmpty(&s)) {
		printf("%d", pop(&s));
	}
	printf("\n");
}

void Print(Stack *s) {

	printf("从低位到高位输出的结果为: ");
	while (!isEmpty(&s)) {
		printf("%d", pop(&s));
	}
}

int main() {
	int n,x;
	printf("请输入一个数字:\n");
	scanf("%d", &n);
	printf("请选择需要转换的进制：1.二进制；2.八进制；3.十六进制；\n");
	scanf("%d", &x);
		switch (x)
		{
		case 1:
			x = 2;
			decimalToBinary(n, x);
			break;
		case 2:
			x = 8;
			decimalToBinary(n, x);
			break;
		case 3:
			x = 16;
			decimalToBinary(n, x);
			break;
		default:
			printf("非法输入\n");
			break;
		}
			
	return 0;
}
*/

//杨辉三角
/*
#define MAXSIZE 100

typedef struct {
	int data[MAXSIZE];
	int front, rear;
} Queue;

void InitQueue(Queue* q) {
	q->front = q->rear = 0;
}

int QueueEmpty(Queue* q) {
	return q->front == q->rear;
}

void EnQueue(Queue* q, int x) {
	q->data[q->rear] = x;
	q->rear = (q->rear + 1) % MAXSIZE;
}

int DeQueue(Queue* q) {
	int x = q->data[q->front];
	q->front = (q->front + 1) % MAXSIZE;
	return x;
}

int GetHead(Queue* q) {
	return q->data[q->front];
}

int main() {
	Queue q;
	InitQueue(&q);
	int a[MAXSIZE][MAXSIZE] = { 0 };
	int n = 10;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i) {
				a[i][j] = 1;
			}
			else {
				a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
			}
			EnQueue(&q, a[i][j]);
		}
		while (!QueueEmpty(&q)) {
			printf("%d ", DeQueue(&q));
		}
		printf("\n");
	}
	return 0;
}
*/

//队列
/*
#define MAX_SIZE 10
int queue[MAX_SIZE];
int front = 0, rear = 0;

//入队
void enqueue(int data) {
    if ((rear + 1) % MAX_SIZE == front) {
        printf("Queue is full!\n");
        return;
    }
    queue[rear] = data;
    rear = (rear + 1) % MAX_SIZE;
}

//出队
int dequeue() {
    if (front == rear) {
        printf("Queue is empty!\n");
        return -1;
    }
    int data = queue[front];
    front = (front + 1) % MAX_SIZE;
    return data;
}

//获取杨辉三角第n行第m个数的值
int get_num(int n, int m) {
    if (m == 0 || m == n) {
        return 1;
    } else {
        int a = dequeue();
        int b = get_num(n, m - 1);
        int c = get_num(n - 1, m - 1);
        int result = b + c;
        enqueue(a);
        enqueue(result);
        return result;
    }
}

int main() {
    int i, j;
    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j <= i; j++) {
            enqueue(get_num(i, j));
        }
        for (j = 0; j < MAX_SIZE - i - 1; j++) {
            printf(" ");
        }
        for (j = 0; j <= i; j++) {
            printf("%d ", dequeue());
        }
        printf("\n");
        front = rear = 0;
    }
    return 0;
}
*/

//串操作
/*
#define MAXSIZE 50

typedef struct {
	char ch[MAXSIZE];
	int len;
}SString;
// 初始化
SString* init_string()
{
	SString* s;
	s = (SString*)malloc(sizeof(SString));
	if (s != NULL) {
		s->len = 0;
	}
	return s;
}
// 判串长
int StrNum(SString* S) {
	return S->len;
}
// 判空串
int StrEmpty(SString* S) {
	if (S->len == 0) {
		return 1;
	}
	return 0;
}
// 输入赋值
void StrAssignGet(SString* S) {
	printf("请输入一段字符串，按回车结束：\n");
	gets(S->ch);
	int i = 0, j = 0;
	while (S->ch[i] != '\0') {
		i++;
		j++;
	}
	S->len = j;
}
// 串赋值
void StrAss(SString *S,char T[]) {
	int i;
	for ( i = 0; T[i] != '\0'; i++)
	{
		S->ch[i] = T[i];
	}
	S->len = i;
}
// 串连接
void StrCat(SString* S, SString* T) {
	int i;
	if ((S->len + T->len) <= MAXSIZE) {
		for (i = 0; i < T->len; i++) {
			S->ch[S->len + i] = T->ch[i];
		}
		S->len += T->len;
	}
}
// 串比较
int StrCopmare(SString* S, SString* T) {
	int i;
	for (i = 0; i <= S->len&&i<=T->len; i++) {
	if (S->ch[i] != T->ch[i]) {
		return S->ch[i]-T->ch[i];
		}
		return S->len-T->len;
	}

}
// 串插入
void StrInsert(SString* S, int pos, SString* T) {
	int i;
	if (pos<1 || pos>S->len+1) {
		printf("插入位置不合法\n");
		return 0;
	}
	if (S->len + T->len > MAXSIZE) {
		printf("插入后长度超过了最大长度\n");
		return 0;
	}
	for (i = S->len + T->len; i >= T->len + pos; i--) {
		S->ch[i] = S->ch[i - T->len];
	}
	for (i = 0; i < T->len; i++) {
		S->ch[i + pos] = T->ch[i];
	}
	S->len = S->len + T->len;
	
}
// 取子串
void StrGet(SString *S,SString *T, int pos, int len) {
	int i,j = 0;
	if (pos<1 || pos>T->len || len<1 || pos + len>T->len + 1) {
		printf("子串位置或长度不合法\n");
	}
	else {
		for (i = 0; i < len; i++) {
			S->ch[i] = T->ch[pos - 1 + i];
		}
		S->len = len;
	}
}
// 子串删除
int StrDel(SString* S, int i, int j) {
	int k;
	if (i + j - 1 > S->len) {
		printf("所要删除的子串越界!");
		return 0;
	}
	else {
		for (k = i + j - 1; k < S->len; k++, i++) {
			S->ch[i - 1] = S->ch[k];
		}
		S->len = S->len - j;
		S->ch[S->len] = '\0';
		return 1;
	}
}
// 简单模式匹配
int Index(SString *s, SString *t, int pos)
{
	int i = pos, j = 1;
	while (i <= s->len && j <= t->len) {
		if (s->ch[i - 1] == t->ch[j - 1]) {
			i++;
			j++;
		}
		else {
			i = i - j + 2;
			j = 1;
		}
	}
	if (j > t->len) {
		return i - t->len;
	}
	else {
		return 0;
	}
}
// 打印字符串
void printSString(SString *str)
{
	int i;
	for (i = 0; i <= str->len; i++)
		printf("%c", str->ch[i]);
	printf("\n");
}

int main() {
	
	//串初始化，输入赋值，串赋值
	SString *S1,*T1;
	S1 = init_string();
	StrAssignGet(S1);
	printf("输入赋值操作字符串:");
	printSString(S1);
//---------------------------------------------
	T1= init_string();
	char T[] = "Hello,World!";
	StrAss(T1, T);
	printf("串赋值操作字符串:");
	printSString(T1);
	printf("\n---------------------------------------------------\n");
	
	//判空和求串长
	SString* K;
	K = init_string();
	//判断串是否为空
	printf("串S是否为空:%d\n", StrEmpty(S1));
	printf("串T是否为空:%d\n", StrEmpty(K));
	//获取串的长度
	printf("串S的长度:%d\n", StrNum(S1));
	printf("串T的长度:%d\n", StrNum(K));
	printf("\n---------------------------------------------------\n");
	
	//串连接
	
	SString* S2,*T2;
	S2 = init_string();
	StrAssignGet(S2);
	printf("字符串一:");
	printSString(S2);
	T2 = init_string();
	StrAssignGet(T2);
	printf("字符串二:");
	printSString(T2);
	StrCat(S2, T2);
	printf("字符串连接:");
	printSString(S2);

	printf("\n---------------------------------------------------\n");
	
	//串比较
	
	SString* S3, * T3;
	S3 = init_string();
	StrAssignGet(S3);
	printf("字符串一:");
	printSString(S3);
	T3 = init_string();
	StrAssignGet(T3);
	printf("字符串二:");
	printSString(T3);
	int flag1 = StrCopmare(S3,T3);
	if (flag1==0)
	{
		printf("字符串相同");
	}
	else if (flag1 >0)
	{
		printf("字符串不相同,且字符串一比字符串二长");
	}
	else if (flag1 <0)
	{
		printf("字符串不相同，且字符串一比字符串二短");
	}
	else
	{
		printf("字符串不相同");
	}
	
	printf("\n---------------------------------------------------\n");

	//串插入
	
	SString* S4, * T4;
	S4 = init_string();
	StrAssignGet(S4);
	printf("字符串一:");
	printSString(S4);
	T4 = init_string();
	StrAssignGet(T4);
	printf("字符串二:");
	printSString(T4);
	StrInsert(S4, 2, T4);
	printf("插入字符串后");
	printSString(S4);
	printf("\n---------------------------------------------------\n");
	//取子串
	
	SString* S5,*T5;
	T5 = init_string();
	StrAssignGet(T5);
	printf("母串:");
	printSString(T5);
	S5 = init_string();
	StrGet(S5,T5,2,3);
	printf("子串:");
	printSString(S5);
	printf("\n---------------------------------------------------\n");
	//删子串
	
	SString* S6, * T6;
	T6 = init_string();
	StrAssignGet(T6);
	printf("母串:");
	printSString(T5);
	S6 = init_string();
	StrGet(S6, T6, 2, 3);
	printf("子串:");
	printSString(S6);
	int flag = StrDel(T6,2,3);
	if (flag == 1) {
		printf("字串删除成功，新母串为:");
		printSString(T6);
	}else if(flag==0){
		printf("字串删除失败");
	}
	

	SString *S7,*T7;
	int k;
	T7 = init_string();
	StrAssignGet(T7);
	printf("字符串一:");
	printSString(T7);
	S7 = init_string();
	StrGet(S7,T7,2,3);
	printf("字符串二:");
	printSString(S7);
	k = Index(T7, S7, 1);
	printf("第一次出现的位置是%d",k);
}
*/

/*
#include <string.h>

#define MAXSIZE 50

typedef struct {
	char ch[MAXSIZE];
	int len;
}SString;

SString* init_string()
{
	SString* s;
	s = (SString*)malloc(sizeof(SString));
	if (s != NULL) {
		s->len = 0;
	}
	return s;
}

void StrAss(SString* S, char T[]) {
	int i;
	for (i = 0; T[i] != '\0'; i++)
	{
		S->ch[i] = T[i];
	}
	S->len = i;
}

void getNewstring(SString* S, SString* T, char R[],int r[]) {
	int i, j, flag;
	int k = 0;
	for ( i = 0; i < S->len; i++)
	{
		flag = 1;
		for ( j = 0; j < T->len; j++)
		{
			if (S->ch[i]==T->ch[j])
			{
				flag = 0;
				break;
			}
		}
		if (flag)
		{
			R[k] = S->ch[i];
			r[k] = i;
			k++;
		}
	}
	R[k] = '\0';
}

void printSString(SString* str)
{
	int i;
	for (i = 0; i <str->len; i++)
		printf("%c", str->ch[i]);
	printf("\n");
}

int main() {
	SString *S,*T,*R;
	char s[] = "Hello,world!";
	char t[] = "l";
	int  r[MAXSIZE];
	char R1[MAXSIZE];

	S = init_string();
	StrAss(S, s);
	printSString(S);
	T = init_string();
	StrAss(T, t);
	printSString(T);

	R = init_string();
	getNewstring(S, T, R1, r);
	StrAss(R, R1);
	printf("新串R为:\n");
	printSString(R);
	printf("新串R中每个字符在串S中第一次出现的位置为：\n");
	for (int i = 0; i < R->len; i++) {
		printf("%c:%d |", R->ch[i], r[i]);
	}
	return 0;
}
*/


//下三角(一维数组)
/*
#define MAX_SIZE 100

typedef struct {
	int data[MAX_SIZE];//存储非零数
	int n;//矩阵的阶数
}LowSJ;

//初始化矩阵
void initLowSJ(LowSJ* L, int n) {
	L->n = n;
	int i = 0;
	for ( i = 0; i < n*(n+1)/2; i++)
	{
		L->data[i] = 0;
	}
}
//设置非零元素
void setLowSJ(LowSJ *L,int row,int col,int value) {
	if (row>=col) {
		int index = row * (row - 1) / 2 + col - 1;
		L->data[index] = value;
	}
}



//获取下三角的元素
int getLowSJ(LowSJ *L,int row,int col) {
	if (row >= col) {
		int index = row * (row - 1) / 2 + col - 1;
		return L->data[index];
	}else {
		return 0;
	}
}
//输出
void printLowSJ(LowSJ *L) {
	int i, j;
	for (i = 1; i <= L->n; i++) {
		for (j = 1; j <= L->n; j++) {
			printf("%d ", getLowSJ(L, i, j));
		}
		printf("\n");
	}
}

int main() {
	LowSJ L;
	initLowSJ(&L,4);
	setLowSJ(&L, 1, 1, 1);
	setLowSJ(&L, 2, 1, 2);
	setLowSJ(&L, 2, 2, 3);
	setLowSJ(&L, 3, 1, 4);
	setLowSJ(&L, 3, 2, 5);
	setLowSJ(&L, 3, 3, 6);
	setLowSJ(&L, 4, 1, 7);
	setLowSJ(&L, 4, 2, 8);
	setLowSJ(&L, 4, 3, 9);
	setLowSJ(&L, 4, 4, 10);
	printLowSJ(&L);
}
*/

//稀疏矩阵
/*
#define MAXSIZE 100

typedef struct {
	int row, col;
	int e;
}Triple;

typedef struct {
	Triple data[MAXSIZE];
	int m, n, num;//行，列，非零元素个数
}TSMatrix;

//矩阵的递增转置法
void TransposeMatrix(TSMatrix A, TSMatrix* B) {
	int i, j, k;
	B->m = A.n;
	B->n = A.m;
	B->num = A.num;

	if (B->num>0) {
		j = 1;
		for ( k = 0; k <=A.n; k++)//每次寻找col = k时，进行转置，所以k的取值：1《= k《=A.n
		{
			for ( i = 0; i <= A.num; i++)
			{
				if (A.data[i].col==k)
				{
					B->data[j].row = A.data[i].col;
					B->data[j].col = A.data[i].row;
					B->data[j].e = A.data[i].e;
					j++;
				}
			}
		}
	}
}
//创建矩阵
void CreatMatrix(TSMatrix *A) {
	int i, j, k, row, col, e;
	printf("请输入矩阵的行数、列数和非零元素个数：\n");
	scanf("%d%d%d", &A->m, &A->n, &A->num);
	printf("请输入矩阵的三元组：\n");
	for (i = 1; i <= A->num; i++) {
		scanf("%d%d%d", &row, &col, &e);
		A->data[i].row = row;
		A->data[i].col = col;
		A->data[i].e = e;
	}
}
//打印矩阵
void PrintMatrix(TSMatrix A) {
	int i, j, k = 1;
	for (i = 1; i <= A.m; i++) {//矩阵从1开始
		for (j = 1; j <= A.n; j++) {
			if (A.data[k].row == i && A.data[k].col == j) {
				printf("%d\t", A.data[k].e);
				k++;
			}
			else {
				printf("0\t");
			}
		}
		printf("\n");
	}
}

int main() {
	TSMatrix A, B;
	CreatMatrix(&A);
	printf("原矩阵：\n");
	PrintMatrix(A);
	TransposeMatrix(A, &B);
	printf("转置矩阵：\n");
	PrintMatrix(B);
	return 0;
}
*/