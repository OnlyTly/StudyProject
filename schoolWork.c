#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//����һ���ṹ���Ͱ���һ��ѧ���� 3 ��ѧ�Ƴɼ��͸���ƽ���ɼ���
//Ҫ������ĳλѧ�������ſγ̳ɼ���
//��������ƽ���ɼ���
//(1)������ͨ�Ľṹ����ʵ�֣�
//(2)���ýṹָ��ʵ�֡�

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
//	printf("������ѧ��һ�ĳɼ���");
//	scanf("%d", &s.course1);
//	printf("������ѧ�ƶ��ĳɼ���");
//	scanf("%d", &s.course2);
//	printf("������ѧ�����ĳɼ���");
//	scanf("%d", &s.course3);
//
//	//s.average = Ave(&s);
//
//	s.average = (s.course1 + s.course2 + s.course3) / 3;
//
//	/*printf("��ѧ����ѧ��һ�ɼ���%d\n", s.course1);
//	printf("��ѧ����ѧ�ƶ��ɼ���%d\n", s.course2);
//	printf("��ѧ����ѧ�����ɼ���%d\n", s.course3);*/
//	printf("��ѧ����ƽ���ɼ���%d\n", s.average);
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
//    printf("p1��ַ��%d, p2��ַ��%d\n", p1, p2);
//    printf("*p1=%d, *p2=%d\n", *p1, *p2);
//
//    pt = p1;
//    p1 = p2;
//    p2 = pt;
//
//    printf("a = %d, b = %d \n", a, b);
//    printf("p1��ַ��%d, p2��ַ��%d\n", p1, p2);
//    printf("*p1=%d, *p2=%d\n", *p1, *p2);
//
//
//}

//����һ������n��������10λ�����������ĸ�λ����������ϣ�������е����ֵ��������3427�������7432.
//int main()
//{
//	int m,i = 0;
//	long arr[10];
//	printf("������һ��������");
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
//	printf("����������ֵΪ��");
//	for (int k = 0; k <i; k++)
//	{
//		printf("%d", arr[k]);
//	}
//}


//������� 10��
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
//	//����ṹ������
//	printf("Input 5 points: ");
//	for (i = 0; i<5;i++)
//	scanf("%f,%f", &p[i].x, &p[i].y);//����5���������
//
//	for (i = 0; i<5;i++)
//		if(p[i].x *p[i].x<9 && p[i].y * p[i].y<9)
//		num++;
//	printf(" num= %d ", num);
//}

