#include <stdio.h>
#include <stdlib.h>
#define datatype int
#define  MAXSIZE 20

// 定义栈
typedef  struct {
	datatype data[MAXSIZE];
	int top;
} sqstack, *sqslink;

// 定义链表节点
typedef struct node {
	datatype data;
	struct node *next;
}linknode, *link;

int EmptyStack(sqslink s) {
	if(s->top < 0)
		return 1;   //栈空返回1
	else
		return 0;                     //栈非空返回0
}

int Push(sqslink s, datatype x) {
	if (s->top >= MAXSIZE - 1)
		return -1;          //栈满溢出
	s->top++;
	s->data[s->top] = x;    //x进栈
	return 0;               //成功
}

int Pop(sqslink s) {
	if (EmptyStack(s))
		return -1;          //栈空，返回-1
	s->top--;
	return s->data[s->top + 1];
}

void ClearStack(sqslink s) {
	s->top = -1;
}

int GetTop(sqslink s) {
	if (EmptyStack(s))
		return -1;          //栈空，返回-1
	return s->data[s->top];
}

int GetLength(link H) {
    link p;
    p = H;
    int i = 0;
    while(p->next!=NULL) {
        i++;
        p = p->next;
    }
    return i;
}

int xyx(link H) {
    // 建立栈
    sqslink S = (sqslink)malloc(sizeof(sqstack));
    ClearStack(S);

    // 判断基数个节点还是偶数个节点
    int i = 0, length, flag;
    length = GetLength(H);
    flag = length % 2;
    
    // 遍历链表检查是否对称
    link p, q;
    p = H->next;
    while (p != NULL) {
        i++;
        if (flag == 1 && i == length/2 + 1) {
            p = p->next;
            continue;
        }
        else if (i < length/2 || GetTop(S) != p->data)
            Push(S,p->data);
        else {
            Pop(S);
        }
        p = p->next;
    }
    if (EmptyStack(S))
        return 1;
    else
        return 0;
}

void main() {
	int DATA;
	link A;
    link p, r;
	A = (link)malloc(sizeof(linknode));

	// 输入链表A
	r = A;
	printf("Input Link A:\n");
	scanf("%d", &DATA);
    // 输入-1结束输入
	while (DATA != -1) {
		p = (link)malloc(sizeof(linknode));
		p->data = DATA;
		r->next = p;
		r = p;
		scanf("%d", &DATA);
	}
	r->next = NULL;

    // 输出结果
	if (xyx(A))
        printf("It's a balance link\n");
    else
        printf("It's not a balance link\n");
    system("pause");
}