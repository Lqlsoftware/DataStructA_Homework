#include <stdio.h>
#include <stdlib.h>
#define datatype int

// 定义链表节点
typedef struct node {
    // 头节点数据为链表节点个数
	datatype data;
	struct node *next;
}linknode, *link;

// 搜索节点数据
link search(link R, link p,datatype d) {
    link q, r;
    q = p;
    for (int i = 0;i < R->data && (q == R || q->data!=d );i++) {
        q = q->next;
    }
    return q;
}

void main() {
	int DATA;
	link A = NULL;
    link p, r;
	A = (link)malloc(sizeof(linknode));
    A->data = 1;
	// 输入链表A
	r = A;
	printf("Input Link:\n");
	scanf("%d", &DATA);
	while (DATA != -1) {
		p = (link)malloc(sizeof(linknode));
		p->data = DATA;
		r->next = p;
		r = p;
        A->data++;
		scanf("%d", &DATA);
	}
	r->next = A;

    printf("Input Data:\n");
    scanf("%d", &DATA);

    // 进行运算
    r = search(A,A->next,DATA);

    // 输出结果
    printf("Result:");
    printf("%d\n", r->data);

    system("pause");
}