//������������Ԫ��ֵ�����������еĵ�����
// ����ʵ�ֽ�������������ϲ�Ϊһ����Ԫ��ֵ�ݼ��������еĵ�����
//��Ҫ������ԭ������������Ľ���źϲ���ĵ�����
/*
typedef struct node 
{
	int data;//������
	struct node* next;
}node,*LinkList;
//ͨ����linklist˵��ָ�������ǿ������ĳ���������ͷָ�����������Ϊlinklist L,L��ʾͷָ�롣
//node�������嵥�����н���ָ�룬����node *p��pΪ����ָ�������pҲ���Զ���Ϊͷ��㡣

//����ĳ�ʼ��
node* startlist(node*L) {
	//��ʼ�������� ������Ϊ�ձ�
	L = (node*)malloc(sizeof(node));
	L->next = NULL;//ʹͷ����ָ����Ϊ�գ�����һ���յĵ����� 
	return L;
}//�ڷ�������Ϊͷ�������ڴ�ռ��ʱ��Ҫע�⣬����Ҫ����ָ��

 //ͷ�巨����������
void creatfromhead(node* L) {//����ͷ�巨���������� 
	node* p;//�½�һ�����ָ�� 
	int i = 1;
	int j;
	while (i != 0) {
		scanf("%d", &j);
		if (j != -1) {
			p = (node*)malloc(sizeof(node));//�½�һ�����
			p->data = j;//�������ֵ��ֵ���½���ָ����
			p->next = L->next;//���½����뵽��ͷ 
			L->next = p;//ͷ���Ҫʼ�շ�����ǰ�� 
		}
		else
		{
			i = 0;//�������-1����������������	
		}
	}
}
//
void creatfromtail(node* l) {//����β�巨����������
	node* p;//�½�һ�����ָ��
	node* r;//�ٽ���һ��βָ��
	int i = 1;
	int j;
	r = l;//����Ҫ��һ������βָ��rָ��ͷ���l,������β���� 
	while (i != 0) {
		scanf("%d", &j);
		if (j != -1) {
			p = (node*)malloc(sizeof(node));//����һ���½��
			p->data = j;
			r->next = p;//βָ���ָ����ָ���½��p
			r = p;//����βָ�����p���棬βָ����Զ����� 

		}
		else
		{
			i = 0;//����-1����� 
			r->next = NULL;//βָ���ָ��������Ϊ�գ���ʾ����Ľ��� 
		}
	}
}

//�������ӡ 
void print(node* L) {//�Ե�������д�ӡ
	if (L->next == NULL)
	printf("������Ϊ��");

	printf("�����������Ϊ��");
	while (L->next != NULL) {
		printf("%d ", L->next->data);
		L = L->next;
	}
	printf("\n");
}

//
void Merge(LinkList A, LinkList B) {
	node* pa = A->next, * pb = B->next;	//pa.pb�ֱ�ΪA,B�Ĺ���ָ�� 
	A->next = NULL;//A��Ϊ��������ͷָ��,�Ƚ���������ʼ��Ϊ�� 
	node* ra, * rb;//ra,rb�ݴ�pa�ĺ�̽��ָ��,�Է����� 
	while (pa != NULL && pb != NULL) {
		if (pa->data < pb->data) {
			ra = pa->next;
			pa->next = A->next;//ͷ�巨�����С���� 
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
	while (pa != NULL) {//ͷ�巨����A��ʣ�µ��� 
		ra = pa->next;
		pa->next = A->next;
		A->next = pa;
		pa = ra;
	}
	while (pb != NULL) {//ͷ�巨����B��ʣ�µ��� 
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
	printf("�������ѳ�ʼ��\n");
	printf("��������LA��\n");
	//creatfromhead(l);
	creatfromtail(LA);
	print(LA);
	printf("��������LB��\n");
	//creatfromhead(m);
	creatfromtail(LB);
	print(LB);
	printf("���������ϲ��ݼ�����\n");
	Merge(LA,LB);
	print(LA);
	return 0;
}

*/


//��д���򣬽�ʮ������Nת��Ϊd��������
//1.����һ��ջ�����ڴ洢����������ÿһλ��
//2.���������ʮ������N�����Ͻ��г�2������������ѹ��ջ�У�ֱ����Ϊ0��
//3.��ջ����ʼ���ε���ÿһλ����������������ɵõ��ӵ�λ����λ�Ķ���������
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
	printf("�ӵ�λ����λ����Ľ��Ϊ: ");
	while (!isEmpty(&s)) {
		printf("%d", pop(&s));
	}
	printf("\n");
}

void Print(Stack *s) {

	printf("�ӵ�λ����λ����Ľ��Ϊ: ");
	while (!isEmpty(&s)) {
		printf("%d", pop(&s));
	}
}

int main() {
	int n,x;
	printf("������һ������:\n");
	scanf("%d", &n);
	printf("��ѡ����Ҫת���Ľ��ƣ�1.�����ƣ�2.�˽��ƣ�3.ʮ�����ƣ�\n");
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
			printf("�Ƿ�����\n");
			break;
		}
			
	return 0;
}
*/

//�������
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

