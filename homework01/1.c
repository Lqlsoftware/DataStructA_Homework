#include <stdio.h>
#include <stdlib.h>
#define datatype int

// 定义链表节点
typedef struct node {
	datatype data;
	struct node *next;
}linknode, *link;

// 函数：A减B
void LA_Sub_LB(link A, link B) {
	link p, q, r;
	p = A;
	r = A;
	q = B->next;

    // 寻找AB相同的部分(注：这里可以使用快排+遍历的方式来达到o(nlog2n)的时间复杂度)
	while (p && p->next) {
		while (q) {
            // 找到相同部分并从A中删除
			if (p->next->data == q->data) {
				r = p->next;
				p->next = r->next;
				free(r);
				break;
			}
			else {
				q = q->next;
			}
		}
		q = B->next;
		p = p->next;
	}
}

// 函数：A交B
link LA_Intersection_LB(link A, link B) {
    link C, p, q, r, s;
    p = A->next;
	q = B->next;

    // 新建链表C
    C = (link)malloc(sizeof(linknode));
    C->next = NULL;
    r = C;

    // 寻找AB相同的部分
    while (p) {
		while (q) {
            // 找到相同部分添加到C中
			if (p->data == q->data ) {
                // 检查是否以及添加
                link temp;
                temp = C->next;
                while (temp && temp->data != p->data) {
                    temp = temp->next;
                }
                if (temp != NULL) {
                    break;
                } else {
                    // 添加到C中
                    s = (link)malloc(sizeof(linknode));
                    r->next = s;
                    s->data = p->data;
                    s->next = NULL;
                    r = s;
                    break;
                }
			} else {
				q = q->next;
			}
		}
		q = B->next;
		p = p->next;
	}
    r->next = NULL;
    return C;
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
    C = LA_Intersection_LB(A, B);
 	LA_Sub_LB(A, B);

    // 输出结果
	p = A;
    printf("A:");
	while (p->next) {
		p = p->next;
        printf("%d ", p->data);
	}
    printf("\n");

    p = B;
    printf("B:");
	while (p->next) {
		p = p->next;
        printf("%d ", p->data);
	}
    printf("\n");

    if (C!=NULL) {
        p = C;
        printf("C:");
        while (p->next) {
            p = p->next;
            printf("%d ", p->data);
        }
        printf("\n");
    }

    system("pause");
}
