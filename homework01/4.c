#include <stdio.h>
#include <stdlib.h>
#define datatype int

// 定义链表节点
typedef struct node {
	datatype data;
	struct node *next;
}linknode, *link;

// 函数：链表A与链表B是否相等
int equal(link A,link B) {
    link p, q;
    p = A->next;
    q = B->next;
    while (p && q) {
        if(p->data != q->data)
            break;
        p = p->next;
        q = q->next;
    }
    if (p == NULL && q == NULL)
        return 1;
    else 
        return 0;
}

void main() {
	int DATA;
	link A, B, C = NULL;
    link p, r;
	A = (link)malloc(sizeof(linknode));
	B = (link)malloc(sizeof(linknode));

	// 输入链表A
	r = A;
	printf("Input Link A:\n");
	scanf("%d", &DATA);
	while (DATA != -1) {
		p = (link)malloc(sizeof(linknode));
		p->data = DATA;
		r->next = p;
		r = p;
		scanf("%d", &DATA);
	}
	r->next = NULL;

	// 输入链表B
	r = B;
	printf("Input Link B:\n");
	scanf("%d", &DATA);
	while (DATA != -1) {
		p = (link)malloc(sizeof(linknode));
		p->data = DATA;
		r->next = p;
		r = p;
		scanf("%d", &DATA);
	}
	r->next = NULL;

    // 进行运算
    int result = equal(A, B);

    // 输出结果
    if (result)
        printf("Equal!\n");
    else 
        printf("Not Equal!\n");

    system("pause");
}