//����
/*
#define MAX_SIZE 10
int queue[MAX_SIZE];
int front = 0, rear = 0;

//���
void enqueue(int data) {
    if ((rear + 1) % MAX_SIZE == front) {
        printf("Queue is full!\n");
        return;
    }
    queue[rear] = data;
    rear = (rear + 1) % MAX_SIZE;
}

//����
int dequeue() {
    if (front == rear) {
        printf("Queue is empty!\n");
        return -1;
    }
    int data = queue[front];
    front = (front + 1) % MAX_SIZE;
    return data;
}

//��ȡ������ǵ�n�е�m������ֵ
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

//������
/*
#define MAXSIZE 50

typedef struct {
	char ch[MAXSIZE];
	int len;
}SString;
// ��ʼ��
SString* init_string()
{
	SString* s;
	s = (SString*)malloc(sizeof(SString));
	if (s != NULL) {
		s->len = 0;
	}
	return s;
}
// �д���
int StrNum(SString* S) {
	return S->len;
}
// �пմ�
int StrEmpty(SString* S) {
	if (S->len == 0) {
		return 1;
	}
	return 0;
}
// ���븳ֵ
void StrAssignGet(SString* S) {
	printf("������һ���ַ��������س�������\n");
	gets(S->ch);
	int i = 0, j = 0;
	while (S->ch[i] != '\0') {
		i++;
		j++;
	}
	S->len = j;
}
// ����ֵ
void StrAss(SString *S,char T[]) {
	int i;
	for ( i = 0; T[i] != '\0'; i++)
	{
		S->ch[i] = T[i];
	}
	S->len = i;
}
// ������
void StrCat(SString* S, SString* T) {
	int i;
	if ((S->len + T->len) <= MAXSIZE) {
		for (i = 0; i < T->len; i++) {
			S->ch[S->len + i] = T->ch[i];
		}
		S->len += T->len;
	}
}
// ���Ƚ�
int StrCopmare(SString* S, SString* T) {
	int i;
	for (i = 0; i <= S->len&&i<=T->len; i++) {
	if (S->ch[i] != T->ch[i]) {
		return S->ch[i]-T->ch[i];
		}
		return S->len-T->len;
	}

}
// ������
void StrInsert(SString* S, int pos, SString* T) {
	int i;
	if (pos<1 || pos>S->len+1) {
		printf("����λ�ò��Ϸ�\n");
		return 0;
	}
	if (S->len + T->len > MAXSIZE) {
		printf("����󳤶ȳ�������󳤶�\n");
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
// ȡ�Ӵ�
void StrGet(SString *S,SString *T, int pos, int len) {
	int i,j = 0;
	if (pos<1 || pos>T->len || len<1 || pos + len>T->len + 1) {
		printf("�Ӵ�λ�û򳤶Ȳ��Ϸ�\n");
	}
	else {
		for (i = 0; i < len; i++) {
			S->ch[i] = T->ch[pos - 1 + i];
		}
		S->len = len;
	}
}
// �Ӵ�ɾ��
int StrDel(SString* S, int i, int j) {
	int k;
	if (i + j - 1 > S->len) {
		printf("��Ҫɾ�����Ӵ�Խ��!");
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
// ��ģʽƥ��
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
// ��ӡ�ַ���
void printSString(SString *str)
{
	int i;
	for (i = 0; i <= str->len; i++)
		printf("%c", str->ch[i]);
	printf("\n");
}

int main() {
	
	//����ʼ�������븳ֵ������ֵ
	SString *S1,*T1;
	S1 = init_string();
	StrAssignGet(S1);
	printf("���븳ֵ�����ַ���:");
	printSString(S1);
//---------------------------------------------
	T1= init_string();
	char T[] = "Hello,World!";
	StrAss(T1, T);
	printf("����ֵ�����ַ���:");
	printSString(T1);
	printf("\n---------------------------------------------------\n");
	
	//�пպ��󴮳�
	SString* K;
	K = init_string();
	//�жϴ��Ƿ�Ϊ��
	printf("��S�Ƿ�Ϊ��:%d\n", StrEmpty(S1));
	printf("��T�Ƿ�Ϊ��:%d\n", StrEmpty(K));
	//��ȡ���ĳ���
	printf("��S�ĳ���:%d\n", StrNum(S1));
	printf("��T�ĳ���:%d\n", StrNum(K));
	printf("\n---------------------------------------------------\n");
	
	//������
	
	SString* S2,*T2;
	S2 = init_string();
	StrAssignGet(S2);
	printf("�ַ���һ:");
	printSString(S2);
	T2 = init_string();
	StrAssignGet(T2);
	printf("�ַ�����:");
	printSString(T2);
	StrCat(S2, T2);
	printf("�ַ�������:");
	printSString(S2);

	printf("\n---------------------------------------------------\n");
	
	//���Ƚ�
	
	SString* S3, * T3;
	S3 = init_string();
	StrAssignGet(S3);
	printf("�ַ���һ:");
	printSString(S3);
	T3 = init_string();
	StrAssignGet(T3);
	printf("�ַ�����:");
	printSString(T3);
	int flag1 = StrCopmare(S3,T3);
	if (flag1==0)
	{
		printf("�ַ�����ͬ");
	}
	else if (flag1 >0)
	{
		printf("�ַ�������ͬ,���ַ���һ���ַ�������");
	}
	else if (flag1 <0)
	{
		printf("�ַ�������ͬ�����ַ���һ���ַ�������");
	}
	else
	{
		printf("�ַ�������ͬ");
	}
	
	printf("\n---------------------------------------------------\n");

	//������
	
	SString* S4, * T4;
	S4 = init_string();
	StrAssignGet(S4);
	printf("�ַ���һ:");
	printSString(S4);
	T4 = init_string();
	StrAssignGet(T4);
	printf("�ַ�����:");
	printSString(T4);
	StrInsert(S4, 2, T4);
	printf("�����ַ�����");
	printSString(S4);
	printf("\n---------------------------------------------------\n");
	//ȡ�Ӵ�
	
	SString* S5,*T5;
	T5 = init_string();
	StrAssignGet(T5);
	printf("ĸ��:");
	printSString(T5);
	S5 = init_string();
	StrGet(S5,T5,2,3);
	printf("�Ӵ�:");
	printSString(S5);
	printf("\n---------------------------------------------------\n");
	//ɾ�Ӵ�
	
	SString* S6, * T6;
	T6 = init_string();
	StrAssignGet(T6);
	printf("ĸ��:");
	printSString(T5);
	S6 = init_string();
	StrGet(S6, T6, 2, 3);
	printf("�Ӵ�:");
	printSString(S6);
	int flag = StrDel(T6,2,3);
	if (flag == 1) {
		printf("�ִ�ɾ���ɹ�����ĸ��Ϊ:");
		printSString(T6);
	}else if(flag==0){
		printf("�ִ�ɾ��ʧ��");
	}
	

	SString *S7,*T7;
	int k;
	T7 = init_string();
	StrAssignGet(T7);
	printf("�ַ���һ:");
	printSString(T7);
	S7 = init_string();
	StrGet(S7,T7,2,3);
	printf("�ַ�����:");
	printSString(S7);
	k = Index(T7, S7, 1);
	printf("��һ�γ��ֵ�λ����%d",k);
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
	printf("�´�RΪ:\n");
	printSString(R);
	printf("�´�R��ÿ���ַ��ڴ�S�е�һ�γ��ֵ�λ��Ϊ��\n");
	for (int i = 0; i < R->len; i++) {
		printf("%c:%d |", R->ch[i], r[i]);
	}
	return 0;
}
*/


//������(һά����)
/*
#define MAX_SIZE 100

typedef struct {
	int data[MAX_SIZE];//�洢������
	int n;//����Ľ���
}LowSJ;

//��ʼ������
void initLowSJ(LowSJ* L, int n) {
	L->n = n;
	int i = 0;
	for ( i = 0; i < n*(n+1)/2; i++)
	{
		L->data[i] = 0;
	}
}
//���÷���Ԫ��
void setLowSJ(LowSJ *L,int row,int col,int value) {
	if (row>=col) {
		int index = row * (row - 1) / 2 + col - 1;
		L->data[index] = value;
	}
}



//��ȡ�����ǵ�Ԫ��
int getLowSJ(LowSJ *L,int row,int col) {
	if (row >= col) {
		int index = row * (row - 1) / 2 + col - 1;
		return L->data[index];
	}else {
		return 0;
	}
}
//���
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

//ϡ�����
/*
#define MAXSIZE 100

typedef struct {
	int row, col;
	int e;
}Triple;

typedef struct {
	Triple data[MAXSIZE];
	int m, n, num;//�У��У�����Ԫ�ظ���
}TSMatrix;

//����ĵ���ת�÷�
void TransposeMatrix(TSMatrix A, TSMatrix* B) {
	int i, j, k;
	B->m = A.n;
	B->n = A.m;
	B->num = A.num;

	if (B->num>0) {
		j = 1;
		for ( k = 0; k <=A.n; k++)//ÿ��Ѱ��col = kʱ������ת�ã�����k��ȡֵ��1��= k��=A.n
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
//��������
void CreatMatrix(TSMatrix *A) {
	int i, j, k, row, col, e;
	printf("���������������������ͷ���Ԫ�ظ�����\n");
	scanf("%d%d%d", &A->m, &A->n, &A->num);
	printf("������������Ԫ�飺\n");
	for (i = 1; i <= A->num; i++) {
		scanf("%d%d%d", &row, &col, &e);
		A->data[i].row = row;
		A->data[i].col = col;
		A->data[i].e = e;
	}
}
//��ӡ����
void PrintMatrix(TSMatrix A) {
	int i, j, k = 1;
	for (i = 1; i <= A.m; i++) {//�����1��ʼ
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
	printf("ԭ����\n");
	PrintMatrix(A);
	TransposeMatrix(A, &B);
	printf("ת�þ���\n");
	PrintMatrix(B);
	return 0;
}
*/